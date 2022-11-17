// Copyright 2022 jamesYun (@skylupin03)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// #include "config_common.h"  // 이것이 없으면  매트릭스 핀설정을 json파일에서 해줘야

#define MATRIX_ROWS 8
#define MATRIX_COLS 3

#define MATRIX_ROW_PINS { B8, A1, A2, A3, A4, A5, A6, A7 }
#define MATRIX_COL_PINS { B0, B1, B10 }

#define DIODE_DIRECTION ROW2COL

//#define WAIT_US_TIMER           GPTD3
//#define STM32_GPT_USE_TIM3 TRUE		// Board 디렉토리 파일에 디파인 있음

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define FORCE_NKRO

/* Bootmagic Lite key configuration */
#define EARLY_INIT_PERFORM_BOOTLOADER_JUMP TRUE
#define BOOTMAGIC_LITE_ROW                 0
#define BOOTMAGIC_LITE_COLUMN              0

//#define LED_NUM_LOCK_PIN    B12
//#define LED_CAPS_LOCK_PIN   B14
//#define LED_SCROLL_LOCK_PIN B15
#define LED_JAMES1_PIN	C13         // board LED
#define	LED_JAMES2_PIN	C14

#define LED_PIN_ON_STATE    0

#define HARDWARE_RESET_PIN  A0      // board KEY
#define BUTTON_EXT_PIN	C15         // 임시로 엔코더 버튼 사용

/* Encoder used pins */
#define ENCODERS_PAD_A { B13 }
#define ENCODERS_PAD_B { B14 }
/* Specifies the number of pulses the encoder registers between each detent */
#define ENCODER_RESOLUTION 2       //4

/* DIP switch */
//#define DIP_SWITCH_MATRIX_GRID  { {5,4} }
#define DIP_SWITCH_PINS { B12 }

// Dynamic EEPROM
// Something sensible or else VIA may crash
// Users may enable more if they wish
 #define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR  4095

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* 이건 뭐지?
// Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap
#define LOCKING_SUPPORT_ENABLE
// Locking resynchronize hack
#define LOCKING_RESYNC_ENABLE
*/

#ifdef BACKLIGHT_ENABLE
/* Backlight */
#define BACKLIGHT_PIN         B9
// #define BACKLIGHT_LED_COUNT 3
// #define BACKLIGHT_PINS { B9, A8, A9 }

#define BACKLIGHT_PWM_DRIVER  PWMD4
#define BACKLIGHT_PWM_CHANNEL 4
#define BACKLIGHT_PAL_MODE    2       //1
#define BACKLIGHT_LEVELS      31
#define BACKLIGHT_ON_STATE    1
//#define BACKLIGHT_PWM_OUTPUT_FREQUENCY 1000 // Increases backlight PWM freq if compiled with an unmerged PR. Does no harm without it.
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD      5
#define BACKLIGHT_DEFAULT_LEVEL 31
#define BACKLIGHT_DEFAULT_BREATHING
//#define BACKLIGHT_CAPS_LOCK
#endif

/* RGB Underlow or WS2812 RGB Matirx */
#define RGB_DI_PIN B15    // The pin connected to the data pin of the LEDs

#ifdef RGB_DI_PIN
//pwm driver
    // #define WS2812_PWM_DRIVER PWMD1
    // #define WS2812_PWM_CHANNEL 3
    // #define WS2812_PWM_PAL_MODE 1                   // 2 <- 072?
    // #define WS2812_PWM_COMPLEMENTARY_OUTPUT         // Define for a complementary timer output (TIMx_CHyN); omit for a normal timer output (TIMx_CHy).
    // #define WS2812_DMA_STREAM STM32_DMA2_STREAM5    // TIM1_UP = STM32_DMA2_STREAM5  / TIM1_CH3 = STM32_DMA2_STREAM6
    // #define WS2812_DMA_CHANNEL 6                    // 2
    // //#define WS2812_DMAMUX_ID STM32_DMAMUX1_TIM2_UP // DMAMUX configuration for TIMx_UP -- only required if your MCU has a DMAMUX peripheral, see the respective reference manual for the appropriate values for your MCU.
    // //#define WS2812_PWM_TARGET_PERIOD 800000
//spi driver
    #define WS2812_SPI                  SPID2
    #define WS2812_SPI_MOSI_PAL_MODE    5      // MOSI pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 5   // 0 for F072
    // #define WS2812_SPI_SCK_PIN       B13     //for F072?
    // #define WS2812_SPI_SCK_PAL_MODE  0       //for F072?
    #define WS2812_SPI_DIVISOR	        8      //4 4와 8만 되나?       //16
    #define WS2812_SPI_USE_CIRCULAR_BUFFER    // fix Fliker (이 기능을 켜면 access가 많아짐)

//#define RGBLIGHT_LED_MAP { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 23, 21, 19, 17, 15, 13, 11, 9, 7, 5, 3, 1  }
//#define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_RGB
#endif

