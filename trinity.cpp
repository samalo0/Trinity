#include "trinity.h"
#include "ui_trinity.h"
#include "RtMidi.h"
#include "midi.h"
#include <QFile>

#ifdef __DEBUG__
#include <QDebug>
#endif

#ifdef Q_OS_LINUX
// for RASPBERRY PI GPIO
#include <wiringPi.h>

// for interrupt service routines
#include "buttons.h"

#endif
//------------------------------------------------------------------------------
Trinity::Trinity(QWidget *parent):QWidget(parent),ui(new Ui::Trinity) {
    quint32 i;

    ui->setupUi(this);


    #ifdef Q_OS_LINUX
        // disable title bar
        setWindowFlags(Qt::FramelessWindowHint);

        // initialize GPIO
        wiringPiSetup();

        // set GPIO 17 (pin 0 in wiringPi) up
        pinMode(0, INPUT);
        pullUpDnControl(0, PUD_UP);

        // set GPIO 4 (pin 7) up
        pinMode(7, INPUT);
        pullUpDnControl(7, PUD_UP);

        // set GPIO 27 (pin 2) up
        pinMode(2, INPUT);
        pullUpDnControl(2, PUD_UP);

        // set GPIO 22 (pin 3) as output
        pinMode(3, OUTPUT);

        // set GPIO 23 (pin 4) as output
        pinMode(4, OUTPUT);

        // set up ISRs for inputs
        wiringPiISR(0, INT_EDGE_BOTH, &buttons_isr0, this);
        wiringPiISR(7, INT_EDGE_BOTH, &buttons_isr1, this);
        wiringPiISR(2, INT_EDGE_BOTH, &buttons_isr2, this);
    #endif

    // set up globals
    if(!loadDefaults()) {
        #ifdef __DEBUG__
            qDebug() << "file: load defaults failed";
        #endif
        de.midi_in_port_default = MIDI_NO_PORT;
        de.midi_out_port_default = MIDI_NO_PORT;
        de.midi_channel[SETLIST_PATCH_PRESET_BIGSKY] = 0;
        de.midi_channel[SETLIST_PATCH_PRESET_MOBIUS] = 1;
        de.midi_channel[SETLIST_PATCH_PRESET_TIMELINE] = 2;
    }
    if(!loadSetList()) {
        #ifdef __DEBUG__
            qDebug() << "file: load setlist failed";
        #endif
        setlist_init(&sl);
    }

    current_song = 0;
    current_patch = SETLIST_PATCH_SIZE;
    looperState = LOOPER_UNDEF;

    #ifdef Q_OS_LINUX
        CHANNEL_SWITCH1_CLR;
        CHANNEL_SWITCH2_CLR;
    #endif

    // set up song list widget
    for(i = 0; i < SETLIST_SONG_SIZE; i++) ui->listWidgetSongNames->addItem(QString::fromUtf8(sl.song_names[i]));

    // set up midi channel combo boxes
    for(i = 0; i < SETLIST_MIDI_CHANNELS; i++) {
        ui->comboBoxBigskyMidi->addItem(QString::number(i + 1));
        ui->comboBoxTimelineMidi->addItem(QString::number(i + 1));
        ui->comboBoxMobiusMidi->addItem(QString::number(i + 1));
    }

    // set combo box selection
    ui->comboBoxBigskyMidi->setCurrentIndex(de.midi_channel[SETLIST_PATCH_PRESET_BIGSKY]);
    ui->comboBoxMobiusMidi->setCurrentIndex(de.midi_channel[SETLIST_PATCH_PRESET_MOBIUS]);
    ui->comboBoxTimelineMidi->setCurrentIndex(de.midi_channel[SETLIST_PATCH_PRESET_TIMELINE]);

    // set up MIDI in
    midiin = 0;

    try {
        midiin = new RtMidiIn();
    }
    catch(RtMidiError &error) {
        error.printMessage();
        exit(EXIT_FAILURE);
    }

    if(midiin->getPortCount() == 0) midi_in_list << "No Ports Found";
    else {
        for(quint32 i = 0; i < midiin->getPortCount(); i++) {
            midi_in_list << QString::fromStdString(midiin->getPortName(i));
        }
        if(de.midi_in_port_default < midiin->getPortCount()) {
            try {
                midiin->openPort(de.midi_in_port_default);
            }
            catch(RtMidiError &error) {
                error.printMessage();
                exit(EXIT_FAILURE);
            }
            midiin->setCallback(&midi_callBack, this);
            #ifdef __DEBUG__
                qDebug() << "midi: opened input port " + QString::number(de.midi_in_port_default) + ".";
            #endif
        }
     }
    midi_in_model = new QStringListModel(this);
    midi_in_model->setStringList(midi_in_list);
    ui->comboBoxMidiInput->setModel(midi_in_model);
    if(de.midi_in_port_default != MIDI_NO_PORT) ui->comboBoxMidiInput->setCurrentIndex(de.midi_in_port_default);

    // set up MIDI out
    midiout = 0;

    try {
        midiout = new RtMidiOut();
    }
    catch(RtMidiError &error) {
        error.printMessage();
        exit(EXIT_FAILURE);
    }

    if(midiout->getPortCount() == 0) midi_out_list << "No Ports Found";
    else {
        for(quint32 i = 0; i < midiout->getPortCount(); i++) {
            midi_out_list << QString::fromStdString(midiout->getPortName(i));
        }
        if(de.midi_out_port_default < midiout->getPortCount()) {
            try {
                midiout->openPort(de.midi_out_port_default);
            }
            catch(RtMidiError &error) {
                error.printMessage();
                exit(EXIT_FAILURE);
            }
            #ifdef __DEBUG__
                qDebug() << "midi: opened output port " + QString::number(de.midi_out_port_default) + ".";
            #endif
        }
    }
    midi_out_model = new QStringListModel(this);
    midi_out_model->setStringList(midi_out_list);
    ui->comboBoxMidiOutput->setModel(midi_out_model);
    if(de.midi_out_port_default != MIDI_NO_PORT) ui->comboBoxMidiOutput->setCurrentIndex(de.midi_out_port_default);

    ui->labelSetupMessage->setText("Found " + QString::number(midiin->getPortCount()) + " in, " + QString::number(midiout->getPortCount()) + " out ports.");

    // update tabs
    updatePerformanceTab();
    updateEditTab();
}
//------------------------------------------------------------------------------
Trinity::~Trinity() {
    delete midi_in_model;
    delete midi_out_model;
    delete midiin;
    delete midiout;
    delete ui;
}
//------------------------------------------------------------------------------
void Trinity::updatePerformanceTab() {
    QString temp;

    ui->labelSongName->setText(QString::number(current_song + 1) + ". " + QString::fromUtf8(sl.song_names[current_song]));
    temp = sl.setlist_songs[current_song][0].patch_name;
    ui->pushButtonA->setText("A\n" + temp);
    temp = sl.setlist_songs[current_song][1].patch_name;
    ui->pushButtonB->setText("B\n" + temp);
    temp = sl.setlist_songs[current_song][2].patch_name;
    ui->pushButtonC->setText("C\n" + temp);

    if(current_patch < SETLIST_PATCH_SIZE) {
        ui->lineEditBigsky->setText(setlist_patch_preset_string(sl.setlist_songs[current_song][current_patch].patch_presets[SETLIST_PATCH_PRESET_BIGSKY], SETLIST_PATCH_PRESET_BIGSKY));
        ui->lineEditMobius->setText(setlist_patch_preset_string(sl.setlist_songs[current_song][current_patch].patch_presets[SETLIST_PATCH_PRESET_MOBIUS], SETLIST_PATCH_PRESET_MOBIUS));
        ui->lineEditTimeline->setText(setlist_patch_preset_string(sl.setlist_songs[current_song][current_patch].patch_presets[SETLIST_PATCH_PRESET_TIMELINE], SETLIST_PATCH_PRESET_TIMELINE));
    }
    else {
        ui->lineEditBigsky->setText("BYP");
        ui->lineEditMobius->setText("BYP");
        ui->lineEditTimeline->setText("BYP");
    }

    ui->pushButtonPrevSong->setEnabled(current_song > 0);
    ui->pushButtonNextSong->setEnabled(current_song < (SETLIST_SONG_SIZE - 1));
    ui->pushButtonDetect->setEnabled(current_patch != SETLIST_PATCH_PRESET_SIZE);
}
//------------------------------------------------------------------------------
void Trinity::updateEditTab() {
    ui->listWidgetSongNames->setCurrentRow(current_song);
    ui->lineEditSongName->setText(sl.song_names[current_song]);

    ui->lineEditP1Name->setText(sl.setlist_songs[current_song][0].patch_name);
    ui->lineEditP2Name->setText(sl.setlist_songs[current_song][1].patch_name);
    ui->lineEditP3Name->setText(sl.setlist_songs[current_song][2].patch_name);

    ui->checkBoxP1Sw1->setChecked(sl.setlist_songs[current_song][0].patch_switches[0]);
    ui->checkBoxP1Sw2->setChecked(sl.setlist_songs[current_song][0].patch_switches[1]);
    ui->checkBoxP2Sw1->setChecked(sl.setlist_songs[current_song][1].patch_switches[0]);
    ui->checkBoxP2Sw2->setChecked(sl.setlist_songs[current_song][1].patch_switches[1]);
    ui->checkBoxP3Sw1->setChecked(sl.setlist_songs[current_song][2].patch_switches[0]);
    ui->checkBoxP3Sw2->setChecked(sl.setlist_songs[current_song][2].patch_switches[1]);

    ui->lineEditP1Bs->setText(setlist_patch_preset_string(sl.setlist_songs[current_song][0].patch_presets[SETLIST_PATCH_PRESET_BIGSKY], SETLIST_PATCH_PRESET_BIGSKY));
    ui->lineEditP2Bs->setText(setlist_patch_preset_string(sl.setlist_songs[current_song][1].patch_presets[SETLIST_PATCH_PRESET_BIGSKY], SETLIST_PATCH_PRESET_BIGSKY));
    ui->lineEditP3Bs->setText(setlist_patch_preset_string(sl.setlist_songs[current_song][2].patch_presets[SETLIST_PATCH_PRESET_BIGSKY], SETLIST_PATCH_PRESET_BIGSKY));

    ui->lineEditP1Mo->setText(setlist_patch_preset_string(sl.setlist_songs[current_song][0].patch_presets[SETLIST_PATCH_PRESET_MOBIUS], SETLIST_PATCH_PRESET_MOBIUS));
    ui->lineEditP2Mo->setText(setlist_patch_preset_string(sl.setlist_songs[current_song][1].patch_presets[SETLIST_PATCH_PRESET_MOBIUS], SETLIST_PATCH_PRESET_MOBIUS));
    ui->lineEditP3Mo->setText(setlist_patch_preset_string(sl.setlist_songs[current_song][2].patch_presets[SETLIST_PATCH_PRESET_MOBIUS], SETLIST_PATCH_PRESET_MOBIUS));

    ui->lineEditP1Tl->setText(setlist_patch_preset_string(sl.setlist_songs[current_song][0].patch_presets[SETLIST_PATCH_PRESET_TIMELINE], SETLIST_PATCH_PRESET_TIMELINE));
    ui->lineEditP2Tl->setText(setlist_patch_preset_string(sl.setlist_songs[current_song][1].patch_presets[SETLIST_PATCH_PRESET_TIMELINE], SETLIST_PATCH_PRESET_TIMELINE));
    ui->lineEditP3Tl->setText(setlist_patch_preset_string(sl.setlist_songs[current_song][2].patch_presets[SETLIST_PATCH_PRESET_TIMELINE], SETLIST_PATCH_PRESET_TIMELINE));

    ui->pushButtonMoveUp->setEnabled(current_song != 0);
    ui->pushButtonMoveDown->setEnabled(current_song != (SETLIST_SONG_SIZE - 1));
}
//------------------------------------------------------------------------------
void Trinity::on_pushButtonPrevSong_clicked() {
    if(current_song > 0) current_song--;

    ui->pushButtonA->setChecked(false);
    ui->pushButtonB->setChecked(false);
    ui->pushButtonC->setChecked(false);
    ui->pushButtonDetect->setChecked(false);

    current_patch = SETLIST_PATCH_SIZE;

    updatePerformanceTab();
    updateEditTab();
}
//------------------------------------------------------------------------------
void Trinity::on_pushButtonNextSong_clicked() {
    if(current_song < (SETLIST_SONG_SIZE - 1)) current_song++;

    ui->pushButtonA->setChecked(false);
    ui->pushButtonB->setChecked(false);
    ui->pushButtonC->setChecked(false);
    ui->pushButtonDetect->setChecked(false);

    current_patch = SETLIST_PATCH_SIZE;

    updatePerformanceTab();
    updateEditTab();
}
//------------------------------------------------------------------------------
void Trinity::on_pushButtonA_clicked() {
    if(ui->pushButtonA->isChecked()) {
        // uncheck other buttons
        ui->pushButtonB->setChecked(false);
        ui->pushButtonC->setChecked(false);

        // set patch
        current_patch = 0;
        patchChange(sl.setlist_songs[current_song][current_patch].patch_presets);

        // set channels
        switchChange(sl.setlist_songs[current_song][current_patch].patch_switches);

        // update display
        updatePerformanceTab();
    }
}
//------------------------------------------------------------------------------
void Trinity::on_pushButtonB_clicked() {
    if(ui->pushButtonB->isChecked()) {
        // uncheck other buttons
        ui->pushButtonA->setChecked(false);
        ui->pushButtonC->setChecked(false);

        // set patch
        current_patch = 1;
        patchChange(sl.setlist_songs[current_song][current_patch].patch_presets);

        // set channels
        switchChange(sl.setlist_songs[current_song][current_patch].patch_switches);

        // update display
        updatePerformanceTab();
    }
}
//------------------------------------------------------------------------------
void Trinity::on_pushButtonC_clicked() {
    if(ui->pushButtonC->isChecked()) {
        // uncheck other buttons
        ui->pushButtonA->setChecked(false);
        ui->pushButtonB->setChecked(false);

        // set patch
        current_patch = 2;
        patchChange(sl.setlist_songs[current_song][current_patch].patch_presets);

        // set channels
        switchChange(sl.setlist_songs[current_song][current_patch].patch_switches);

        // update display
        updatePerformanceTab();
    }
}
//------------------------------------------------------------------------------
void Trinity::on_checkBoxP1Sw1_clicked() {
    sl.setlist_songs[current_song][0].patch_switches[0] = ui->checkBoxP1Sw1->isChecked();
}

