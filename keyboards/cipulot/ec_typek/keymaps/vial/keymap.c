/* Copyright 2023 Cipulot
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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
#include "keymap.h"
#include "layers.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_COLEMAK] = LAYOUT(
        KC_HOME, XXXXXXX, KC_1,        KC_2,        KC_3,        KC_4,        KC_5,    KC_6, KC_7,    KC_8,    KC_9,        KC_0,        KC_MINS,     KC_EQL,      KC_BSLS,  KC_GRV,
        KC_END,  XXXXXXX, KC_Q,        KC_W,        KC_F,        KC_P,        KC_B,          KC_MPRV, KC_J,    KC_L,        KC_U,        KC_Y,        KC_QUOT,     KC_SCLN,  XXXXXXX,
        KC_PGUP, KC_TAB,  GUI_T(KC_A), ALT_T(KC_R), CTL_T(KC_S), SFT_T(KC_T), KC_G,          KC_MNXT, KC_M,    RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), KC_ENTER,
        KC_PGDN, KC_ESC,  KC_X,        KC_C,        KC_D,        KC_V,        KC_Z,          KC_MPLY, KC_SLSH, KC_K,        KC_H,        KC_COMM,     KC_DOT,      MO(_NAV), XXXXXXX,
                 XXXXXXX,                           TL_LOWR,     KC_SPC,      XXXXXXX,       XXXXXXX, KC_BSPC, TL_UPPR,                                                      XXXXXXX
    ),
    [_QWERTY] = LAYOUT(
        _______, _______, _______,     _______,     _______,     _______,     _______, _______, _______, _______, _______,      _______,      _______,         _______,         _______, _______,
        _______, _______, KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,             _______, KC_Y,    KC_U,         KC_I,         KC_O,            KC_P,            XXXXXXX, _______,
        _______, _______, GUI_T(KC_A), ALT_T(KC_S), CTL_T(KC_D), SFT_T(KC_F), KC_G,             _______, KC_J,    RSFT_T(KC_K), RCTL_T(KC_L), RALT_T(KC_QUOT), RGUI_T(KC_SCLN), _______,
        _______, _______, KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,             _______, KC_SLSH, KC_N,         KC_M,         KC_COMM,         KC_DOT,          _______, XXXXXXX,
                 _______,                           _______,     _______,     XXXXXXX,          XXXXXXX, _______, _______,                                                               _______
    ),
    [_NAV] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, UKC_RTAB, UKC_PTAB, UKC_NTAB, XXXXXXX,          KC_VOLU, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   XXXXXXX, XXXXXXX,
        XXXXXXX, _______, KC_LGUI, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,          KC_VOLD, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX,
        XXXXXXX, _______, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,          KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
                 XXXXXXX,                              _______,  _______,          XXXXXXX,          XXXXXXX, _______, _______,                    XXXXXXX
    ),
    [_NUM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,            XXXXXXX, KC_F6,   KC_F7,       KC_F8,       KC_F9,       KC_F10,      KC_F11,  KC_F12,
        XXXXXXX, _______, GUI_T(KC_1), ALT_T(KC_2), CTL_T(KC_3), SFT_T(KC_4), KC_5,             XXXXXXX, KC_6,    SFT_T(KC_7), CTL_T(KC_8), ALT_T(KC_9), GUI_T(KC_0), _______,
        XXXXXXX, _______, XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,     _______,     _______,     _______, XXXXXXX,
                 XXXXXXX,                           _______,     _______,     XXXXXXX,          XXXXXXX, _______, _______,                                                     XXXXXXX
    ),
    [_SYM] = LAYOUT(
        QK_BOOT,      XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,
        XXXXXXX,      XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,          XXXXXXX, XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,
        DF(_COLEMAK), _______,  S(KC_MINS), UKC_LBRAKT, UKC_LBRACE, UKC_LPAREN, XXXXXXX,          XXXXXXX, XXXXXXX,   UKC_RPAREN, UKC_RBRACE, UKC_RBRAKT, KC_EQL,     _______,
        DF(_QWERTY),  _______,  KC_GRV,     S(KC_GRV),  KC_MINS,    XXXXXXX,    XXXXXXX,          XXXXXXX, XXXXXXX,   XXXXXXX,    S(KC_EQL),  KC_BSLS,    S(KC_BSLS), _______, XXXXXXX,
                      XXXXXXX,                          _______,    _______,    XXXXXXX,          XXXXXXX, _______,   _______,                                                 XXXXXXX
    )
};