#ifdef RGB_MATRIX_ENABLE
#define DRIVER_LED_TOTAL 254       // for RGB matrix //PWM으로 하면 갯수 255이상에서 에러발생 / SPI는 혹시 255에상에서 다운?
    #define RGBLED_NUM 254
#define RGB_MATRIX_STARTUP_VAL 40
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define RGB_DISABLE_WHEN_USB_SUSPENDED  // turn off effects when suspended
//#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT

#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON///////////////////////////////////
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define ENABLE_RGB_MATRIX_HUE_BREATHING
#define ENABLE_RGB_MATRIX_HUE_PENDULUM
#define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_FRACTAL
#define ENABLE_RGB_MATRIX_PIXEL_RAIN
#define ENABLE_RGB_MATRIX_PIXEL_FLOW

#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL

#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN

#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif
//------------------------------------------------------
#ifdef RGBLIGHT_ENABLE
    #define RGBLED_NUM 60             // for RGB Light & RGB matrix
    #define RGBLIGHT_HUE_STEP 8
    #define RGBLIGHT_SAT_STEP 8
    #define RGBLIGHT_VAL_STEP 8
    #define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
    #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_EFFECT_RAINBOW_MOOD
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_EFFECT_SNAKE
  #define RGBLIGHT_EFFECT_KNIGHT
  #define RGBLIGHT_EFFECT_CHRISTMAS
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  #define RGBLIGHT_EFFECT_RGB_TEST
  #define RGBLIGHT_EFFECT_ALTERNATING
  #define RGBLIGHT_EFFECT_TWINKLE
    /* default setup after eeprom reset */
    #define RGBLIGHT_DEFAULT_MODE (RGBLIGHT_EFFECT_RAINBOW_MOOD + 6)
//    #define RGBLIGHT_DEFAULT_HUE 152         // 이것 4개를 설정하면 BREATHING이 안되는건가? TWINKLE은 계속 안되고 있음
//    #define RGBLIGHT_DEFAULT_SAT 232
//    #define RGBLIGHT_DEFAULT_VAR 255         // 밝기
//    #define RGBLIGHT_DEFAULT_SPD 2
    //#define RGBLIGHT_LAYERS  // 뭐지?
#endif


#ifdef LED_MATRIX_ENABLE
/* LED Matrix Driver Configuration */
#define LED_DRIVER_COUNT 1
#define LED_DRIVER_ADDR_1 0b1110100 //0b1110111
//#define DRIVER_ADDR_2 0b1110110   //0b1110100

//#define ISSI_TIMEOUT    100     // option
#define ISSI_PERSISTENCE 3     // option

#define LED_DRIVER_1_LED_TOTAL 144     // 104
//#define DRIVER_2_LED_TOTAL 37
#define DRIVER_LED_TOTAL LED_DRIVER_1_LED_TOTAL       //  + DRIVER_2_LED_TOTAL)

//#define LED_MATRIX_ROWS 15
//#define LED_MATRIX_COLS 7

/* Enable caps-lock LED */
//#define CAPS_LOCK_LED_INDEX 0
//#define SCROLL_LOCK_LED_INDEX 1
//#define NUM_LOCK_LED_INDEX 47

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
#endif

/* I2C driver overrides */
//#define I2C_DRIVER I2CD1
//#define I2C1_SCL_PIN B6
//#define I2C1_SDA_PIN B7

// < for STM32F072 >
//#define I2C1_SCL_PAL_MODE 1
//#define I2C1_SDA_PAL_MODE 1

// < for STM32F072 - I2C Speed>
//#define I2C1_TIMINGR_PRESC 2U
//#define I2C1_TIMINGR_SCLDEL 0U  //2 0 0 9 14--> 100K/Digital Filter off
//#define I2C1_TIMINGR_SDADEL 0U
//#define I2C1_TIMINGR_SCLH 9U
//#define I2C1_TIMINGR_SCLL 14U


#ifdef OLED_ENABLE
/*  OLED Configulation */
// #define OLED_DISPLAY_ADDRESS 0x3C
// #define OLED_COM_PINS 0x12           // 크기가 작아짐.. 어디다 사용? 128x64에 사용하는 건가? 뭐지?

// #define OLED_IC OLED_IC_SSD1306      //안해도 default는 SSD1306

/* Required for SH1106 Oled Driver */
#define OLED_IC OLED_IC_SH1106      // YwRobot 1.3inch
#define OLED_COLUMN_OFFSET 2        // SH1106 screen is a little off to the left
/* Default Oled init */
#define OLED_TIMEOUT 20000              // Turns off OLED after said amount of milliseconds
#define OLED_DISPLAY_128X64
#define OLED_BRIGHTNESS 255

//#define OLED_UPDATE_INTERVAL 33 // ~30fps

#endif
