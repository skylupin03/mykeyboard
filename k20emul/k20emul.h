//#ifndef KB_H
//#define KB_H

#pragma once
#include "quantum.h"

//#include "config_common.h"

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

enum K20_keycodes {
#ifdef VIA_ENABLE
    KC_TGUI = USER00,   // Toggle between GUI Lock or Unlock
    NEW_SAFE_RANGE = SAFE_RANGE
#else
    KC_TGUI = SAFE_RANGE,   // Toggle between GUI Lock or Unlock
    NEW_SAFE_RANGE
#endif
};

/* Function Prototype */
void off_all_leds(void);
void on_all_leds(void);

//#endif