void Trinity::on_checkBoxP1Sw2_clicked() {
    sl.setlist_songs[current_song][0].patch_switches[1] = ui->checkBoxP1Sw2->isChecked();
}

void Trinity::on_checkBoxP2Sw1_clicked() {
    sl.setlist_songs[current_song][1].patch_switches[0] = ui->checkBoxP2Sw1->isChecked();
}

void Trinity::on_checkBoxP2Sw2_clicked() {
    sl.setlist_songs[current_song][1].patch_switches[1] = ui->checkBoxP2Sw2->isChecked();
}

void Trinity::on_checkBoxP3Sw1_clicked(){
    sl.setlist_songs[current_song][2].patch_switches[0] = ui->checkBoxP3Sw1->isChecked();
}

void Trinity::on_checkBoxP3Sw2_clicked(){
    sl.setlist_songs[current_song][2].patch_switches[1] = ui->checkBoxP3Sw2->isChecked();
}

void Trinity::on_lineEditP1Name_editingFinished(){
    setlist_qstring_to_char(ui->lineEditP1Name->text(), sl.setlist_songs[current_song][0].patch_name);
}

void Trinity::on_lineEditP2Name_editingFinished(){
    setlist_qstring_to_char(ui->lineEditP2Name->text(), sl.setlist_songs[current_song][1].patch_name);
}

