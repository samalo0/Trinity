#ifndef MIDI_H
#define MIDI_H

#include <QtGlobal>
#include <vector>

#define MIDI_NO_PORT            0xFF

// general MIDI
#define MIDI_CONTROL_CHANGE     0xB0
#define MIDI_PROGRAM_CHANGE     0xC0
#define MIDI_SYSEX_START        0xF0
#define MIDI_SYSEX_ID           0x1A
#define MIDI_SYSEX_END          0xF7

// strymon CC specs
#define MIDI_CC_BYPASS          102
#define MIDI_CC_EXPRESSION      100
#define MIDI_CC_LOOPER_LEVEL    98
#define MIDI_CC_RECORD          87
#define MIDI_CC_PLAY            86
#define MIDI_CC_PATCH_BANK      0
#define MIDI_CC_REMOTE_TAP      93
#define MIDI_CC_STOP            85
#define MIDI_CC_UNDO            89

void midi_callBack(double deltatime, std::vector<unsigned char> *message, void *userData);

#endif // MIDI_H

