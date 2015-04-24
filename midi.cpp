#include "midi.h"
#include "setlist.h"
#include "trinity.h"

#ifdef __DEBUG__
    #include <QDebug>
#endif

//------------------------------------------------------------------------------
// midi_callBack
//------------------------------------------------------------------------------
void midi_callBack(double deltatime, std::vector<unsigned char> *message, void *userData) {
    quint8 mchan;
    quint8 mcomm;
    quint32 index;
    Trinity *trp = (Trinity *)userData;
    static quint8 midi_bank[SETLIST_PATCH_PRESET_SIZE];

    #ifdef __DEBUG__
        QString temp;
        temp.append("midi: input ");
        for(index = 0; index < message->size(); index++) temp.append(QString::number(message->at(index)) + " ");
        qDebug() << temp;
    #endif

    if(message->size() < 2) return;

    mchan = message->at(0) & 0xF;
    mcomm = message->at(0) & 0xF0;

    // check message type
    switch(mcomm) {
    case MIDI_CONTROL_CHANGE:
        if(message->at(1) == MIDI_CC_PATCH_BANK) {
            // a pedal changed patch bank
            for(index = 0; index < SETLIST_PATCH_PRESET_SIZE; index++) {
                if(trp->midiChannel(index) == mchan) {
                    midi_bank[index] = message->at(2);
                    break;
                }
            }
        }
        break;
    case MIDI_PROGRAM_CHANGE:
        if(trp->detectMode()) {
            for(index = 0; index < SETLIST_PATCH_PRESET_SIZE; index++) {
                if(trp->midiChannel(index) == mchan) {
                    trp->setPatch(message->at(1) + (midi_bank[index] << 7), index);
                    trp->updatePerformanceTab();
                    break;
                }
            }
        }
        break;
    }
}
//------------------------------------------------------------------------------
