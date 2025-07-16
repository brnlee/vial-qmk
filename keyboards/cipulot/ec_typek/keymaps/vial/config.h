/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0x00, 0x3A, 0xE4, 0xED, 0x10, 0xB5, 0xEE, 0x7F}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

#define DYNAMIC_KEYMAP_LAYER_COUNT 6

// --- ---------- ---
// --- Tri Layers ---
// --- ---------- ---
#define TRI_LAYER_LOWER_LAYER 2  // NAV
#define TRI_LAYER_UPPER_LAYER 3  // NUM
#define TRI_LAYER_ADJUST_LAYER 4 // SYM

// --- --------- ---
// --- Bootmagic ---
// --- --------- ---
#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 1

// --- ------------ ---
// --- Space Saving ---
// --- ------------ ---
#define LAYER_STATE_8BIT
#define NO_MUSIC_MODE
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD