#include QMK_KEYBOARD_H
#include "k20emul2.h"

enum layers { WIN_BASE,
              WIN_FN,
              MAC_BASE,
              MAC_FN
            };

// enum custom_keycodes {
// #ifdef VIA_ENABLE
//     KC_TGUI = USER00,   // Toggle between GUI Lock or Unlock
//     KC_MISSION_CONTROL,
//     KC_LAUNCHPAD,
//     KC_LOPTN,
//     KC_ROPTN,
//     KC_LCMMD,
//     KC_RCMMD,
//     KC_TASK_VIEW,
//     KC_FILE_EXPLORER,
//     NEW_SAFE_RANGE = SAFE_RANGE
// #else
//     KC_TGUI = SAFE_RANGE,   // Toggle between GUI Lock or Unlock
//     KC_MISSION_CONTROL,
//     KC_LAUNCHPAD,
//     KC_LOPTN,
//     KC_ROPTN,
//     KC_LCMMD,
//     KC_RCMMD,
//     KC_TASK_VIEW,
//     KC_FILE_EXPLORER,
//     NEW_SAFE_RANGE
// #endif
// };

#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER

typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[2];
} key_combination_t;

key_combination_t key_comb_list[2] = {
    {2, {KC_LWIN, KC_TAB}},
    {2, {KC_LWIN, KC_E}}
};

static uint8_t mac_keycode[4] = { KC_LOPT, KC_ROPT, KC_LCMD, KC_RCMD };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │Esc│Tab│MO1│Bsp│
     * ├───┼───┼───┼───┤
     * │Num│ / │ * │ - │
     * ├───┼───┼───┼───┤
     * │ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┤ + │
     * │ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │   │
     * ├───┴───┼───┤Ent│
     * │ 0     │ . │   │
     * └───────┴───┴───┘
     */
    [WIN_BASE] = LAYOUT(KC_ESC,  KC_TAB,  KC_BSPC,   MO(1), KC_VOLD, KC_MUTE, KC_VOLU,
                        KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
                        KC_P7,    KC_P8,   KC_P9, KC_PPLS,
                        KC_P4,    KC_P5,   KC_P6,
                        KC_P1,    KC_P2,   KC_P3, KC_PENT,
                        KC_LWIN,          KC_PDOT),
    /*
     * ┌───┐───┬───┬───┐
     * │Rst│Tab│MO1│Bsp│
     * └───┘───┼───┼───┤
     * │Num│ / │ * │ - │
     * ┌───┬───┬───┐───┤
     * │Hom│ ↑ │PgU│   │
     * ├───┼───┼───┤ + │
     * │ ← │   │ → │   │
     * ├───┼───┼───┤───┤
     * │End│ ↓ │PgD│   │
     * ├───┴───┼───┤Ent│
     * │Insert │Del│   │
     * └───────┴───┘───┘
     */
    [WIN_FN] = LAYOUT(KC_CALC, BL_STEP, NK_TOGG, KC_TRNS, BL_DEC, BL_STEP, BL_INC,
                    BL_TOGG,   KC_STER, RGB_TOG, KC_F9,
                    BL_BRTG,   KC_SPDI, RGB_MOD, KC_TRNS,
                    BL_INC,    KC_SPDD, RGB_HUI,
                    BL_DEC,    RGB_MOD, RGB_HUD, QK_BOOT,
                    KC_TGUI,           KC_TRNS),

    [MAC_BASE] = LAYOUT(KC_ESC,   KC_TAB, KC_BSPC,    MO(3),   KC_VOLD, KC_MUTE, KC_VOLU,
                        KC_NLCK, KC_PSLS, KC_PAST,  KC_PMNS,
                        KC_P7,     KC_P8,   KC_P9,  KC_PPLS,
                        KC_P4,     KC_P5,   KC_P6,
                        KC_P1,     KC_P2,   KC_P3,  KC_PENT,
                        RGB_SPI,          RGB_SPD),

    [MAC_FN] = LAYOUT(RGB_TOG, RGB_MOD,  RGB_RMOD, KC_TRNS,   RGB_SPI, BL_STEP,RGB_SPD,
                      RGB_HUI, RGB_M_P,  RGB_M_SN, RGB_M_T,
                      RGB_HUD, RGB_M_B,  RGB_M_K,  RGB_M_TW,
                      RGB_SAI, RGB_M_R,  RGB_M_X,
                      RGB_SAD, RGB_M_SW, RGB_M_G,  QK_BOOT,
                      RGB_VAI,           RGB_VAD)
};
    /*
    // All RGB matrix keycodes are currently shared with the RGBLIGHT system
    // PLAIN, BREATHE, RAINBOW, SWIRL,
    // (RGB light only ->) SNAKE, NIGHT, XMAS, GRADIENT, RGBTEST, TWINKLE
                     (RGB_TOG, RGB_MOD,  RGB_RMOD, KC_TRNS,   RGB_VAI, BL_STEP,RGB_VAD,
                      RGB_HUI, RGB_M_P,  RGB_M_SN, RGB_M_T,
                      RGB_HUD, RGB_M_B,  RGB_M_K,  RGB_M_TW,
                      RGB_SAI, RGB_M_R,  RGB_M_X,
                      RGB_SAD, RGB_M_SW, RGB_M_G,  QK_BOOT,
                      RGB_SPI,           RGB_SPD),
    */

