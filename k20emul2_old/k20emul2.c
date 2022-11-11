/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

//#include "quantum.h"

#include "k20emul2.h"
#include <ch.h>
#include <hal.h>

/* Private Functions */
void off_all_leds(void) {
//    writePinHigh(LED_NUM_LOCK_PIN);
//    writePinHigh(LED_CAPS_LOCK_PIN);
//    writePinHigh(LED_SCROLL_LOCK_PIN);
writePinHigh(LED_JAMES1_PIN);
writePinHigh(LED_JAMES2_PIN);	
}

/* WinLock and MR LEDs are non-standard. Need to override led init */
void led_init_ports(void) {
//    setPinOutput(LED_NUM_LOCK_PIN);
//    setPinOutput(LED_CAPS_LOCK_PIN);
//    setPinOutput(LED_SCROLL_LOCK_PIN);
    setPinOutput(LED_JAMES1_PIN);
    setPinOutput(LED_JAMES2_PIN);

    off_all_leds();
}

static void hardware_reset_cb(void *arg) {
    chSysLockFromISR();
//    bootloader_jump();
/*
	if(!readPin(LED_JAMES1_PIN)){
		writePinHigh(LED_JAMES1_PIN);
	}
	else{
	 	writePinLow(LED_JAMES1_PIN);
	}
*/
    togglePin(LED_JAMES1_PIN);
#ifdef LED_MATRIX_ENABLE
    led_matrix_step();
#endif
    chSysUnlockFromISR(); 
}

static void BUTTON_EXT_PIN_cb(void *arg) {
    chSysLockFromISR();

	if(!readPin(LED_JAMES2_PIN)){
		writePinHigh(LED_JAMES2_PIN);
	}
	else{
	 	writePinLow(LED_JAMES2_PIN);
	}
 //        oled_write_P(PSTR("Test"), false);
    chSysUnlockFromISR(); 
}
//---------------------

#ifdef ENCODER_ENABLE

bool encoder_update_kb(uint8_t index, bool clockwise){
//  return encoder_update_user(index,clockwise);

    if (!encoder_update_user(index,clockwise)) { return false; }
    if(index == 0){
        if (clockwise) {
            tap_code_delay(KC_1, 10);
        } else {
            tap_code_delay(KC_2, 10);
        }
    }
    return true;
}
#endif

//---------------------
#ifdef DIP_SWITCH_ENABLE

bool dip_switch_update_kb(uint8_t index, bool active) {
    if (!dip_switch_update_user(index, active)) { return false; }
    if (index == 0) {
        default_layer_set(1UL << (active ? 2 : 0));        
    }    
    return true;
}
#endif

//---------------------

static bool win_key_locked = false;

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_TGUI:
            if (record->event.pressed) {
                // Toggle GUI lock on key press
                win_key_locked = !win_key_locked;
                writePin(LED_JAMES1_PIN, !win_key_locked);
            }
            break;
        case KC_LGUI:
            if (win_key_locked) { return false; }
            break;
    }
    return process_record_user(keycode, record);
}

//---------------------
void keyboard_pre_init_kb(void) {
    setPinInputHigh(HARDWARE_RESET_PIN);
	setPinInputHigh(BUTTON_EXT_PIN);

//    Jump to bootloader when the hardware reset button is pressed
    palEnablePadEvent(PAL_PORT(HARDWARE_RESET_PIN), PAL_PAD(HARDWARE_RESET_PIN), PAL_EVENT_MODE_FALLING_EDGE);
    palSetPadCallback(PAL_PORT(HARDWARE_RESET_PIN), PAL_PAD(HARDWARE_RESET_PIN), hardware_reset_cb, NULL);

    palEnablePadEvent(PAL_PORT(BUTTON_EXT_PIN), PAL_PAD(BUTTON_EXT_PIN), PAL_EVENT_MODE_FALLING_EDGE);
    palSetPadCallback(PAL_PORT(BUTTON_EXT_PIN), PAL_PAD(BUTTON_EXT_PIN), BUTTON_EXT_PIN_cb, NULL);

	// The interrupt is edge-triggered so check that it's not already pressed

    if (!readPin(HARDWARE_RESET_PIN)) {
        writePinHigh(LED_JAMES1_PIN); // bootloader_jump();
    }
}

#ifdef LED_MATRIX_ENABLE

 // __attribute__ ((weak)) 