void Trinity::on_lineEditP3Name_editingFinished(){
    setlist_qstring_to_char(ui->lineEditP3Name->text(), sl.setlist_songs[current_song][2].patch_name);
}

void Trinity::on_pushButtonCopy_clicked() {
    qint32 index;

    for(index = 0; index < SETLIST_PATCH_SIZE; index++) copy_buffer[index] = sl.setlist_songs[current_song][index];
    for(index = 0; index < SETLIST_NAME_SIZE; index++) copy_buffer_name[index] = sl.song_names[current_song][index];
    ui->pushButtonPaste->setEnabled(true);
}

void Trinity::on_pushButtonPaste_clicked() {
    qint32 index;

    // update list widget
    index = current_song;

    // this will cause current song to be updated
    delete ui->listWidgetSongNames->item(index);
    ui->listWidgetSongNames->insertItem(index, QString::fromUtf8(copy_buffer_name));

    // set it back
    current_song = index;

    for(index = 0; index < SETLIST_PATCH_SIZE; index++) sl.setlist_songs[current_song][index] = copy_buffer[index];
    for(index = 0; index < SETLIST_NAME_SIZE; index++) sl.song_names[current_song][index] = copy_buffer_name[index];
    updatePerformanceTab();
    updateEditTab();
}

void Trinity::on_pushButtonMoveUp_clicked() {
    qint32 index;

    // update list widget
    index = current_song;

    // this will cause current song to be updated
    delete ui->listWidgetSongNames->item(index - 1);
    ui->listWidgetSongNames->insertItem(index, QString::fromUtf8(sl.song_names[index - 1]));

    // set it back
    current_song = index;

    // save song above into move buffer
    for(index = 0; index < SETLIST_PATCH_SIZE; index++) move_buffer[index] = sl.setlist_songs[current_song - 1][index];
    for(index = 0; index < SETLIST_NAME_SIZE; index++) move_buffer_name[index] = sl.song_names[current_song - 1][index];

    // replace song above with current song
    for(index = 0; index < SETLIST_PATCH_SIZE; index++) sl.setlist_songs[current_song - 1][index] = sl.setlist_songs[current_song][index];
    for(index = 0; index < SETLIST_NAME_SIZE; index++) sl.song_names[current_song - 1][index] = sl.song_names[current_song][index];

    // replace current song with buffer
    for(index = 0; index < SETLIST_PATCH_SIZE; index++) sl.setlist_songs[current_song][index] = move_buffer[index];
    for(index = 0; index < SETLIST_NAME_SIZE; index++) sl.song_names[current_song][index] = move_buffer_name[index];

    current_song--;

    updatePerformanceTab();
    updateEditTab();
}