// KC_MCTL KC_MISSION_CONTROL
// KC_LPAD KC_LAUNCHPAD
// KC_TASK KC_TASK_VIEW
// KC_FLXP KC_FILE_EXPLORER
// KC_LOPTN left option   (win위치)
// KC_ROPTN right option
// KC_LCMMD left command  (ALT위치)
// KC_RCMMD right command



// #ifdef ENCODER_MAP_ENABLE
// const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
//     [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
//     [WIN_FN] = { ENCODER_CCW_CW(BL_DEC, BL_INC) },
// };
// #endif


#if defined(VIA_ENABLE) && defined(ENCODER_ENABLE)

#define ENCODERS 1
static uint8_t  encoder_state[ENCODERS] = {0};
static keypos_t encoder_cw[ENCODERS]    = {{2, 7}};
static keypos_t encoder_ccw[ENCODERS]   = {{1, 7}};

void encoder_action_unregister(void) {
    for (int index = 0; index < ENCODERS; ++index) {
        if (encoder_state[index]) {
            keyevent_t encoder_event = (keyevent_t){
                .key = encoder_state[index] >> 1 ? encoder_cw[index] : encoder_ccw[index],
                .pressed = false,
                .time = (timer_read() | 1)
             };
            encoder_state[index]     = 0;
            action_exec(encoder_event);
        }
    }
}

void encoder_action_register(uint8_t index, bool clockwise){
    keyevent_t encoder_event = (keyevent_t){
        .key = clockwise ? encoder_cw[index] : encoder_ccw[index],
        .pressed = true,
        .time = (timer_read() | 1)
    };
    encoder_state[index] = (clockwise ^ 1) | (clockwise << 1);
    action_exec(encoder_event);
}

void matrix_scan_user(void) {
    togglePin(LED_JAMES2_PIN);
    encoder_action_unregister();
}

bool encoder_update_user(uint8_t index, bool clockwise) {

    encoder_action_register(index, clockwise);

    // if (index == 0) {
    //     if (IS_LAYER_ON(WIN_FN)) {
    //         if (clockwise) {
    //             tap_code_delay(KC_P8, 10);
    //         } else {
    //             tap_code_delay(KC_P2, 10);
    //         }
    //     }

    //     else {
    //         if (clockwise) {
    //             tap_code_delay(KC_VOLU, 10);
    //         } else {
    //             tap_code_delay(KC_VOLD, 10);
    //         }
    //     }
    // }
    return false;
}
#else
void matrix_scan_user(void) {

    togglePin(LED_JAMES2_PIN);
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
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
        case KC_TASK:
        case KC_FLXP:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    register_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            } else {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    unregister_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            }
            return false;  // Skip all further processing of this key
        default:
            return true;   // Process all other keycodes normally
    }
}

//---------------------
// #ifdef DIP_SWITCH_ENABLE

// bool dip_switch_update_user(uint8_t index, bool active) {
//     switch (index){
//         case 0:
//             if (index == 0){
//                 default_layer_set(1UL << (active ? 2 : 0));     //default_layer_set(1UL << (active ? 2 : 0));
//             }
//             break;
//         default;
//     }
//     return true;
// }1
// #endif

//---------------------

#ifdef OLED_ENABLE

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case WIN_BASE:
            oled_write_P(PSTR("WINdows\n"), false);
            break;
        case WIN_FN:
            oled_write_P(PSTR("WIN-FN\n"), false);
            break;
        case MAC_BASE:
            oled_write_P(PSTR("MACintosh\n"), false);
            break;
        case MAC_FN:
            oled_write_P(PSTR("MAC-FN\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("error?"), false);
    }

    oled_write_P(PSTR("---------------\n"), false);

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM  ") : PSTR("     "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP  ") : PSTR("     "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR  ") : PSTR("     "), false);

    return false;
}

// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//     return OLED_ROTATION_0;
// }

// static void render_logo(void) {

//     static const char PROGMEM qmk_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//     };
//     oled_write_P(qmk_logo, false);
// }
// // OLED
// bool oled_task_user(void) {

//     togglePin(LED_JAMES1_PIN);

//     render_logo();
//     //oled_scroll_right(); 이부분은 주석끄면 로고가 스크롤됩니다 안꺼도 config.h에서 준 시간 이후 스크롤됩니다
//      return false;
// }

#endif
//----------------------------------