void led_matrix_indicators_kb(void) {

    led_t host_leds = host_keyboard_led_state();

    if (host_leds.caps_lock) {
         led_matrix_set_value(72, 0xff); 
 //        led_matrix_set_value(0, 0xff); 
    }
    if (host_leds.scroll_lock) {
//         led_matrix_set_value(1, 0xff); 
        led_matrix_set_value(23, 0xff); 
         }
    if (host_keyboard_led_state().num_lock) { 
 //       led_matrix_set_value(2, 0xff); 
         led_matrix_set_value(47, 0xff);        
        }
}

//-----------------------------

const is31_led PROGMEM g_is31_leds[DRIVER_LED_TOTAL] = {
    {0,C1_1},         {0,C1_2},{0,C1_3},{0,C1_4},{0,C1_5},    {0,C1_6},{0,C1_7},{0,C1_8}, {0,C8_1},     //8

    {0,C2_1},         {0,C2_2},{0,C2_3},{0,C2_4},{0,C2_5},      {0,C2_6},{0,C2_7},{0,C2_8}, {0,C8_2},     {0,C7_14},{0,C7_15},{0,C7_16},{0,C1_9},   {0,C1_10},{0,C1_11},{0,C1_12},      {0,C1_13},{0,C1_14},{0,C1_15},{0,C1_16},         // 28           

    {0,C3_1},{0,C3_2},{0,C3_3},{0,C3_4},{0,C3_5},{0,C3_6},{0,C3_7},{0,C3_8}, {0,C8_3},{0,C8_4},{0,C8_5}, {0,C7_11},{0,C7_13}, {0,C3_9}, {0,C2_9},    {0,C2_10},{0,C2_11},{0,C2_12},     {0,C2_13},{0,C2_14},{0,C2_15},{0,C2_16},          // 50       
      {0,C4_1}, {0,C4_2},{0,C4_3},{0,C4_4},{0,C4_5},{0,C4_6},{0,C4_7},{0,C4_8},  {0,C8_6},{0,C8_7},  {0,C7_9},{0,C7_10}, {0,C7_12},  {0,C4_13},        {0,C3_10},{0,C3_11},{0,C3_12},    {0,C3_13},{0,C3_14},{0,C3_15},{0,C3_16},         // 71 
      {0,C5_1},  {0,C5_2},{0,C5_3},{0,C5_4},{0,C5_5},{0,C5_6},{0,C5_7},{0,C5_8},   {0,C4_9},{0,C4_10},{0,C4_11},{0,C4_12},                                                               {0,C4_14},{0,C4_15},{0,C4_16},         // 86
       {0,C6_1},   {0,C6_2},{0,C6_3},{0,C6_4},{0,C6_5},{0,C6_6},{0,C6_7},{0,C6_8},   {0,C5_9},{0,C5_10},{0,C5_11},       {0,C6_9},                             {0,C5_12},                 {0,C5_13},{0,C5_14},{0,C5_15},{0,C5_16},         // 103
    {0,C7_1},  {0,C7_2},  {0,C7_3},  {0,C7_4},               {0,C7_5},                   {0,C7_6},  {0,C7_7}, {0,C7_8},  {0,C6_10},  {0,C6_11},       {0,C6_12},{0,C6_13},{0,C6_14},         {0,C6_15},     {0,C6_16},          // 118
                                                                                                      
    {0,C9_1},{0,C9_2},{0,C9_3},{0,C9_4},{0,C9_5},{0,C9_6},{0,C9_7},{0,C9_8}, {0,C8_8}, {0,C8_9},{0,C8_10},{0,C8_11},{0,C8_12},{0,C8_13},{0,C8_14},{0,C8_15},{0,C8_16}, {0,C9_9},{0,C9_10},{0,C9_11},{0,C9_12},{0,C9_13},{0,C9_14},{0,C9_15},{0,C9_16}, // 143
};

#define ___ NO_LED

