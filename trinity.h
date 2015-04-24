#ifndef TRINITY_H
#define TRINITY_H

#include <QWidget>
#include <QStringListModel>
#include <QListWidget>
#include "RtMidi.h"
#include "setlist.h"

// gpio relay drive for channel switching
#define CHANNEL_SWITCH1_SET digitalWrite(3, LOW)
#define CHANNEL_SWITCH1_CLR digitalWrite(3, HIGH)
#define CHANNEL_SWITCH2_SET digitalWrite(4, LOW)
#define CHANNEL_SWITCH2_CLR digitalWrite(4, HIGH)

typedef struct {
    quint8 midi_channel[SETLIST_PATCH_PRESET_SIZE];
    quint8 midi_in_port_default;
    quint8 midi_out_port_default;
} defaults;

namespace Ui {
class Trinity;
}

class Trinity : public QWidget
{
    Q_OBJECT

public:
    explicit Trinity(QWidget *parent = 0);
    ~Trinity();

    bool detectMode();
    quint8 midiChannel(quint8 channel);
    void setPatch(quint16 patch, quint32 index);
    void updatePerformanceTab();
    void switchPushed(quint8 switch_num);
    void switchReleased(quint8 switch_num);

private slots:
    void on_pushButtonPrevSong_clicked();
    void on_pushButtonNextSong_clicked();
    void on_pushButtonA_clicked();
    void on_pushButtonB_clicked();
    void on_pushButtonC_clicked();
    void on_checkBoxP1Sw1_clicked();
    void on_checkBoxP1Sw2_clicked();
    void on_checkBoxP2Sw1_clicked();
    void on_checkBoxP2Sw2_clicked();
    void on_checkBoxP3Sw1_clicked();
    void on_checkBoxP3Sw2_clicked();
    void on_pushButtonCopy_clicked();
    void on_pushButtonPaste_clicked();
    void on_pushButtonMoveUp_clicked();
    void on_pushButtonMoveDown_clicked();
    void on_lineEditP1Bs_editingFinished();
    void on_lineEditP2Bs_editingFinished();
    void on_lineEditP3Bs_editingFinished();
    void on_lineEditP1Mo_editingFinished();
    void on_lineEditP2Mo_editingFinished();
    void on_lineEditP3Mo_editingFinished();
    void on_lineEditP1Tl_editingFinished();
    void on_lineEditP2Tl_editingFinished();
    void on_lineEditP3Tl_editingFinished();
    void on_pushButtonDetect_clicked();
    void on_pushButtonSave_clicked();
    void on_pushButtonLoad_clicked();
    void on_lineEditP1Name_editingFinished();
    void on_lineEditP2Name_editingFinished();
    void on_lineEditP3Name_editingFinished();
    void on_lineEditSongName_editingFinished();
    void on_listWidgetSongNames_currentRowChanged(int currentRow);
    void on_comboBoxMidiInput_activated(int index);
    void on_comboBoxMidiOutput_activated(int index);
    void on_comboBoxBigskyMidi_activated(int index);
    void on_comboBoxMobiusMidi_activated(int index);
    void on_comboBoxTimelineMidi_activated(int index);
    void on_pushButtonLoopUndo_clicked();
    void on_pushButtonLoopStop_clicked();
    void on_pushButtonLoopRec_released();
    void on_pushButtonLoopRec_pressed();
    void on_pushButtonLoopSw1_clicked();
    void on_pushButtonLoopSw2_clicked();

    void on_pushButtonPower_clicked();

private:
    Ui::Trinity *ui;

    // backup variables
    setlist sl;
    defaults de;

    // temporary variables
    quint8 current_song;
    quint8 current_patch;
    patch_data copy_buffer[SETLIST_PATCH_SIZE];
    char copy_buffer_name[SETLIST_NAME_SIZE];
    patch_data move_buffer[SETLIST_PATCH_SIZE];
    char move_buffer_name[SETLIST_NAME_SIZE];
    QStringList midi_in_list;
    QStringList midi_out_list;
    QStringListModel *midi_in_model;
    QStringListModel *midi_out_model;
    RtMidiIn *midiin;
    RtMidiOut *midiout;
    enum {
        LOOPER_UNDEF = 0,
        LOOPER_STOPPED,
        LOOPER_PLAYING
    } looperState;
    bool channel_switch_status[2];

    void patchChange(quint16 *patch_presets);
    void switchChange(quint8 *patch_switches);
    void updateEditTab();
    bool loadSetList();
    bool loadDefaults();
    bool saveDefaults();
};

#endif // TRINITY_H
