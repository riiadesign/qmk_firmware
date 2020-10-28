/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _DEFAULT,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  LAUNCHY  = SAFE_RANGE,
  CMDER,
  YAHARA,
  YSFTWRE,
  YEMAIL,
  GMAIL
};

#define SPCLOWER LT(_LOWER, KC_SPC)
#define ENTRAISE LT(_RAISE, KC_ENT)
#define CTLESC   LCTL_T(KC_ESC)
#define SFTDEL   RSFT_T(KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DEFAULT] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,     KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_BSLS,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
  CTLESC,  KC_A,    KC_S,    KC_D,    KC_F,     KC_G,     KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, SFTDEL,
  KC_CAPS, LAUNCHY, KC_LGUI, KC_LALT, SPCLOWER, SPCLOWER, ENTRAISE, ENTRAISE, KC_RALT, KC_RCTL, CMDER,   KC_DEL
),

[_LOWER] = LAYOUT_preonic_grid(
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  _______,
  _______, _______, _______, _______, _______, _______, _______, KC_GRV,  KC_BSLS, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_preonic_grid(
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, YAHARA,  YSFTWRE, YEMAIL,  GMAIL,   _______, _______, _______, KC_UP,   _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT,  KC_HOME, KC_END,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case LAUNCHY:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL(SS_LSFT(" ")));
            }
            break;
        case CMDER:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LCTRL(SS_LALT("`"))));
            }
            break;
        case YAHARA:
            if (record->event.pressed) {
                SEND_STRING("yahara");
            }
            break;
        case YSFTWRE:
            if (record->event.pressed) {
                SEND_STRING("yaharasoftware");
            }
            break;
        case YEMAIL:
            if (record->event.pressed) {
                SEND_STRING("agwilliam@yaharasoftware.com");
            }
            break;
        case GMAIL:
            if (record->event.pressed) {
                SEND_STRING("adamgwilliam@gmail.com");
            }
            break;
        }
    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
