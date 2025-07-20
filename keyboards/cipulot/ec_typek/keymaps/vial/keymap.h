#pragma once
#include QMK_KEYBOARD_H

#define UKC_PTAB  C(S((KC_TAB))) // Previous tab
#define UKC_NTAB  C(KC_TAB)      // Next tab
#define UKC_RTAB  C(S(KC_T))     // Restore tab

#define UKC_LPAREN S(KC_9)       // (
#define UKC_RPAREN S(KC_0)       // )
#define UKC_LBRAKT KC_LBRC       // [
#define UKC_RBRAKT KC_RBRC       // ]
#define UKC_LBRACE S(KC_LBRC)    // {
#define UKC_RBRACE S(KC_RBRC)    // }