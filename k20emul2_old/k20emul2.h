//#ifndef KB_H
//#define KB_H

#pragma once
#include "quantum.h"

//#include "config_common.h"
/*
#define LAYOUT( \
	K00, K01, K02, \
	K10, K11, K12, \
	K20, K21, K22, \
	K30, K31, K32, \
	K40, K41, K42, \
	K50, K51, K52, \
	K60, K61,      \
	K70  \
) { \
	{ K00,   K01,   K02 }, \
	{ K10,   K11,   K12 }, \
	{ K20,   K21,   K22 }, \
	{ K30,   K31,   K32 }, \
	{ K40,   K41,   K42 }, \
	{ K50,   K51,   K52 }, \
	{ K60,   K61,   KC_NO }, \
	{ K70,   KC_NO, KC_NO }  \
}
*/

// 아래 layout 안에는 절대 다른문자가 들어가면 안됨 코맨트도 안됨

/*
#define LAYOUT( \
	K00, K01, K02, K70, \
	K10, K11, K12, K61, \
	K20, K21, K22, K60,\
	K30, K31, K32, \
	K40, K41, K42, K52, \
	K50,      K51 \
  \
) { \
	{ K00,   K01,   K02 }, \
	{ K10,   K11,   K12 }, \
	{ K20,   K21,   K22 }, \
	{ K30,   K31,   K32 }, \
	{ K40,   K41,   K42 }, \
	{ K50,   K51,   K52 }, \
	{ K60,   K61,   KC_NO }, \
	{ K70,   KC_NO, KC_NO }  \
} */

// digital encoder를 키맵에 추가 CC,button,CCW  (221020)

#define LAYOUT( \
	K00, K01, K02, K70, K71, K62, K72,\
	K10, K11, K12, K61, \
	K20, K21, K22, K60,\
	K30, K31, K32, \
	K40, K41, K42, K52, \
	K50,      K51 \
  \
) { \
	{ K00,   K01,   K02 }, \
	{ K10,   K11,   K12 }, \
	{ K20,   K21,   K22 }, \
	{ K30,   K31,   K32 }, \
	{ K40,   K41,   K42 }, \
	{ K50,   K51,   K52 }, \
	{ K60,   K61,   K62 }, \
	{ K70,   K71,   K72 }  \
}

// enum K20_keycodes {
// #ifdef VIA_ENABLE
//     KC_TGUI = USER00,   // Toggle between GUI Lock or Unlock
//     NEW_SAFE_RANGE = SAFE_RANGE
// #else
//     KC_TGUI = SAFE_RANGE,   // Toggle between GUI Lock or Unlock
//     NEW_SAFE_RANGE
// #endif
// };

enum custom_keycodes {
#ifdef VIA_ENABLE
    KC_TGUI = USER00,   // Toggle between GUI Lock or Unlock
    KC_MISSION_CONTROL,
    KC_LAUNCHPAD,
    KC_LOPTN,
    KC_ROPTN,
    KC_LCMMD,
    KC_RCMMD,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER,    
    NEW_SAFE_RANGE = SAFE_RANGE
#else
    KC_TGUI = SAFE_RANGE,   // Toggle between GUI Lock or Unlock
    KC_MISSION_CONTROL,
    KC_LAUNCHPAD,
    KC_LOPTN,
    KC_ROPTN,
    KC_LCMMD,
    KC_RCMMD,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER,
    NEW_SAFE_RANGE
#endif
};

/* Function Prototype */
void off_all_leds(void);
void on_all_leds(void);

//#endif