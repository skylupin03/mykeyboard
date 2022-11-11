/* Copyright 2021 kuenhlee, Don Kjer, Tyler Tidman
 * Copyright 2021 Simon Arlott
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "quantum.h"

#include "k310led.h"
#include <ch.h>
#include <hal.h>

#include <math.h>
#include "print.h"

/* Private Functions */
void off_all_leds(void) {
#ifdef LED_NUM_LOCK_PIN
    writePinHigh(LED_NUM_LOCK_PIN);
#endif
    writePinHigh(LED_CAPS_LOCK_PIN);
    writePinHigh(LED_SCROLL_LOCK_PIN);
    writePinHigh(LED_WIN_LOCK_PIN);
    writePinHigh(LED_MR_LOCK_PIN);
}

void on_all_leds(void) {
#ifdef LED_NUM_LOCK_PIN
    writePinLow(LED_NUM_LOCK_PIN);
#endif
    writePinLow(LED_CAPS_LOCK_PIN);
    writePinLow(LED_SCROLL_LOCK_PIN);
    writePinLow(LED_WIN_LOCK_PIN);
    writePinLow(LED_MR_LOCK_PIN);
}

/* WinLock and MR LEDs are non-standard. Need to override led init */
void led_init_ports(void) {
#ifdef LED_NUM_LOCK_PIN
    setPinOutput(LED_NUM_LOCK_PIN);
#endif
    setPinOutput(LED_CAPS_LOCK_PIN);
    setPinOutput(LED_SCROLL_LOCK_PIN);
    setPinOutput(LED_WIN_LOCK_PIN);
    setPinOutput(LED_MR_LOCK_PIN);
    off_all_leds();
}

#ifndef WINLOCK_DISABLED
static bool win_key_locked = false;

//static bool all_key_locked = false;

static uint8_t mac_keycode[4] = { KC_LOPT, KC_ROPT, KC_LCMD, KC_RCMD };

typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[2];
} key_combination_t;

key_combination_t key_comb_list[2] = {
    {2, {KC_LWIN, KC_TAB}},
    {2, {KC_LWIN, KC_E}}
};

#define HCS(report) host_consumer_send(record->event.pressed ? report : 0); return false
#define HSS(report) host_system_send(record->event.pressed ? report : 0); return false


bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_TGUI:
            if (record->event.pressed) {  // Toggle GUI lock on key press
                win_key_locked = !win_key_locked;
                writePin(LED_WIN_LOCK_PIN, !win_key_locked);
            }
            break;
        case KC_LGUI:
            if (win_key_locked) { return false; }
            break;
#ifdef LED_MATRIX_ENABLE            
        case KC_STER:
            if (record->event.pressed) {  led_matrix_step_reverse(); }
            break;
        case KC_SPDI:
            if (record->event.pressed) {  led_matrix_increase_speed(); }
            break;
        case KC_SPDD:
            if (record->event.pressed) {  led_matrix_decrease_speed(); }
            break;
#endif        
        case KC_MISSION_CONTROL:
            if (record->event.pressed){
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false; // Skip all further processing of this key        
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key

        case KC_SPOTLIGHT:
            HCS(0x221);
        case KC_DICTATION:
            HCS(0xCF);
        case KC_DO_NOT_DISTURB:
            HSS(0x9B);
        case KC_LOCK_SCREEN:
            HCS(0x19E);

        case KC_LOPTN:
        case KC_ROPTN:
        case KC_LCMMD:
        case KC_RCMMD:
            if (record->event.pressed) {
                register_code(mac_keycode[keycode - KC_LOPTN]);
            } else {
                unregister_code(mac_keycode[keycode - KC_LOPTN]);
            }
            return false;  // Skip all further processing of this key

        // case KC_TASK_VIEW:
        // case KC_FILE_EXPLORER:
        //     if (record->event.pressed) {
        //         for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK_VIEW].len; i++) {
        //             register_code(key_comb_list[keycode - KC_TASK_VIEW].keycode[i]);
        //         }
        //     } else {
        //         for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK_VIEW].len; i++) {
        //             unregister_code(key_comb_list[keycode - KC_TASK_VIEW].keycode[i]);
        //         }
        //     }
        //     return false;  // Skip all further processing of this key

        case KC_WIN_MODE:
            writePinHigh(LED_MR_LOCK_PIN);        
            set_single_persistent_default_layer(0);        
            // default_layer_set(1UL << 0);
            // layer_off(2);
            // layer_on(0);
            return false;

        case KC_MAC_MODE:
            writePinLow(LED_MR_LOCK_PIN);        
            set_single_persistent_default_layer(2);        
            // default_layer_set(1UL << 2);
            // layer_off(0);
            // layer_on(2);
            return false;            

        // case KC_TKEY:                        // 전체키 input off -> 좀 더  손을 봐야 함 위에 나열한 키는 입력이 되며, FN키는 동작되게 해야 할듯함
        //     if (record->event.pressed){
        //         all_key_locked = !all_key_locked;
        //         writePin(LED_MR_LOCK_PIN, !all_key_locked);                                          
        //     }
        //     break;
        // default:
        //     if (all_key_locked) { return false;  }
    }
    return process_record_user(keycode, record);
}
#endif /* WINLOCK_DISABLED */

