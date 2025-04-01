#pragma once
#include QMK_KEYBOARD_H

// ---------------------
// --- User Keycodes ---
// ---------------------

enum my_keycodes {
    UKC_CONST = SAFE_RANGE,      // CONSTANT_CASE
    UKC_SNAKE,                   // snakeCase
    UKC_KEBAB,                   // kebab-case
    UKC_CAMEL,                   // camelCase
};

#define UKC_PTAB  C(S((KC_TAB))) // Previous tab
#define UKC_NTAB  C(KC_TAB)      // Next tab
#define UKC_RTAB  C(S(KC_T))     // Restore tab

#define UKC_PDESK C(KC_LEFT)     // Previous desktop
#define UKC_NDESK C(KC_RIGHT)    // Next desktop

#define UKC_PFIND G(S(KC_G))     // Previous find result
#define UKC_NFIND G(KC_G)        // Next find result

#define UKC_LPAREN S(KC_9)       // (
#define UKC_RPAREN S(KC_0)       // )
#define UKC_LBRAKT KC_LBRC       // [
#define UKC_RBRAKT KC_RBRC       // ]
#define UKC_LBRACE S(KC_LBRC)    // {
#define UKC_RBRACE S(KC_RBRC)    // }

#define UKC_PLUS  S(KC_EQUAL)    // +
#define UKC_UNSCR S(KC_MINUS)    // _

#define UKC_SSPART LSG(KC_3)     // Capture a portion of the screen 
#define UKC_SSWIN  LSG(KC_4)     // Capture a window
