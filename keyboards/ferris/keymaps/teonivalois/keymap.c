// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
  _QWERTY,
  _NUM,
  _NAV,
  _FUN
};

enum ferris_tap_dances {
  TD_SPC_TAB
};

/* QWERTY */
#define MY_SPC TD(TD_SPC_TAB)

#define MY_A LGUI_T(KC_A)
#define MY_S LALT_T(KC_S)
#define MY_D LCTL_T(KC_D)
#define MY_F LSFT_T(KC_F)

#define MY_J LSFT_T(KC_J)
#define MY_K RCTL_T(KC_K)
#define MY_L RALT_T(KC_L)
#define MY_SCLN RGUI_T(KC_SCLN)

#define MY_ESC LT(_NUM,KC_ESC)
#define MY_BSPC LT(_NAV,KC_BSPC)

/* NUM */
#define MY_1 LGUI_T(KC_1)
#define MY_2 LALT_T(KC_2)
#define MY_3 LCTL_T(KC_3)
#define MY_4 LSFT_T(KC_4)

#define MY_7 LSFT_T(KC_7)
#define MY_8 RCTL_T(KC_8)
#define MY_9 RALT_T(KC_9)
#define MY_0 RGUI_T(KC_0)

/* NAV */
#define MY_TAB LGUI_T(KC_TAB)
#define MY_VOLD LALT_T(KC_VOLD)
#define MY_VOLU LCTL_T(KC_VOLU)
#define MY_MUTE LSFT_T(KC_MUTE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* QWERTY */
    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    MY_A,     MY_S,     MY_D,     MY_F,     KC_G,                         KC_H,     MY_J,     MY_K,     MY_L,     MY_SCLN,
    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                         KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
                                            MY_ESC,   MY_SPC,   KC_ENT,   MY_BSPC
  ),

  [_NUM] = LAYOUT( /* [> NUM <] */
    KC_GRV,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  KC_HOME,  KC_END,   XXXXXXX,
    MY_1,     MY_2,     MY_3,     MY_4,     KC_5,                         KC_6,     MY_7,     MY_8,     MY_9,     MY_0,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            _______,  _______,  _______,  MO(_FUN)  
  ),

  [_NAV] = LAYOUT( /* [> NAV <] */
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                    KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  XXXXXXX,
    MY_TAB,   MY_VOLD,  MY_VOLU,  MY_MUTE,  KC_MPLY,                    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_QUOT,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSLS,
                                           MO(_FUN), KC_LGUI,  _______, _______  
  ),

  [_FUN] = LAYOUT( /* [> FUN <] */
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                      KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
    KC_F11,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F12,
                                            _______, XXXXXXX,  XXXXXXX, _______  
  )
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Space, twice for Tab
    [TD_SPC_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_TAB)
};