#ifndef HW_RESET_PIN_DISABLED
static void hardware_reset_cb(void *arg) {
    chSysLockFromISR();
    bootloader_jump();
    chSysUnlockFromISR();
}
#endif

void keyboard_pre_init_kb(void) {
    setPinInputHigh(HARDWARE_RESET_PIN);

#ifndef HW_RESET_PIN_DISABLED
    /* Jump to bootloader when the hardware reset button is pressed */
    palEnablePadEvent(PAL_PORT(HARDWARE_RESET_PIN), PAL_PAD(HARDWARE_RESET_PIN), PAL_EVENT_MODE_FALLING_EDGE);
    palSetPadCallback(PAL_PORT(HARDWARE_RESET_PIN), PAL_PAD(HARDWARE_RESET_PIN), hardware_reset_cb, NULL);

    /* The interrupt is edge-triggered so check that it's not already pressed */
    if (!readPin(HARDWARE_RESET_PIN)) {
        bootloader_jump();
    }
#endif
}
//----------------------------------

#ifdef LED_MATRIX_ENABLE

__attribute__ ((weak)) void led_matrix_indicators_kb(void) {

    led_t host_leds = host_keyboard_led_state();

    if (host_leds.caps_lock) {led_matrix_set_value(48, 0xff);  }
    if (host_leds.scroll_lock) {led_matrix_set_value(14, 0xff); }
    if (host_keyboard_led_state().num_lock) { led_matrix_set_value(104, 0xff);  }
}
//----------------------------------

const is31_led PROGMEM g_is31_leds[DRIVER_LED_TOTAL] = {
    {0, C1_1}, {0, C1_2}, {0, C1_3}, {0, C1_4}, {0, C1_5}, {0, C1_6}, {0, C1_7}, {0, C1_8},    {0, C1_9}, {0, C1_10}, {0, C1_11}, {0, C1_12}, {0, C1_13}, {0, C1_14}, {0, C1_15}, {0, C1_16},
    {0, C2_1}, {0, C2_2}, {0, C2_3}, {0, C2_4}, {0, C2_5}, {0, C2_6}, {0, C2_7}, {0, C2_8},    {0, C2_9}, {0, C2_10}, {0, C2_11}, {0, C2_12}, {0, C2_13}, {0, C2_14}, {0, C2_15}, {0, C2_16},
    {0, C3_1}, {0, C3_2}, {0, C3_3}, {0, C3_4}, {0, C3_5}, {0, C3_6}, {0, C3_7}, {0, C3_8},    {0, C3_9}, {0, C3_10}, {0, C3_11}, {0, C3_12}, {0, C3_13}, {0, C3_14}, {0, C3_15}, {0, C3_16},
    {0, C4_1}, {0, C4_2}, {0, C4_3}, {0, C4_4}, {0, C4_5}, {0, C4_6}, {0, C4_7}, {0, C4_8},    {0, C4_9}, {0, C4_10}, {0, C4_11}, {0, C4_12}, {0, C4_13}, {0, C4_14}, {0, C4_15}, {0, C4_16},
    {0, C5_1}, {0, C5_2}, {0, C5_3}, {0, C5_4}, {0, C5_5}, {0, C5_6}, {0, C5_7}, {0, C5_8},    {0, C5_9}, {0, C5_10}, {0, C5_11}, {0, C5_12}, {0, C5_13}, {0, C5_14}, {0, C5_15}, {0, C5_16},

    {0, C6_1}, {0, C6_2}, {0, C6_3}, {0, C6_4}, {0, C6_5}, {0, C6_6}, {0, C6_7}, {0, C6_8},    {0, C6_9}, {0, C6_10}, {0, C6_11}, {0, C6_12}, {0, C6_13}, {0, C6_14}, {0, C6_15}, {0, C6_16},
    {0, C7_1}, {0, C7_2}, {0, C7_3}, {0, C7_4}, {0, C7_5}, {0, C7_6}, {0, C7_7}, {0, C7_8},    {0, C7_9}, {0, C7_10}, {0, C7_11}, {0, C7_12}, {0, C7_13}, {0, C7_14}, {0, C7_15}, {0, C7_16},
    {0, C8_1}, {0, C8_2}, {0, C8_3}, {0, C8_4}, {0, C8_5}, {0, C8_6}, {0, C8_7}, {0, C8_8},    {0, C8_9}, {0, C8_10}, {0, C8_11}, {0, C8_12}, {0, C8_13}, {0, C8_14}, {0, C8_15}, {0, C8_16},
    {0, C9_1}, {0, C9_2}, {0, C9_3}, {0, C9_4}, {0, C9_5}, {0, C9_6}, {0, C9_7}, {0, C9_8},    {0, C9_9}, {0, C9_10}, {0, C9_11}, {0, C9_12}, {0, C9_13}, {0, C9_14}, {0, C9_15}, {0, C9_16}
};

