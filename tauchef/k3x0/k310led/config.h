/* Copyright 2021 Don Kjer and Tyler Tidman
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

#pragma once

#include "config_common.h"

/* key matrix size (cols in generic keyboard config) */
#define MATRIX_ROWS 8

#define MATRIX_ROW_PINS { A0, A1, A2, A3, A4, A5, A6, A7 }

/* LED indicator pins */
#define LED_NUM_LOCK_PIN    C8


#define BACKLIGHT_LEVELS 5
/* LED Matrix Driver Configuration */
#define LED_DRIVER_COUNT 1
#define LED_DRIVER_ADDR_1 0b1110111 // 0b1110100  //0b1110111
//#define DRIVER_ADDR_2 0b1110110   //0b1110100

//#define ISSI_TIMEOUT    100     // option
#define ISSI_PERSISTENCE 3     // option

#define LED_DRIVER_1_LED_TOTAL 144     //105       // 104
//#define DRIVER_2_LED_TOTAL 37
#define DRIVER_LED_TOTAL LED_DRIVER_1_LED_TOTAL       //  + DRIVER_2_LED_TOTAL)

//#define LED_MATRIX_ROWS 15
//#define LED_MATRIX_COLS 7

/* Enable caps-lock LED */
#define CAPS_LOCK_LED_INDEX 0
#define SCROLL_LOCK_LED_INDEX 1     //14
#define NUM_LOCK_LED_INDEX 2            //104


#define LED_MATRIX_KEYPRESSES // reacts to keypresses
//#define LED_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
//#define LED_MATRIX_FRAMEBUFFER_EFFECTS // enable framebuffer effects
//#define LED_DISABLE_TIMEOUT 0 // number of milliseconds to wait until led automatically turns off
//#define LED_DISABLE_AFTER_TIMEOUT 0 // OBSOLETE: number of ticks to wait until disabling effects
#define LED_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
//#define LED_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
//#define LED_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#define LED_MATRIX_MAXIMUM_BRIGHTNESS 255 // limits maximum brightness of LEDs
#define LED_MATRIX_STARTUP_MODE LED_MATRIX_BREATHING // Sets the default mode, if none has been set
#define LED_MATRIX_STARTUP_VAL LED_MATRIX_MAXIMUM_BRIGHTNESS/2 // Sets the default brightness value, if none has been set
#define LED_MATRIX_STARTUP_SPD 127
// #define LED_MATRIX_CENTER {112, 32}   

#define ENABLE_LED_MATRIX_ALPHAS_MODS
#define ENABLE_LED_MATRIX_BREATHING
#define ENABLE_LED_MATRIX_BAND
#define ENABLE_LED_MATRIX_BAND_PINWHEEL
#define ENABLE_LED_MATRIX_BAND_SPIRAL
#define ENABLE_LED_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_LED_MATRIX_CYCLE_UP_DOWN
#define ENABLE_LED_MATRIX_CYCLE_OUT_IN
#define ENABLE_LED_MATRIX_DUAL_BEACON   
#if defined(LED_MATRIX_KEYPRESSES)   // #if defined(LED_MATRIX_KEYREACTIVE_ENABLED)
#    define ENABLE_LED_MATRIX_SOLID_REACTIVE_SIMPLE
#    define ENABLE_LED_MATRIX_SOLID_REACTIVE_WIDE
#    define ENABLE_LED_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    define ENABLE_LED_MATRIX_SOLID_REACTIVE_CROSS
#    define ENABLE_LED_MATRIX_SOLID_REACTIVE_MULTICROSS
#    define ENABLE_LED_MATRIX_SOLID_REACTIVE_NEXUS
#    define ENABLE_LED_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define ENABLE_LED_MATRIX_SPLASH
#    define ENABLE_LED_MATRIX_MULTISPLASH
#endif
#define ENABLE_LED_MATRIX_WAVE_LEFT_RIGHT
#define ENABLE_LED_MATRIX_WAVE_UP_DOWN
#define ENABLE_LED_MATRIX_EFFECT_MAX

//#define I2C_DRIVER I2CD1
//#define I2C1_SCL_PIN B6
//#define I2C1_SDA_PIN B7
#define I2C1_SCL_PAL_MODE 1
#define I2C1_SDA_PAL_MODE 1

#define I2C1_TIMINGR_PRESC 2U  // 0_1_0_2_10  // 0_1_0_2_30  // 0_1_0_4_68  // 0_2_0_29_43
#define I2C1_TIMINGR_SCLDEL 0U  //2 0 0 9 14--> 100K/Digital Filter off
#define I2C1_TIMINGR_SDADEL 0U
#define I2C1_TIMINGR_SCLH 9U
#define I2C1_TIMINGR_SCLL 14U
