/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0x37, 0x2A, 0x11, 0x37, 0x76, 0x76, 0x76, 0x7A}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 13 }

// --- ---------- ---
// --- Tri Layers ---
// --- ---------- ---
#define TRI_LAYER_LOWER_LAYER 2  // Nav
#define TRI_LAYER_UPPER_LAYER 3  // Num
#define TRI_LAYER_ADJUST_LAYER 4 // Sym

// --- ------------ ---
// --- Space Saving ---
// --- ------------ ---
#define LAYER_STATE_8BIT
#define NO_MUSIC_MODE

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