#define __ NO_LED
#define ___ NO_LED

led_config_t g_led_config = {
    {  // Key Matrix to LED Index
     
        // {  0,  1,  2,  3,  4,  5,  6,  7,    8,  9, 10, 11, 12, 13, 14, 15 },
        // { 16, 17, 18, 19, 20, 21, 22, 23,   24, 25, 26, 27, 28, 29, 30, 31 },
        // { 32, 33, 34, 35, 36, 37, 38, 39,   40, 41, 42, 43, 44, 45, 46, 47 },
        // { 48, 49, 50, 51, 52, 53, 54, 55,   56, 57, 58, 59, 60, 61, 62, 63 },
        // { 64, 65, 66, 67, 68, 69, 70, 71,   72, 73, 74, 75, 76, 77, 78, 79 },    
        // { 80, 81, 82, 83, 84, 85, 86, 87,   88, 89, 90, 91, 92, 93, 94, 95 },
        // { 96, 97, 98, 99,100,101,102,103,  104,105,106,107,108,109,110,111 }, 
        // {112,113,114,115,116,117,118,119,  120,121,122,123,124,125,126,127 },
        // {128,129,130,131,132,133,134,135,  136,137,138,139,140,141,142,143 }

    { 00,  01,  02,  03,  04,  05,  06,  07,     8,   9,  10,  11,  12,  13,  14,  15 },  \
    { 16,  17,  18,  19,  20,  21,  22,  23,    24,  25,  26,  27,  28, ___,  30,  47 },  \
    { 32,  33,  34,  35,  36,  37,  38,  39,    40,  41,  42,  43,  44,  45,  31,  46 },  \
    { 48,  49,  50,  51,  52,  53,  54,  55,    56,  57,  58,  59,  62,  62,  63,  79 },  \
    { 64,  65,  66,  67,  68,  69,  70,  71,    72,  73,  74,  75, ___,  77,  61,  78 },  \
    { 80,  81,  82, ___, ___, ___,  85, ___,   ___, ___,  88,  89,  90,  91,  92,  93 },  \
    {___, ___, ___, ___, ___, ___, ___, 107,   106, 105, 104, 123, 110, 109, 108,  94 },  \
    {___, ___, ___, ___, ___, ___, ___,  127,  122, 121, 120, 111, 126, 125, 124,  95 }          
/*
< 사용하지 않는 led >
29,60,76, 83,86,87
96, 97,98,99,100,101,102,103,    112,113,114,115,116,117,118,119, 
128,129,130,131,132,133,134,135,   136,137,138,139,140,141,142,143

     [_BASE] = LAYOUT_all( // Base Layer
      KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_PSCR, KC_SLCK, KC_PAUS,
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,    KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,                                   KC_P4,   KC_P5,   KC_P6,
      KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,             KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PENT,
      KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_FN), KC_APP,  KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT
  ),
    
    #define LAYOUT_all( \
      K00,        K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C,      K0D,  K0E,  K0F,                          \
      K10,  K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K1A,  K1B,  K1C,  K1E,      K2E,  K2F,  K1F,      K6A, K69, K68, K67, \
      K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29,  K2A,  K2B,  K2C,  K2D,      K3D,  K3E,  K3F,      K7A, K79, K78, K6B, \
      K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C,  K4E,                            K7E, K7D, K7C,      \
      K40,  K41,  K42,  K43,  K44,  K45,  K46,  K47,  K48,  K49,  K4A,  K4B,        K4D,            K4F,            K6E, K6D, K6C, K7B, \
      K50,  K51,  K52,                    K56,                    K5A,  K5B,  K5C,  K5D,      K5E,  K5F,  K6F,      K7F,      K77       \
) { \
    { K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C,  K0D,  K0E,  K0F },  \
    { K10,  K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K1A,  K1B,  K1C,  XXX,  K1E,  K1F },  \
    { K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29,  K2A,  K2B,  K2C,  K2D,  K2E,  K2F },  \
    { K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C,  K3D,  K3E,  K3F },  \
    { K40,  K41,  K42,  K43,  K44,  K45,  K46,  K47,  K48,  K49,  K4A,  K4B,  XXX,  K4D,  K4E,  K4F },  \
    { K50,  K51,  K52,  XXX,  XXX,  XXX,  K56,  XXX,  XXX,  XXX,  K5A,  K5B,  K5C,  K5D,  K5E,  K5F },  \
    { XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  K67,  K68,  K69,  K6A,  K6B,  K6C,  K6D,  K6E,  K6F },  \
    { XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  K77,  K78,  K79,  K7A,  K7B,  K7C,  K7D,  K7E,  K7F }   \
}*/

    }, {
        // LED Index to Physical Position
        {  0,  0}, { 15,  0}, { 30,  0}, { 45,  0}, { 60,  0}, { 75,  0}, { 90,  0}, {105,  0}, {130,  0}, {145,  0}, {160,  0}, {175,  0}, {190,  0}, {205,  0}, {220,  0}, {235,  0},
        {  0,  8}, { 15,  8}, { 30,  8}, { 45,  8}, { 60,  8}, { 75,  8}, { 90,  8}, {105,  8}, {130,  8}, {145,  8}, {160,  8}, {175,  8}, {190,  8}, {205,  8}, {220,  8}, {235,  8},
        {  0, 16}, { 15, 16}, { 30, 16}, { 45, 16}, { 60, 16}, { 75, 16}, { 90, 16}, {105, 16}, {130, 16}, {145, 16}, {160, 16}, {175, 16}, {190, 16}, {205, 16}, {220, 16}, {235, 16},
        {  0, 24}, { 15, 24}, { 30, 24}, { 45, 24}, { 60, 24}, { 75, 24}, { 90, 24}, {105, 24}, {130, 24}, {145, 24}, {160, 24}, {175, 24}, {190, 24}, {205, 24}, {220, 24}, {235, 24},
        {  0, 32}, { 15, 32}, { 30, 32}, { 45, 32}, { 60, 32}, { 75, 32}, { 90, 32}, {105, 32}, {130, 32}, {145, 32}, {160, 32}, {175, 32}, {190, 32}, {205, 32}, {220, 32}, {235, 32},

        {  0, 40}, { 15, 40}, { 30, 40}, { 45, 40}, { 60, 40}, { 75, 40}, { 90, 40}, {105, 40}, {130, 40}, {145, 40}, {160, 40}, {175, 40}, {190, 40}, {205, 40}, {220, 40}, {235, 40},
        {  0, 48}, { 15, 48}, { 30, 48}, { 45, 48}, { 60, 48}, { 75, 48}, { 90, 48}, {105, 48}, {130, 48}, {145, 48}, {160, 48}, {175, 48}, {190, 48}, {205, 48}, {220, 48}, {235, 48},
        {  0, 56}, { 15, 56}, { 30, 56}, { 45, 56}, { 60, 56}, { 75, 56}, { 90, 56}, {105, 56}, {130, 56}, {145, 56}, {160, 56}, {175, 56}, {190, 56}, {205, 56}, {220, 56}, {235, 56},
        {  0, 64}, { 15, 64}, { 30, 64}, { 45, 64}, { 60, 64}, { 75, 64}, { 90, 64}, {105, 64}, {130, 64}, {145, 64}, {160, 64}, {175, 64}, {190, 64}, {205, 64}, {220, 64}, {235, 64}
    }, {
        // LED Index to Flag
        9, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4, 1, 8, 1,  //15       // scroll lock
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,  //31 
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,  //47      
        8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1,  //63     caplock
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1,  // 79
        1, 1, 1, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 4,  // 95
        4, 4, 4, 4, 4, 4, 4, 4, 8, 1, 1, 1, 4, 4, 4, 1,  // 111     numlock

        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 4, 4, 4, 4,  // 127
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4        
    }
};
#endif
