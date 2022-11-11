//#ifndef KB_H
//#define KB_H

#pragma once
#include "quantum.h"

//#include "config_common.h"

// 아래 layout 안에는 절대 다른문자가 들어가면 안됨 코맨트도 안됨
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

// 커스텀 키 갯수가 16개 한계일까?
//#ifndef WINLOCK_DISABLED
// Define the TGUI key here so it is available in QMK configurator
enum K20_keycodes {
#ifdef VIA_ENABLE
    KC_TGUI = USER00,   // Toggle between GUI Lock or Unlock
    KC_WIN_MODE,             // WINDOWS Keyboard로 변경
    KC_MAC_MODE,             // Machintosh Keyboard로 변경
    KC_MISSION_CONTROL,     // MAC_key
    KC_LAUNCHPAD,           // MAC_key
KC_SPOTLIGHT,           // MAC_key
KC_DICTATION,           // MAC_key
KC_DO_NOT_DISTURB,      // MAC_key
KC_LOCK_SCREEN,         // MAC_key
    KC_LOPTN,               // MAC_key 불필요한듯
    KC_ROPTN,               // MAC_key 불필요한듯
    KC_LCMMD,               // MAC_key 불필요한듯
    KC_RCMMD,               // MAC_key 불필요한듯
    KC_TASK_VIEW,           // for win (gui + tap)
    KC_FILE_EXPLORER,       // for win (gui + e)
    KC_STER,                // LED effect step reverse
    KC_SPDI,                // LED effect speed up
    KC_SPDD,                // LED effect speed down
    KC_TKEY,                // all key input off
    NEW_SAFE_RANGE = SAFE_RANGE
#else
    KC_TGUI = SAFE_RANGE,   // Toggle between GUI Lock or Unlock
    KC_WIN_MODE,             // WINDOWS Keyboard로 변경
    KC_MAC_MODE,             // Machintosh Keyboard로 변경
    KC_MISSION_CONTROL,     // MAC_key
    KC_LAUNCHPAD,           // MAC_key
KC_SPOTLIGHT,           // MAC_key
KC_DICTATION,           // MAC_key
KC_DO_NOT_DISTURB,      // MAC_key
KC_LOCK_SCREEN,         // MAC_key
    KC_LOPTN,               // MAC_key 불필요한듯
    KC_ROPTN,               // MAC_key 불필요한듯
    KC_LCMMD,               // MAC_key 불필요한듯
    KC_RCMMD,               // MAC_key 불필요한듯
//    KC_TASK_VIEW,           // for win (gui + tap)
//    KC_FILE_EXPLORER,       // for win (gui + e)
    KC_STER,                // LED effect step reverse
    KC_SPDI,                // LED effect speed up
    KC_SPDD,                // LED effect speed down
    KC_TKEY,                // all key input off
    NEW_SAFE_RANGE
#endif
};

/* Function Prototype */
void off_all_leds(void);
void on_all_leds(void);

//#endif