led_config_t g_led_config = { // K20 Key Matrix & 31FL3731 KEYBOARD LED TEST array (Mechanic RGB layout) (made at SKYDIGITAL)
    {        // Key Matrix to LED Index
        { 25,  26,  27},
        { 47,  48,  49},      //  { 47,  48,  49},
        { 68,  69,  70},
        { 84,  85,  86},
        {100, 101, 102},
        {117, 118, 103},
        { 71,  50, ___},
        { 28, ___, ___}    //{28, NO_LED, NO_LED}
    }, {

        // LED Index to Physical Position
        {  0, 0},            { 20, 0}, { 30, 00}, { 40, 00}, { 50, 00},     { 65, 00}, { 75, 00}, { 85, 00}, { 95, 00},             // 8

        {  0, 12},            { 20, 12}, { 30, 12}, { 40, 12}, { 50, 12},     { 65, 12}, { 75, 12}, { 85, 12}, { 95, 12},   {110, 12}, {120, 12}, {130, 12}, {140, 12},             {155, 12}, {165, 12}, {175, 12},   {190, 12}, {200, 12},{210, 12}, {220, 12},         // 28

        {  0, 24}, { 10, 24}, { 20, 24}, { 30, 24}, { 40, 24}, { 50, 24}, { 60, 24}, { 70, 24}, { 80, 24}, { 90, 24}, {100, 24}, {110, 24}, {120, 24}, {130, 24}, {140, 24},         {155, 24}, {165, 24}, {175, 24},   {190, 24}, {200, 24},{210, 24}, {220, 24},         // 50
          {  0, 30},    { 15, 30}, { 25, 30}, { 35, 30}, { 45, 30}, { 55, 30}, { 65, 30}, { 75, 30}, { 85, 30}, { 95, 30}, {105, 30}, {115, 30}, {125, 30},      {130, 33},          {155, 30}, {165, 30}, {175, 30},   {190, 30}, {200, 30},{210, 30}, {220, 30},         // 71   
            {  0, 36},      { 15, 36}, { 25, 36}, { 35, 36}, { 45, 36}, { 55, 36}, { 65, 36}, { 75, 36}, { 85, 36}, { 95, 36}, {105, 36}, {115, 36},                                                                     {194, 36}, {204, 36},{214, 36},         // 86
             {  0, 42},      { 20, 42}, { 30, 42}, { 40, 42}, { 50, 42}, { 60, 42}, { 70, 42}, { 80, 42}, { 90, 42}, {100, 42}, {110, 42},            {130, 42},                                 {165, 42},              {194, 42}, {204, 42},{214, 42}, {224, 42}, //103
        {  0, 48}, { 10, 48}, { 20, 48}, { 30, 48},                        {60, 48},                     { 90, 48}, {100, 48}, {110, 48}, { 120, 48}, { 140, 48},                     {155, 48}, {165, 48}, {175, 48},          {195, 48},     {210, 48},

        {  30, 64}, { 38, 64}, { 46, 64}, { 54, 64}, { 62, 64}, { 70, 64}, { 78, 64}, {86, 64}, {84, 64}, {92, 64}, {100, 64}, {108, 64}, {116, 64}, {124, 64}, {132, 64}, {140, 64}, {148, 64}, {156, 64}, {164, 64}, {172, 64}, {180, 64}, {188, 64}, {196, 64}, {204, 64}, {212, 64}
    }, {

        // LED Index to Flag
        4,    1, 2, 8, 4,  4, 4, 4, 4, 
        4,    4, 4, 4, 4,  4, 4, 4, 4,   4, 4, 4, 4,   4, 4, 4,   4, 4, 4, 1,           // <- Modified (LED_FLAG_MODIFIER)

        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,   4, 4, 4,   8, 4, 4, 4,           // <- Modified (LED_FLAG_INDICATOR)
          4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4, 4, 4,   4, 4, 4, 4, 
          4,  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,                    4, 4, 4, 
          4,  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,   4,          4,      4, 4, 4, 4, 
          4, 4, 4, 4,       4,      4, 4, 4, 4, 4,     4, 4, 4,     4,  4,  
          
       4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4        
    }
};
#endif

