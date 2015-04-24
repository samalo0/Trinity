#include "setlist.h"

//------------------------------------------------------------------------------
// setlist_init
// Initialize the data in a setlist.
//------------------------------------------------------------------------------
void setlist_init(setlist *sl) {
    qint32 index;
    qint32 pindex;
    qint32 nindex;
    QString temp;

    temp.sprintf("SETLIST");
    setlist_qstring_to_char(temp, sl->setlist_name);

    for(index = 0; index < SETLIST_SONG_SIZE; index++) {
        temp.sprintf("SONG %d", index + 1);
        setlist_qstring_to_char(temp, sl->song_names[index]);
        for(pindex = 0; pindex < SETLIST_PATCH_SIZE; pindex++) {
            temp.sprintf("PATCH%d", pindex + 1);
            setlist_qstring_to_char(temp, sl->setlist_songs[index][pindex].patch_name);
            for(nindex = 0; nindex < SETLIST_CHANNEL_SWITCH_SIZE; nindex++) sl->setlist_songs[index][pindex].patch_switches[nindex] = false;
            for(nindex = 0; nindex < SETLIST_PATCH_PRESET_SIZE; nindex++) sl->setlist_songs[index][pindex].patch_presets[nindex] = SETLIST_PATCH_BYPASS;
        }
    }
}
//------------------------------------------------------------------------------
// setlist_patch_from_string
// Convert an input string in bank + letter format into an integer which
// represents the actual midi patch number.
//------------------------------------------------------------------------------
quint16 setlist_patch_from_string(QString input, quint8 pedal_type) {
    QByteArray temp;
    QByteArray tempnum;
    qint32 index;
    qint16 patch = SETLIST_PATCH_BYPASS;

    // convert to ascii string
    input = input.toUpper();
    temp = input.toLatin1();

    // need to make sure the format is correct
    // find starting number length
    for(index = 0; index < temp.size(); index++) {
       if(temp.at(index) < '0' || temp.at(index) > '9') break;
    }

    switch(pedal_type) {
    case SETLIST_PATCH_PRESET_BIGSKY:
        // check for bad input - bypass
        if(index == 0 || (temp.at(index) < 'A' && temp.at(index) > 'C') || index > 2) return SETLIST_PATCH_BYPASS;

        // get patch number
        tempnum = temp.left(index);
        patch = tempnum.toUShort() * 3;

        // add in mondifier for letter
        switch(temp.at(index)) {
        case 'B':
            patch++;
            break;
        case 'C':
            patch +=2;
            break;
        }
        break;
    case SETLIST_PATCH_PRESET_MOBIUS:
    case SETLIST_PATCH_PRESET_TIMELINE:
        // check for bad input - bypass
        if(index == 0 || (temp.at(index) < 'A' && temp.at(index) > 'B') || index > 2) return SETLIST_PATCH_BYPASS;

        // get patch number
        tempnum = temp.left(index);
        patch = tempnum.toUShort() * 2;

        // add in mondifier for letter
        if(temp.at(index) == 'B') patch++;
        break;
    }

    return patch;
}
//------------------------------------------------------------------------------
// setlist_patch_preset_string
// Return a string to display the patch selection properly in the bank number
// plus letter format. This format matches what it displayed on the pedals.
//------------------------------------------------------------------------------
QString setlist_patch_preset_string(quint16 preset, quint8 pedal_type) {
    QString retval;

    if(preset == SETLIST_PATCH_BYPASS) return "BYP";

    switch(pedal_type) {
    case SETLIST_PATCH_PRESET_BIGSKY:
        retval = QString::number(preset / 3);
        switch(preset % 3) {
        case 0:
            retval += "A";
            break;
        case 1:
            retval += "B";
            break;
        case 2:
            retval += "C";
            break;
        }
        break;
    case SETLIST_PATCH_PRESET_MOBIUS:
    case SETLIST_PATCH_PRESET_TIMELINE:
        retval = QString::number(preset / 2);
        switch(preset % 2) {
        case 0:
            retval += "A";
            break;
        case 1:
            retval += "B";
            break;
        }
        break;
    }

    return retval;
}
//------------------------------------------------------------------------------
// setlist_qstring_to_char
//------------------------------------------------------------------------------
void setlist_qstring_to_char(QString instr, char *outstr) {
    qint32 index;
    qint32 limit;
    QByteArray arg1 = instr.toLatin1();

    if(arg1.size() > (SETLIST_NAME_SIZE - 1)) limit = SETLIST_NAME_SIZE - 1;
    else limit = arg1.size();

    for(index = 0; index < limit; index++) outstr[index] = arg1.at(index);
    outstr[index] = 0;
}
//------------------------------------------------------------------------------