void Trinity::on_pushButtonMoveDown_clicked() {
    qint32 index;

    // update list widget
    index = current_song;

    // this will cause current song to be updated
    delete ui->listWidgetSongNames->item(index + 1);
    ui->listWidgetSongNames->insertItem(index, QString::fromUtf8(sl.song_names[index + 1]));

    // set it back
    current_song = index;

    // save song below into move buffer
    for(index = 0; index < SETLIST_PATCH_SIZE; index++) move_buffer[index] = sl.setlist_songs[current_song + 1][index];
    for(index = 0; index < SETLIST_NAME_SIZE; index++) move_buffer_name[index] = sl.song_names[current_song + 1][index];

    // replace song below with current song
    for(index = 0; index < SETLIST_PATCH_SIZE; index++) sl.setlist_songs[current_song + 1][index] = sl.setlist_songs[current_song][index];
    for(index = 0; index < SETLIST_NAME_SIZE; index++) sl.song_names[current_song + 1][index] = sl.song_names[current_song][index];

    // replace current song with buffer
    for(index = 0; index < SETLIST_PATCH_SIZE; index++) sl.setlist_songs[current_song][index] = move_buffer[index];
    for(index = 0; index < SETLIST_NAME_SIZE; index++) sl.song_names[current_song][index] = move_buffer_name[index];

    current_song++;

    updatePerformanceTab();
    updateEditTab();
}

