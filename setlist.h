#ifndef SETLIST_H
#define SETLIST_H

#include <QStringList>

#define SETLIST_SONG_SIZE               20

#define SETLIST_CHANNEL_SWITCH_SIZE     2

#define SETLIST_NAME_SIZE               16
#define SETLIST_MIDI_CHANNELS           16

#define SETLIST_PATCH_SIZE              3

#define SETLIST_PATCH_PRESET_SIZE       3
#define SETLIST_PATCH_PRESET_BIGSKY     0
#define SETLIST_PATCH_PRESET_MOBIUS     1
#define SETLIST_PATCH_PRESET_TIMELINE   2
#define SETLIST_PATCH_BYPASS            500


typedef struct {
    char patch_name[SETLIST_NAME_SIZE];
    quint16 patch_presets[SETLIST_PATCH_PRESET_SIZE];
    quint8 patch_switches[SETLIST_CHANNEL_SWITCH_SIZE];
} patch_data;

typedef struct {
    char setlist_name[SETLIST_NAME_SIZE];
    char song_names[SETLIST_SONG_SIZE][SETLIST_NAME_SIZE];
    patch_data setlist_songs[SETLIST_SONG_SIZE][SETLIST_PATCH_SIZE];
} setlist;

void setlist_init(setlist *sl);
QString setlist_patch_preset_string(quint16 preset, quint8 pedal_type);
quint16 setlist_patch_from_string(QString input, quint8 pedal_type);
void setlist_qstring_to_char(QString instr, char *outstr);

#endif // SETLIST_H
