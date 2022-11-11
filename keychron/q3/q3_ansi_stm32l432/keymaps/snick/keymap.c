/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This pro2gram is free software: you can redistribute it and/or modify
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

#include QMK_KEYBOARD_H

#ifdef VIA_ENABLE
    #define USER_START USER00
#else
    #define USER_START SAFE_RANGE
#endif

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    LEFT_HANDED_GAMING,
    WIN_FN
};

enum custom_keycodes {
    KC_MISSION_CONTROL = USER_START,
    KC_LAUNCHPAD,
    KC_LOPTN,
    KC_ROPTN,
    KC_LCMMD,
    KC_RCMMD,
    KC_SIRI,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER,
    KC_SCREEN_SHOT,
    KC_CORTANA,
    KC_RESET
};

#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER
#define KC_SNAP KC_SCREEN_SHOT
#define KC_CRTA KC_CORTANA
#define KC_EEPROM_RESET EEPROM_RESET

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_87(
        KC_ESC,             KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  KC_SNAP,  KC_SIRI,  RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN,MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_87(
        KC_NO  ,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,   KC_NO  ,  KC_NO  ,  RGB_TOG,
        KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,   KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  NK_TOGG,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,   KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,
        KC_NO  ,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,             KC_NO  ,
        KC_NO  ,            KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,             KC_NO  ,            KC_NO  ,
        KC_NO  ,  KC_NO  ,  KC_NO  ,                                KC_NO  ,                                KC_NO  ,  KC_NO  ,  KC_NO  ,   KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ),

    [WIN_BASE] = LAYOUT_ansi_87(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,   KC_PSCR,  KC_CRTA,  RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN, MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [LEFT_HANDED_GAMING] = LAYOUT_ansi_87(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,   KC_PSCR,  KC_CRTA,  RGB_MOD,
        KC_BSPC,   KC_EQL,  KC_MINS,  KC_0,     KC_9,     KC_8,     KC_7,     KC_6,     KC_5,     KC_4,     KC_3,     KC_2,     KC_1,      KC_GRV,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_RBRC,  KC_LBRC,  KC_UP,    KC_O,     KC_I,     KC_U,     KC_Y,     KC_T,     KC_R,     KC_E,     KC_W,     KC_Q,     KC_TAB,    KC_TAB,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_K,     KC_J,     KC_H,     KC_G,     KC_F,     KC_A,     KC_S,     KC_D,                KC_ENT,
        KC_RSFT,            KC_SLSH,  KC_DOT,  KC_COMM,   KC_M,     KC_N,     KC_B,     KC_V,     KC_C,     KC_X,     KC_Z,                KC_LSFT,            KC_UP,
        KC_RCTL,  KC_LCMD,  KC_RALT,                                KC_SPC,                                 KC_LALT,  KC_RWIN, MO(WIN_FN), KC_LCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_87(
        KC_NO  ,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  KC_NO  ,  KC_NO  ,  RGB_TOG,
        KC_NO  ,  TO(WIN_BASE)   , TO(LEFT_HANDED_GAMING)  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,   KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,
        RGB_TOG,  RGB_MOD , RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  NK_TOGG,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,   KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,
        KC_NO  ,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,             KC_NO  ,
        KC_NO  ,            KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  QK_RESET  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ,             KC_NO  ,            KC_NO  ,
        KC_NO  ,  KC_NO   , KC_NO  ,                                KC_NO  ,                                KC_NO  ,  KC_NO  ,  KC_NO  ,   KC_NO  ,  KC_NO  ,  KC_NO  ,  KC_NO  ),
};

// layers colors for HSA
#define WHITE   {0,0,255}
#define ORANGE  {23,255,255}
#define BLUE    {170,255,255}
#define NO_COLOR {0,0,0}

const uint8_t PROGMEM rgb_matrix_led_map[][DRIVER_LED_TOTAL][5] = {
    { // MAC_BASE
        NO_COLOR,              NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,
        NO_COLOR, NO_COLOR  ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,
        NO_COLOR, NO_COLOR  ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,
        NO_COLOR, NO_COLOR  ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR           ,
        NO_COLOR            ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR           ,             NO_COLOR,
        NO_COLOR, NO_COLOR,  NO_COLOR,                              WHITE                                ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR           ,  NO_COLOR,  NO_COLOR,  NO_COLOR
    }, { // MAC_FN
        NO_COLOR,              NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,
        NO_COLOR, NO_COLOR  ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,
        NO_COLOR, NO_COLOR  ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,
        NO_COLOR, NO_COLOR  ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR           ,
        NO_COLOR            ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR           ,             NO_COLOR,
        NO_COLOR, NO_COLOR,  NO_COLOR,                              WHITE                                ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR           ,  NO_COLOR,  NO_COLOR,  NO_COLOR
    }, { // WIN_BASE
        NO_COLOR,              NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,
        NO_COLOR, NO_COLOR  ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,
        NO_COLOR, NO_COLOR  ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,
        NO_COLOR, NO_COLOR  ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR           ,
        NO_COLOR            ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR           ,             NO_COLOR,
        NO_COLOR, NO_COLOR,  NO_COLOR,                              ORANGE                               ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR           ,  NO_COLOR,  NO_COLOR,  NO_COLOR
    }, { // LEFT_HANDED_GAMING
        NO_COLOR,              NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,
        NO_COLOR, NO_COLOR  ,  BLUE    ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,
        NO_COLOR, BLUE      ,  BLUE    ,  BLUE    ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  BLUE    ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,
        NO_COLOR, NO_COLOR  ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  BLUE    ,  BLUE    ,  BLUE    ,  NO_COLOR           ,
        NO_COLOR            ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR           ,             BLUE    ,
        NO_COLOR, NO_COLOR,  NO_COLOR,                              BLUE                                 ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR           ,  BLUE    ,  BLUE    ,  BLUE
    }, { // WIN_FN
        NO_COLOR,              NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,
        NO_COLOR, NO_COLOR  ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,
        NO_COLOR, NO_COLOR  ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,
        NO_COLOR, NO_COLOR  ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR           ,
        NO_COLOR            ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR           ,             NO_COLOR,
        NO_COLOR, NO_COLOR,  NO_COLOR,                              ORANGE                               ,  NO_COLOR,  NO_COLOR,  NO_COLOR,  NO_COLOR           ,  NO_COLOR,  NO_COLOR,  NO_COLOR
    }
};

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&rgb_matrix_led_map[layer][i][0]),
            .s = pgm_read_byte(&rgb_matrix_led_map[layer][i][1]),
            .v = pgm_read_byte(&rgb_matrix_led_map[layer][i][2]),
        };

        if (!hsv.h && !hsv.s && !hsv.v) { continue; }

        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
}

void rgb_matrix_indicators_user(void) {
    set_layer_color(biton32(layer_state));
}
