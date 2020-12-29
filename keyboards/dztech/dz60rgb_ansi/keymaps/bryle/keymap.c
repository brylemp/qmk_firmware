#include QMK_KEYBOARD_H

bool is_first_br = false;
bool is_second_br = false;

enum custom_keycodes {
    WIN_MV = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case WIN_MV:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING(SS_DOWN(X_LSHIFT)); 
            SEND_STRING(SS_DOWN(X_LGUI)); 
            SEND_STRING(SS_TAP(X_RIGHT)); 
        } else {
            SEND_STRING(SS_UP(X_LSHIFT)); 
            SEND_STRING(SS_UP(X_LGUI)); 
        }
        break;
    }
    return true;
};

uint32_t layer_state_set_user(uint32_t state) {
  switch(biton32(state)) {
    case 1:
        is_first_br = true;
        is_second_br = false;
        break;
    case 2:
        is_first_br = false;
        is_second_br = true;
        break;
    default:
        is_first_br = false;
        is_second_br = false;
        break;
  }
  return state;
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//     case MO(2):
//         if (record->event.pressed) {
//             is_toggled_br = !is_toggled_br;
//         }
//         else{
//             is_toggled_br = !is_toggled_br;
//         }
//         break;
//     }
//     return true;
// };

void rgb_matrix_indicators_user(void) {
    if(rgb_matrix_is_enabled() == true){
        if(is_first_br == true){
            rgb_matrix_set_color(25, 0xFF, 0xFF, 0xFF);
            rgb_matrix_set_color(37, 0xFF, 0xFF, 0xFF);
            rgb_matrix_set_color(38, 0xFF, 0xFF, 0xFF);
            rgb_matrix_set_color(39, 0xFF, 0xFF, 0xFF);
        }
        else{
            rgb_matrix_enable();
        }
        if(is_second_br == true){
            rgb_matrix_set_color(2, 0xFF, 0xFF, 0xFF);
            rgb_matrix_set_color(1, 0xFF, 0xFF, 0xFF);
            rgb_matrix_set_color(0, 0xFF, 0xFF, 0xFF);
            rgb_matrix_set_color(16, 0xFF, 0xFF, 0xFF);
            rgb_matrix_set_color(15, 0xFF, 0xFF, 0xFF);
            rgb_matrix_set_color(14, 0xFF, 0xFF, 0xFF);
            rgb_matrix_set_color(30, 0xFF, 0xFF, 0xFF);
            rgb_matrix_set_color(29, 0xFF, 0xFF, 0xFF);
            rgb_matrix_set_color(28, 0xFF, 0xFF, 0xFF);
            rgb_matrix_set_color(41, 0xFF, 0xFF, 0xFF);
        }
        else{
            rgb_matrix_enable();
        }
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi(
        KC_GRV,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        MO(1),         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        KC_LCTL,        KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   MO(2),   KC_RCTL
    ),
    [1] = LAYOUT_60_ansi(
        KC_ESC , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        WIN_MV, KC_VOLD, KC_UP,   KC_VOLU, KC_PSCR, KC_SLCK, KC_PAUS, KC_P7, KC_P8,  KC_P9, _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS, KC_HOME, KC_PGUP, KC_P4, KC_P5, KC_P6, _______, _______,          _______,
        KC_LSFT,          KC_MEDIA_PLAY_PAUSE, KC_MUTE, KC_CAPS, KC_DEL, KC_END, KC_PGDN, KC_P1, KC_P2, KC_P3,   KC_P0,          _______,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                            _______, _______, _______, _______
    ),
    [2] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, RGB_TOG,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_HUI, RGB_MOD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_SAI,          RGB_RMOD,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          RGB_M_P,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    )
};


