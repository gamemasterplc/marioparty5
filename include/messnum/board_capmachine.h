#ifndef MESSNUM_BOARD_CAPMACHINE_H
#define MESSNUM_BOARD_CAPMACHINE_H

#include "messdir_enum.h"

enum {
    MESS_BOARD_CAPMACHINE_CHOICE = MESSNUM(MESS_BOARD_CAPMACHINE, 0),
    MESS_BOARD_CAPMACHINE_LASTTURN = MESSNUM(MESS_BOARD_CAPMACHINE, 1),
    MESS_BOARD_CAPMACHINE_FULL = MESSNUM(MESS_BOARD_CAPMACHINE, 2),
    MESS_BOARD_CAPMACHINE_USE = MESSNUM(MESS_BOARD_CAPMACHINE, 3),
    MESS_BOARD_CAPMACHINE_DECIDE = MESSNUM(MESS_BOARD_CAPMACHINE, 4),
    MESS_BOARD_CAPMACHINE_EVENT_FULL = MESSNUM(MESS_BOARD_CAPMACHINE, 5),
    MESS_BOARD_CAPMACHINE_CANCEL = MESSNUM(MESS_BOARD_CAPMACHINE, 6),
    MESS_BOARD_CAPMACHINE_GETCAPSULE = MESSNUM(MESS_BOARD_CAPMACHINE, 7),
};

#endif