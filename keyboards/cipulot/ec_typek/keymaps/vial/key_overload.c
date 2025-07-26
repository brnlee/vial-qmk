#include QMK_KEYBOARD_H
#include "keymap.h"
#include "layers.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool deleting_line;
    switch (keycode) {
        case KC_BSPC: {
            static uint16_t registered_key = KC_NO;
            if (record -> event.pressed) { // On key press.
                const uint8_t mods = get_mods();
                uint8_t shift_mods = mods & MOD_MASK_SHIFT;
                uint8_t gui_mods = mods & MOD_MASK_GUI;

                if ((gui_mods && gui_mods != MOD_MASK_GUI) || deleting_line) { // Single GUI key held, delete line
                    // Clear GUI to not interfere with the macro
                    del_mods(MOD_MASK_GUI);

                    // Delete line
                    tap_code(KC_END);
                    register_code(KC_LSFT);
                    tap_code(KC_HOME);
                    unregister_code(KC_LSFT);
                    tap_code(KC_BSPC);

                    deleting_line = true;
                    return false;
                } else if (shift_mods) { // At least one shift key is held.
                    registered_key = KC_DEL;
                    if (shift_mods != MOD_MASK_SHIFT) {
                        // If one Shift is held, cancel Shift so that a plain Delete is sent
                        del_mods(MOD_MASK_SHIFT);
                    }
                } else {
                    registered_key = KC_BSPC;
                }

                register_code(registered_key);
                set_mods(mods);
            } else { // On key release.
                unregister_code(registered_key);
            }
            return false;
        }
        case TGDF: // Toggle between Colemak and QWERTY default layers
            if (!record->event.pressed) { // On key release
                if (get_highest_layer(default_layer_state) == _COLEMAK) {
                    set_single_default_layer(_QWERTY);
                } else {
                    set_single_default_layer(_COLEMAK);
                }
                return false;
            }
    }
    
    deleting_line = false;
    return true;
}