void Trinity::on_lineEditP1Bs_editingFinished() {
    sl.setlist_songs[current_song][0].patch_presets[SETLIST_PATCH_PRESET_BIGSKY] = setlist_patch_from_string(ui->lineEditP1Bs->text(), SETLIST_PATCH_PRESET_BIGSKY);
    updateEditTab();
}

void Trinity::on_lineEditP2Bs_editingFinished() {
    sl.setlist_songs[current_song][1].patch_presets[SETLIST_PATCH_PRESET_BIGSKY] = setlist_patch_from_string(ui->lineEditP2Bs->text(), SETLIST_PATCH_PRESET_BIGSKY);
    updateEditTab();
}

void Trinity::on_lineEditP3Bs_editingFinished() {
    sl.setlist_songs[current_song][2].patch_presets[SETLIST_PATCH_PRESET_BIGSKY] = setlist_patch_from_string(ui->lineEditP3Bs->text(), SETLIST_PATCH_PRESET_BIGSKY);
    updateEditTab();
}

void Trinity::on_lineEditP1Mo_editingFinished() {
    sl.setlist_songs[current_song][0].patch_presets[SETLIST_PATCH_PRESET_MOBIUS] = setlist_patch_from_string(ui->lineEditP1Mo->text(), SETLIST_PATCH_PRESET_MOBIUS);
    updateEditTab();
}

void Trinity::on_lineEditP2Mo_editingFinished() {
    sl.setlist_songs[current_song][1].patch_presets[SETLIST_PATCH_PRESET_MOBIUS] = setlist_patch_from_string(ui->lineEditP2Mo->text(), SETLIST_PATCH_PRESET_MOBIUS);
    updateEditTab();
}

void Trinity::on_lineEditP3Mo_editingFinished() {
    sl.setlist_songs[current_song][2].patch_presets[SETLIST_PATCH_PRESET_MOBIUS] = setlist_patch_from_string(ui->lineEditP3Mo->text(), SETLIST_PATCH_PRESET_MOBIUS);
    updateEditTab();
}

void Trinity::on_lineEditP1Tl_editingFinished() {
    sl.setlist_songs[current_song][0].patch_presets[SETLIST_PATCH_PRESET_TIMELINE] = setlist_patch_from_string(ui->lineEditP1Tl->text(), SETLIST_PATCH_PRESET_TIMELINE);
    updateEditTab();
}

void Trinity::on_lineEditP2Tl_editingFinished() {
    sl.setlist_songs[current_song][1].patch_presets[SETLIST_PATCH_PRESET_TIMELINE] = setlist_patch_from_string(ui->lineEditP2Tl->text(), SETLIST_PATCH_PRESET_TIMELINE);
    updateEditTab();
}

void Trinity::on_lineEditP3Tl_editingFinished() {
    sl.setlist_songs[current_song][2].patch_presets[SETLIST_PATCH_PRESET_TIMELINE] = setlist_patch_from_string(ui->lineEditP3Tl->text(), SETLIST_PATCH_PRESET_TIMELINE);
    updateEditTab();
}

void Trinity::on_pushButtonDetect_clicked() {
    qint32 index;

    if(ui->pushButtonDetect->isChecked()) {
        // reset patch selections - wait for received
        for(index = 0; index < SETLIST_PATCH_PRESET_SIZE; index++)
        sl.setlist_songs[current_song][current_patch].patch_presets[index] = SETLIST_PATCH_BYPASS;
        updatePerformanceTab();
    }
}

void Trinity::on_pushButtonSave_clicked() {
    // save data to file
    #ifdef Q_OS_LINUX
        QFile file("/home/pi/Trinity/setlist.dat");
    #else
        QFile file("setlist.dat");
    #endif
    if(file.open(QIODevice::WriteOnly)) {
        if(file.write((char *)&sl, sizeof(sl)) == sizeof(sl)) ui->labelSetupMessage->setText("File saved.");
        else ui->labelSetupMessage->setText("Error saving file.");
        file.close();
    }
    else ui->labelSetupMessage->setText("Error opening file.");
}

void Trinity::on_pushButtonLoad_clicked() {
    // read data from file
    if(loadSetList()) {
        ui->labelSetupMessage->setText("File loaded.");

        // update listWidget
        for(qint32 index = 0; index < SETLIST_SONG_SIZE; index++) {
            delete ui->listWidgetSongNames->item(index);
            ui->listWidgetSongNames->insertItem(index, QString::fromUtf8(sl.song_names[index]));
        }
        current_song = 0;
        updatePerformanceTab();
        updateEditTab();
    }
    else ui->labelSetupMessage->setText("Error loading file.");
}
//------------------------------------------------------------------------------
void Trinity::on_comboBoxMidiInput_activated(int index) {
    if(midiin->getPortCount() > 0) {
        if(midiin->isPortOpen()) {
            midiin->closePort();
            midiin->cancelCallback();
            #ifdef __DEBUG__
                qDebug() << "midi: closed input port.";
            #endif
        }
        try {
            midiin->openPort(index);
        }
        catch(RtMidiError &error) {
            error.printMessage();
            exit(EXIT_FAILURE);
        }
        midiin->setCallback(&midi_callBack, this);
        #ifdef __DEBUG__
            qDebug() << "midi: opened input port " + QString::number(index) + ".";
        #endif

        de.midi_in_port_default = index;
        ui->labelSetupMessage->setText("Midi in port " + QString::number(index) + " opened.");
        saveDefaults();
    }
    else {
        ui->labelSetupMessage->setText("No MIDI in port to select.");
    }
}
//------------------------------------------------------------------------------
void Trinity::on_comboBoxMidiOutput_activated(int index) {
    if(midiout->getPortCount() > 0) {
        if(midiout->isPortOpen()) {
            midiout->closePort();
            #ifdef __DEBUG__
                qDebug() << "midi: closed output port.";
            #endif
        }
        midiout->openPort(index);
        #ifdef __DEBUG__
            qDebug() << "midi: opened output port " + QString::number(index) + ".";
        #endif
        de.midi_out_port_default = index;
        ui->labelSetupMessage->setText("Midi out port " + QString::number(index) + " opened.");
        saveDefaults();
    }
    else {
        ui->labelSetupMessage->setText("No MIDI out port to select.");
    }
}
//------------------------------------------------------------------------------
void Trinity::on_lineEditSongName_editingFinished(){
    qint8 csg;

    // backup current song
    csg = current_song;

    setlist_qstring_to_char(ui->lineEditSongName->text(), sl.song_names[csg]);

    // this will cause current song to be updated
    delete ui->listWidgetSongNames->item(csg);
    ui->listWidgetSongNames->insertItem(csg, QString::fromUtf8(sl.song_names[csg]));

    // set it back
    current_song = csg;
    updatePerformanceTab();
    updateEditTab();
}

void Trinity::on_listWidgetSongNames_currentRowChanged(int currentRow) {
    current_song = currentRow;
    updatePerformanceTab();
    updateEditTab();
}

void Trinity::on_comboBoxBigskyMidi_activated(int index) {
    de.midi_channel[SETLIST_PATCH_PRESET_BIGSKY] = index;
    saveDefaults();
}

void Trinity::on_comboBoxMobiusMidi_activated(int index) {
    de.midi_channel[SETLIST_PATCH_PRESET_MOBIUS] = index;
    saveDefaults();
}

