/* Copyright 2021 AndrewFischer
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
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layers {
    _BL,
    _NV,
    _FN
};

// Defines the keycodes used by our macros in process_record_user

enum custom_keycodes {
    KC_DBL0 = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap _BL: (Base Layer) Default Layer
 * ,-------------------.
 * |----|----|----|----|
 * | 7  | 8  | 9  |    |
 * |----|----|----| +  |
 * | 4  | 5  | 6  |    |
 * |----|----|----|----|
 * | 1  | 2  | 3  |    |
 * |----|----|----| En |
 * | 0  |    | .  |    |
 * `-------------------'
 * ENC 1 *
 * ENC 2 -
 */
  [_BL] = LAYOUT(
    KC_P7,    KC_P8,    KC_P9,     KC_PPLS,
    KC_P4,    KC_P5,    KC_P6,     KC_PAST,
    KC_P1,    KC_P2,    KC_P3,	   KC_KP_MINUS,
    KC_P0,              KC_PDOT,   KC_PENT
  ),

/* Keymap _NV: Navigation layer
 * ,-------------------.
 * |INS |HOME|PGUP|    |
 * |----|----|----|----|
 * |DEL |END |PGDN|    |
 * |----|----|----|    |
 * |    |    |    |    |
 * |----|----|----|----|
 * |    | UP |    |    |
 * |----|----|----|    |
 * |LEFT|DOWN|RIGH|    |
 * `-------------------'
 */
  [_NV] = LAYOUT(
    KC_P7,    KC_P8,    KC_P9,     KC_PPLS,
    KC_P4,    KC_P5,    KC_P6,     KC_PAST,
    KC_P1,    KC_P2,    KC_P3,	   KC_KP_MINUS,
    KC_P0,              KC_PDOT,   KC_PENT
  ),

/* Keymap _FN: RGB Function Layer
 * ,-------------------.
 * |RMOD|RGBP|RTOG| FN |
 * |----|----|----|----|
 * |HUD |HUI |    |    |
 * |----|----|----|    |
 * |SAD |SAI |    |    |
 * |----|----|----|----|
 * |VAD |VAS |    |    |
 * |----|----|----|    |
 * |RST |    |    |    |
 * `-------------------'
 */
  [_FN] = LAYOUT(
    KC_P7,    KC_P8,    KC_P9,     KC_PPLS,
    KC_P4,    KC_P5,    KC_P6,     KC_PAST,
    KC_P1,    KC_P2,    KC_P3,	   KC_KP_MINUS,
    KC_P0,              KC_PDOT,   KC_PENT
  ),
};


#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;  // AutoPilot has horizontal display
}

void oled_task_user(void) {
  
  oled_write_P(PSTR("AutoPilot"), false);
  oled_write_ln_P(PSTR(" HDG: 270  ALT:10,000"), false);
}
#endif

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_AUDIO_VOL_UP);
        } else {
            tap_code(KC_AUDIO_VOL_DOWN);
        }
    }
    return true;
}

