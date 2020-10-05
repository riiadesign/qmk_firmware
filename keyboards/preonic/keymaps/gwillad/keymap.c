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
  _QWERTY,
  _LOWER,
  _RAISE,
};

enum preonic_keycodes {
  LAUNCHY  = SAFE_RANGE,
  CMDER,
};

#define SPCLOWER LT(_LOWER, KC_SPC)
#define ENTRAISE LT(_RAISE, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |LAUNCH| GUI  | Alt  |  Lower Spc  |  Ent Raise  | Alt  | Ctrl | CMDER| DEL  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,     KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_GRV, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,     KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  KC_CAPS, LAUNCHY, KC_LGUI, KC_LALT, SPCLOWER, SPCLOWER, ENTRAISE, ENTRAISE, KC_RALT, KC_RCTL, CMDER,   KC_DEL   \
),

[_LOWER] = LAYOUT_preonic_grid( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSLS,  \
  _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  _______,  \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

[_RAISE] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F11,  KC_F12,  KC_BSLS,  \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______,  _______,  \
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
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
                SEND_STRING(SS_LSFT(SS_RSFT("`")));
            }
            break;
        }
    return true;
};
