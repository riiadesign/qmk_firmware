#include QMK_KEYBOARD_H

/* this keymap is to provide a basic keyboard layout for testing the matrix
 * for more practical and complicated keymap refer to other keymaps in the same folder
 */

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    LAUNCHY = SAFE_RANGE,
    CMDER,
    YAHARA,
    YSFTWRE,
    YEMAIL,
    GMAIL
};

#define CTLESC MT(MOD_LCTL, KC_ESC)
#define SFTDEL MT(MOD_RSFT, KC_DEL)
#define LWRSPC LT(_LOWER, KC_SPC)
#define RSEENT LT(_RAISE, KC_ENT)

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, KC_DEL,
    CTLESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,        KC_QUOT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,      SFTDEL,
    KC_NO,  LAUNCHY, KC_LGUI, KC_LALT,           LWRSPC,           RSEENT,           KC_RALT, KC_RCTRL, CMDER,   KC_NO
  ),

  [_LOWER] = LAYOUT(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN,    _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,          _______,
    _______,   _______, _______, _______, _______, _______, _______, KC_GRV,  KC_BSLS, _______, _______,        _______,
    _______, _______, _______, _______,       _______,      _______,                 _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______,
    _______,  YAHARA,  YSFTWRE, YEMAIL,  GMAIL,  _______, _______, _______, KC_UP, _______, _______,          _______,
    _______,   _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_HOME, KC_END,
    _______, _______, _______, _______,       _______,      _______,                 _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT(
       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______,
    _______, _______, _______, _______,       _______,      _______,                 _______, _______, _______, _______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LAUNCHY:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT(" ")));
        }
        break;
    case CMDER:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("`"))));
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
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
