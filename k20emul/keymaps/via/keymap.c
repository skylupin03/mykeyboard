#include QMK_KEYBOARD_H

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
    [0] = LAYOUT(
		KC_ESC, KC_TAB, KC_BSPC, 
		KC_NLCK, KC_PSLS, KC_PAST, 
		KC_P7, KC_P8, KC_P9, 
		KC_P4, KC_P5, KC_P6, 
		KC_P1, KC_P2, KC_P3, 
		KC_LWIN, KC_PDOT, KC_PENT, 
		KC_PPLS, KC_PMNS, 
		MO(1)
    ),

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
    [1] = LAYOUT(
		KC_CALC, KC_R, NK_TOGG, 
		KC_TRNS, KC_TRNS, KC_TRNS, 
		BL_TOGG, BL_STEP, RGB_TOG, 
		BL_INC, KC_TRNS, RGB_HUI, 
		BL_DEC, RGB_MOD, RGB_HUD, 
		KC_TGUI, KC_TRNS, QK_BOOT, 
		KC_TRNS, KC_F9, 
		KC_TRNS
    )
};