void Trinity::on_comboBoxTimelineMidi_activated(int index) {
    de.midi_channel[SETLIST_PATCH_PRESET_TIMELINE] = index;
    saveDefaults();
}
//------------------------------------------------------------------------------
// Trinity::patchChange
//------------------------------------------------------------------------------
void Trinity::patchChange(quint16 *patch_presets) {
    std::vector<unsigned char> message;
    quint32 index;
    quint16 relpatch;

    for(index = 0; index < SETLIST_PATCH_PRESET_SIZE; index++) {
        message.clear();
        if(patch_presets[index] == SETLIST_PATCH_BYPASS) {
            // bypass the pedal
            message.push_back(MIDI_CONTROL_CHANGE | de.midi_channel[index]);
            message.push_back(MIDI_CC_BYPASS);
            message.push_back(0);
            midiout->sendMessage(&message);
        }
        else {
            // switch patch bank
            message.push_back(MIDI_CONTROL_CHANGE | de.midi_channel[index]);
            message.push_back(MIDI_CC_PATCH_BANK);
            if(patch_presets[index] < 128) {
                message.push_back(0);
                relpatch = patch_presets[index];
            }
            else if(patch_presets[index] < 255) {
                message.push_back(1);
                relpatch = patch_presets[index] - 128;
            }
            else {
                message.push_back(2);
                relpatch = patch_presets[index] - 256;
            }
            midiout->sendMessage(&message);

            // switch program
            message.clear();
            message.push_back(MIDI_PROGRAM_CHANGE | de.midi_channel[index]);
            message.push_back(relpatch);
            midiout->sendMessage(&message);

            // engage
            message.clear();
            message.push_back(MIDI_CONTROL_CHANGE | de.midi_channel[index]);
            message.push_back(MIDI_CC_BYPASS);
            message.push_back(127);
            midiout->sendMessage(&message);
        }
    }
}
//------------------------------------------------------------------------------
void Trinity::on_pushButtonLoopRec_pressed() {
    std::vector<unsigned char> message;

    message.push_back(MIDI_CONTROL_CHANGE | de.midi_channel[SETLIST_PATCH_PRESET_TIMELINE]);
    message.push_back(MIDI_CC_RECORD);
    message.push_back(0);
    midiout->sendMessage(&message);

    if(looperState == LOOPER_PLAYING) ui->labelLooperStatus->setText("Overdubbing...");
    else ui->labelLooperStatus->setText("Recording...");
}
//------------------------------------------------------------------------------
void Trinity::on_pushButtonLoopRec_released() {
    std::vector<unsigned char> message;

    if(looperState == LOOPER_PLAYING) {
        message.push_back(MIDI_CONTROL_CHANGE | de.midi_channel[SETLIST_PATCH_PRESET_TIMELINE]);
        message.push_back(MIDI_CC_RECORD);
        message.push_back(0);
    }
    else {
        message.push_back(MIDI_CONTROL_CHANGE | de.midi_channel[SETLIST_PATCH_PRESET_TIMELINE]);
        message.push_back(MIDI_CC_PLAY);
        message.push_back(0);

        // set flag for loop in memory of pedal
        looperState = LOOPER_PLAYING;

        ui->pushButtonLoopRec->setText("A\nOVRDUB");
        ui->pushButtonLoopStop->setText("C\nSTOP");
    }
    midiout->sendMessage(&message);

    ui->labelLooperStatus->setText("Playing...");
}
//------------------------------------------------------------------------------
void Trinity::on_pushButtonLoopUndo_clicked() {
    std::vector<unsigned char> message;

    if(looperState == LOOPER_PLAYING) {
        message.push_back(MIDI_CONTROL_CHANGE | de.midi_channel[SETLIST_PATCH_PRESET_TIMELINE]);
        message.push_back(MIDI_CC_UNDO);
        message.push_back(0);
        midiout->sendMessage(&message);

        ui->labelLooperStatus->setText("Undo sent...");
    }
}
//------------------------------------------------------------------------------
void Trinity::on_pushButtonLoopStop_clicked() {
    std::vector<unsigned char> message;

    if(looperState == LOOPER_PLAYING) {
        message.push_back(MIDI_CONTROL_CHANGE | de.midi_channel[SETLIST_PATCH_PRESET_TIMELINE]);
        message.push_back(MIDI_CC_STOP);
        message.push_back(0);
        midiout->sendMessage(&message);

        ui->labelLooperStatus->setText("Stopped.");

        looperState = LOOPER_STOPPED;

        ui->pushButtonLoopRec->setText("A\nREC");
        ui->pushButtonLoopStop->setText("C\nPLAY");
    }
    else if(looperState == LOOPER_STOPPED){
        message.push_back(MIDI_CONTROL_CHANGE | de.midi_channel[SETLIST_PATCH_PRESET_TIMELINE]);
        message.push_back(MIDI_CC_PLAY);
        message.push_back(0);
        midiout->sendMessage(&message);

        ui->labelLooperStatus->setText("Playing...");
        looperState = LOOPER_PLAYING;

        ui->pushButtonLoopRec->setText("A\nOVRDUB");
        ui->pushButtonLoopStop->setText("C\nSTOP");
    }
}
//------------------------------------------------------------------------------
bool Trinity::detectMode() {
    return ui->pushButtonDetect->isChecked();
}
//------------------------------------------------------------------------------
quint8 Trinity::midiChannel(quint8 channel) {
    return de.midi_channel[channel];
}
//------------------------------------------------------------------------------
void Trinity::setPatch(quint16 patch, quint32 index) {
    sl.setlist_songs[current_song][current_patch].patch_presets[index] = patch;
}
//------------------------------------------------------------------------------
bool Trinity::loadSetList() {
    // read data from file
    #ifdef Q_OS_LINUX
        QFile file("/home/pi/Trinity/setlist.dat");
    #else
        QFile file("setlist.dat");
    #endif
    if(file.open(QIODevice::ReadOnly)) {
        if(file.read((char *)&sl, sizeof(sl)) == sizeof(sl)) {
            file.close();
            return true;
        }
        file.close();
    }
    return false;
}
//------------------------------------------------------------------------------
bool Trinity::loadDefaults() {
    // read data from file
    #ifdef Q_OS_LINUX
        QFile file("/home/pi/Trinity/defaults.dat");
    #else
        QFile file("defaults.dat");
    #endif
    if(file.open(QIODevice::ReadOnly)) {
        if(file.read((char *)&de, sizeof(defaults)) == sizeof(defaults)) {
            file.close();
            return true;
        }
        file.close();
    }
    return false;
}
//------------------------------------------------------------------------------
bool Trinity::saveDefaults() {
    // save data to file
    #ifdef Q_OS_LINUX
        QFile file("/home/pi/Trinity/defaults.dat");
    #else
        QFile file("defaults.dat");
    #endif
    if(file.open(QIODevice::WriteOnly)) {
        if(file.write((char *)&de, sizeof(defaults)) == sizeof(defaults)) {
            file.close();
            return true;
        }
        file.close();
    }
    return false;
}
//------------------------------------------------------------------------------
void Trinity::switchPushed(quint8 switch_num) {
    // figure out which tab is active
    if(ui->tabLooper->isVisible()) {
        switch(switch_num) {
        case 0:
            this->on_pushButtonLoopRec_pressed();
            break;
        case 1:
            ui->pushButtonLoopUndo->click();
            break;
        case 2:
            ui->pushButtonLoopStop->click();
            break;
        }
    }
    else if(ui->tabSetup->isVisible()) {
        switch(switch_num) {
        case 0:
            ui->pushButtonSave->click();
            break;
        case 1:
            ui->pushButtonLoad->click();
            break;
        case 2:
            ui->pushButtonPower->click();
            break;
        }
    }
}
//------------------------------------------------------------------------------
void Trinity::switchReleased(quint8 switch_num) {
    static bool block_middle = false;

    // figure out which tab is active
    if(ui->tabLooper->isVisible()) {
        switch(switch_num) {
        case 0:
            this->on_pushButtonLoopRec_released();
            break;
        }
    }
    else if(ui->tabPerformance->isVisible()) {
        switch(switch_num) {
        case 0:
            #ifdef Q_OS_LINUX
                if(BUTTONS_B_READ == LOW) {
                    ui->pushButtonPrevSong->click();
                    block_middle = true;
                }
                else {
                    ui->pushButtonA->setChecked(false);
                    ui->pushButtonA->click();
                }
            #endif
            break;
        case 1:
            if(!block_middle) {
                ui->pushButtonB->setChecked(false);
                ui->pushButtonB->click();
            }
            block_middle = false;
            break;
        case 2:
            #ifdef Q_OS_LINUX
                if(BUTTONS_B_READ == LOW) {
                    ui->pushButtonNextSong->click();
                    block_middle = true;
                }
                else {
                    ui->pushButtonC->setChecked(false);
                    ui->pushButtonC->click();
                }
            #endif
            break;
        }
    }
}
//------------------------------------------------------------------------------
void Trinity::switchChange(quint8 *patch_switches) {
    ui->pushButtonLoopSw1->setChecked(patch_switches[0]);
    ui->pushButtonLoopSw2->setChecked(patch_switches[1]);

    #ifdef Q_OS_LINUX
        if(patch_switches[0]) CHANNEL_SWITCH1_SET;
        else CHANNEL_SWITCH1_CLR;

        if(patch_switches[1]) CHANNEL_SWITCH2_SET;
        else CHANNEL_SWITCH2_CLR;
    #endif
}
//------------------------------------------------------------------------------
void Trinity::on_pushButtonLoopSw1_clicked() {
    #ifdef Q_OS_LINUX
        if(ui->pushButtonLoopSw1->isChecked()) CHANNEL_SWITCH1_SET;
        else CHANNEL_SWITCH1_CLR;
    #endif
}
//------------------------------------------------------------------------------
void Trinity::on_pushButtonLoopSw2_clicked() {
    #ifdef Q_OS_LINUX
        if(ui->pushButtonLoopSw2->isChecked()) CHANNEL_SWITCH2_SET;
        else CHANNEL_SWITCH2_CLR;
    #endif
}
//------------------------------------------------------------------------------
void Trinity::on_pushButtonPower_clicked() {
    #ifdef Q_OS_LINUX
        system("sudo poweroff");
    #else
        exit(EXIT_SUCCESS);
    #endif
}
//------------------------------------------------------------------------------
