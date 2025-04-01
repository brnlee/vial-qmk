/* Copyright 2024 ai03 Design Studio */
/* SPDX-License-Identifier: GPL-2.0-or-later */

#include "keymap.h"
#include "layers.h"
#include "caps_word.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT(
        KC_ESC,  KC_Q, KC_W, KC_F,    KC_P,     KC_B,    UKC_SSPART, UKC_SSWIN, KC_J,     KC_L,     KC_U,    KC_Y,   KC_SCLN, KC_DEL,
        KC_LGUI, KC_A, KC_R, KC_S,    KC_T,     KC_G,    UKC_KEBAB,  UKC_CAMEL, KC_M,     KC_N,     KC_E,    KC_I,   KC_O,    KC_QUOT,
        KC_LCTL, KC_Z, KC_X, KC_C,    KC_D,     KC_V,    UKC_SNAKE,  UKC_CONST, KC_K,     KC_H,     KC_COMM, KC_DOT, KC_SLSH, KC_TAB,
                             KC_LALT, MO(_NAV), KC_LSFT, KC_SPC,     KC_BSPC,   KC_ENT,   MO(_NUM), KC_RSFT
    ),

    [_QWERTY] = LAYOUT(
        _______, KC_Q, KC_W, KC_E,    KC_R,    KC_T,    _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    _______,
        _______, KC_A, KC_S, KC_D,    KC_F,    KC_G,    _______, _______, KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, _______,
        _______, KC_Z, KC_X, KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_NAV] = LAYOUT(
        _______, XXXXXXX, KC_MCTL,  UKC_PDESK, UKC_NDESK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME,  KC_PGDN, KC_PGUP, KC_END,  _______,
        _______, XXXXXXX, UKC_RTAB, UKC_PTAB,  UKC_NTAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, XXXXXXX, XXXXXXX,  UKC_PFIND, UKC_NFIND, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                    _______,   XXXXXXX,   _______, _______, _______, _______, MO(_SYM), _______
    ),

    [_NUM] = LAYOUT(
        _______, KC_F1, KC_F2,  KC_F3,   KC_F4,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX,
        _______, KC_F5, KC_F6,  KC_F7,   KC_F8,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6, KC_0, XXXXXXX,
        _______, KC_F9, KC_F10, KC_F11,  KC_F12,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX,
                                _______, MO(_SYM), _______, _______, _______, _______, XXXXXXX, _______ 
    ),

    [_SYM] = LAYOUT(
        _______, S(KC_1),   S(KC_2),    S(KC_3),    S(KC_4),    S(KC_5), XXXXXXX,   XXXXXXX,   S(KC_6), S(KC_7),    S(KC_8),    S(KC_9),    S(KC_0),    XXXXXXX,
        _______, KC_GRV,    UKC_LBRAKT, UKC_LBRACE, UKC_LPAREN, XXXXXXX, OSL(_ADJ), OSL(_ADJ), XXXXXXX, UKC_RPAREN, UKC_RBRACE, UKC_RBRAKT, KC_BSLS,    XXXXXXX,
        _______, S(KC_GRV), XXXXXXX,    UKC_UNSCR,  KC_MINUS,   XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX, UKC_PLUS,   KC_EQUAL,   XXXXXXX,    S(KC_BSLS), XXXXXXX,
                                        _______,    XXXXXXX,    _______, _______,   _______,   _______, XXXXXXX,    _______
    ),


    [_ADJ] = LAYOUT(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                   _______, XXXXXXX, _______, _______, _______, _______, XXXXXXX, _______
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