/*`
const is31_led PROGMEM g_is31_leds[DRIVER_LED_TOTAL] = {
    {0, C1_1}, {0, C1_2}, {0, C1_3}, {0, C1_4}, {0, C1_5}, {0, C1_6}, {0, C1_7}, {0, C1_8},    {0, C1_9}, {0, C1_10}, {0, C1_11}, {0, C1_12}, {0, C1_13}, {0, C1_14}, {0, C1_15}, {0, C1_16},
    {0, C2_1}, {0, C2_2}, {0, C2_3}, {0, C2_4}, {0, C2_5}, {0, C2_6}, {0, C2_7}, {0, C2_8},    {0, C2_9}, {0, C2_10}, {0, C2_11}, {0, C2_12}, {0, C2_13}, {0, C2_14}, {0, C2_15}, {0, C2_16},
    {0, C3_1}, {0, C3_2}, {0, C3_3}, {0, C3_4}, {0, C3_5}, {0, C3_6}, {0, C3_7}, {0, C3_8},    {0, C3_9}, {0, C3_10}, {0, C3_11}, {0, C3_12}, {0, C3_13}, {0, C3_14}, {0, C3_15}, {0, C3_16},
    {0, C4_1}, {0, C4_2}, {0, C4_3}, {0, C4_4}, {0, C4_5}, {0, C4_6}, {0, C4_7}, {0, C4_8},    {0, C4_9}, {0, C4_10}, {0, C4_11}, {0, C4_12}, {0, C4_13}, {0, C4_14}, {0, C4_15}, {0, C4_16},
    {0, C5_1}, {0, C5_2}, {0, C5_3}, {0, C5_4}, {0, C5_5}, {0, C5_6}, {0, C5_7}, {0, C5_8},    {0, C5_9}, {0, C5_10}, {0, C5_11}, {0, C5_12}, {0, C5_13}, {0, C5_14}, {0, C5_15}, {0, C5_16},

    {0, C6_1}, {0, C6_2}, {0, C6_3}, {0, C6_4}, {0, C6_5}, {0, C6_6}, {0, C6_7}, {0, C6_8},    {0, C6_9}, {0, C6_10}, {0, C6_11}, {0, C6_12}, {0, C6_13}, {0, C6_14}, {0, C6_15}, {0, C6_16},
    {0, C7_1}, {0, C7_2}, {0, C7_3}, {0, C7_4}, {0, C7_5}, {0, C7_6}, {0, C7_7}, {0, C7_8},    {0, C7_9}, {0, C7_10}, {0, C7_11}, {0, C7_12}, {0, C7_13}, {0, C7_14}, {0, C7_15}, {0, C7_16},
    {0, C8_1}, {0, C8_2}, {0, C8_3}, {0, C8_4}, {0, C8_5}, {0, C8_6}, {0, C8_7}, {0, C8_8},    {0, C8_9}, {0, C8_10}, {0, C8_11}, {0, C8_12}, {0, C8_13}, {0, C8_14}, {0, C8_15}, {0, C8_16},
    {0, C9_1}, {0, C9_2}, {0, C9_3}, {0, C9_4}, {0, C9_5}, {0, C9_6}, {0, C9_7}, {0, C9_8},    {0, C9_9}, {0, C9_10}, {0, C9_11}, {0, C9_12}, {0, C9_13}, {0, C9_14}, {0, C9_15}, {0, C9_16},
};

led_config_t g_led_config = { // K20 Key Matrix & 31FL3731 Full standard LED array(made at SKYDIGITAL)
    {
        // Key Matrix to LED Index
        {  0,  1,  2},
        { 16, 17, 18},
        { 32, 33, 34},
        { 48, 49, 50},
        { 64, 65, 66},
        { 80, 82, 67},
        { 35, 19, NO_LED },
        {  3, NO_LED,NO_LED,}
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
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,

        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4        
    }
};
*/

/*
const is31_led PROGMEM g_is31_leds[DRIVER_LED_TOTAL] = {
    {0, C1_2}, {0, C1_3}, {0, C1_4}, {0, C1_5}, {0, C1_6}, {0, C1_7}, {0, C1_8},
    {0, C2_2}, {0, C2_3}, {0, C2_4}, {0, C2_5}, {0, C2_6}, {0, C2_7}, {0, C2_8},
    {0, C3_2}, {0, C3_3}, {0, C3_4}, {0, C3_5}, {0, C3_6}, {0, C3_7}, {0, C3_8},
    {0, C4_2}, {0, C4_3}, {0, C4_4}, {0, C4_5}, {0, C4_6}, {0, C4_7}, {0, C4_8},
    {0, C5_2}, {0, C5_3}, {0, C5_4}, {0, C5_5}, {0, C5_6}, {0, C5_7}, {0, C5_8},
    {0, C6_2}, {0, C6_3}, {0, C6_4}, {0, C6_5}, {0, C6_6}, {0, C6_7}, {0, C6_8},
    {0, C7_2}, {0, C7_3}, {0, C7_4}, {0, C7_5}, {0, C7_6}, {0, C7_7}, {0, C7_8},
    {0, C8_2}, {0, C8_3}, {0, C8_4}, {0, C8_5}, {0, C8_6}, {0, C8_7}, {0, C8_8},
    //
    {0, C8_15},{0, C8_14},{0, C8_13},{0, C8_12},{0, C8_11},{0, C8_10},{0, C8_9},
    {0, C7_15},{0, C7_14},{0, C7_13},{0, C7_12},{0, C7_11},{0, C7_10},{0, C7_9},
    {0, C6_15},{0, C6_14},{0, C6_13},{0, C6_12},{0, C6_11},{0, C6_10},{0, C6_9},
    {0, C5_15},{0, C5_14},{0, C5_13},{0, C5_12},{0, C5_11},{0, C5_10},{0, C5_9},
    {0, C4_15},{0, C4_14},{0, C4_13},{0, C4_12},{0, C4_11},{0, C4_10},{0, C4_9},
    {0, C3_15},{0, C3_14},{0, C3_13},{0, C3_12},{0, C3_11},{0, C3_10},{0, C3_9},
    {0, C2_15},{0, C2_14},{0, C2_13},{0, C2_12},{0, C2_11},{0, C2_10},{0, C2_9}
};

led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        { NO_LED, NO_LED, NO_LED },
         { NO_LED, NO_LED, NO_LED },
        { NO_LED, NO_LED, NO_LED },
        { NO_LED, NO_LED, NO_LED },
         { NO_LED, NO_LED, NO_LED },
        { NO_LED, NO_LED, NO_LED },
         { NO_LED, NO_LED, NO_LED },
        { NO_LED, NO_LED, NO_LED }
    }, {
        // LED Index to Physical Position
        {   0,  0 }, {  16,  0 }, {  32,  0 }, {  48,  0 }, {  64,  0 }, {  80,  0 }, {  96,  0 }, { 112,  0 }, { 128,  0 }, { 144,  0 }, { 160,  0 }, { 176,  0 }, { 192,  0 }, { 208,  0 }, { 224,  0 },
        {   0, 11 }, {  16, 11 }, {  32, 11 }, {  48, 11 }, {  64, 11 }, {  80, 11 }, {  96, 11 }, { 112, 11 }, { 128, 11 }, { 144, 11 }, { 160, 11 }, { 176, 11 }, { 192, 11 }, { 208, 11 }, { 224, 11 },
        {   0, 21 }, {  16, 21 }, {  32, 21 }, {  48, 21 }, {  64, 21 }, {  80, 21 }, {  96, 21 }, { 112, 21 }, { 128, 21 }, { 144, 21 }, { 160, 21 }, { 176, 21 }, { 192, 21 }, { 208, 21 }, { 224, 21 },
        {   0, 32 }, {  16, 32 }, {  32, 32 }, {  48, 32 }, {  64, 32 }, {  80, 32 }, {  96, 32 }, { 112, 32 }, { 128, 32 }, { 144, 32 }, { 160, 32 }, { 176, 32 }, { 192, 32 }, { 208, 32 }, { 224, 32 },
        {   0, 43 }, {  16, 43 }, {  32, 43 }, {  48, 43 }, {  64, 43 }, {  80, 43 }, {  96, 43 }, { 112, 43 }, { 128, 43 }, { 144, 43 }, { 160, 43 }, { 176, 43 }, { 192, 43 }, { 208, 43 }, { 224, 43 },
        {   0, 53 }, {  16, 53 }, {  32, 53 }, {  48, 53 }, {  64, 53 }, {  80, 53 }, {  96, 53 }, { 112, 53 }, { 128, 53 }, { 144, 53 }, { 160, 53 }, { 176, 53 }, { 192, 53 }, { 208, 53 }, { 224, 53 },
        {   0, 64 }, {  16, 64 }, {  32, 64 }, {  48, 64 }, {  64, 64 }, {  80, 64 }, {  96, 64 }, { 112, 64 }, { 128, 64 }, { 144, 64 }, { 160, 64 }, { 176, 64 }, { 192, 64 }, { 208, 64 }, { 224, 64 }
    }, {
        // LED Index to Flag
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
    }
};
*/

