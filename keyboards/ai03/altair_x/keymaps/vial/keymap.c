/* Copyright 2024 ai03 Design Studio */
/* SPDX-License-Identifier: GPL-2.0-or-later */

#include "keymap.h"
#include "layers.h"
#include "caps_word.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT(
        KC_ESC,  KC_Q, KC_W, KC_F,    KC_P,    KC_B,     UKC_SSPART, UKC_SSWIN, KC_J,     KC_L,   KC_U,    KC_Y,   KC_SCLN, KC_DEL,
        KC_LCTL, KC_A, KC_R, KC_S,    KC_T,    KC_G,     UKC_KEBAB,  UKC_CAMEL, KC_M,     KC_N,   KC_E,    KC_I,   KC_O,    KC_QUOT,
        KC_LALT, KC_Z, KC_X, KC_C,    KC_D,    KC_V,     UKC_SNAKE,  UKC_CONST, KC_K,     KC_H,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                             KC_LGUI, KC_LSFT, MO(_NAV), KC_SPC,     KC_BSPC,   MO(_NUM), KC_ENT, KC_TAB
    ),

    [_QWERTY] = LAYOUT(
        _______, KC_Q, KC_W, KC_E,    KC_R,    KC_T,    _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______, KC_A, KC_S, KC_D,    KC_F,    KC_G,    _______, _______, KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, _______,
        _______, KC_Z, KC_X, KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_NAV] = LAYOUT(
        _______, _______, KC_MCTL,  UKC_PDESK, UKC_NDESK, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
        _______, _______, UKC_RTAB, UKC_PTAB,  UKC_NTAB,  _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, _______, _______,  UKC_PFIND, UKC_NFIND, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                    _______,   _______,   XXXXXXX, _______, _______, XXXXXXX, _______, _______
    ),

    [_NUM] = LAYOUT(
        _______, KC_F1, KC_F2,  KC_F3,   KC_F4,   _______, _______, _______, _______, KC_7,    KC_8,    KC_9, _______, _______,
        _______, KC_F5, KC_F6,  KC_F7,   KC_F8,   _______, _______, _______, _______, KC_4,    KC_5,    KC_6, _______, _______,
        _______, KC_F9, KC_F10, KC_F11,  KC_F12,  _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3, _______, _______,
                                _______, _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______ 
    ),

    [_SYM] = LAYOUT(
        _______, S(1),      S(2),       S(3),       S(4),       S(5),    _______, _______, S(6),    S(7),       S(8),       S(9),       S(0),       _______,
        _______, KC_GRV,    UKC_LBRAKT, UKC_LBRACE, UKC_LPAREN, _______, _______, _______, _______, UKC_RPAREN, UKC_RBRACE, UKC_RBRAKT, KC_BSLS,    _______,
        _______, S(KC_GRV), _______,    UKC_UNSCR,  KC_MINUS,   _______, _______, _______, _______, UKC_PLUS,   KC_EQUAL,   _______,    S(KC_BSLS), _______,
                                        _______,    _______,    XXXXXXX, _______, _______, XXXXXXX, _______,    _______
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case UKC_CONST:
            if (record->event.pressed) {
                toggle_caps_word_mode(CWMODE_CONSTANT_CASE);
                return false;
            }
            break;
        case UKC_SNAKE:
            if (record->event.pressed) {
                toggle_caps_word_space_sub(KC_UNDERSCORE);
                return false;
            }
            break;
        case UKC_KEBAB:
            if (record->event.pressed) {
                toggle_caps_word_space_sub(KC_MINUS);
                return false;
            }
            break;
        case UKC_CAMEL:
            if (record->event.pressed) {
                toggle_caps_word_mode(CWMODE_CAMEL_CASE);
                return false;
            }
            break;
    }
    return true;
}
