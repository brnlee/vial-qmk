#include QMK_KEYBOARD_H

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BSPC: {
            static uint16_t registered_key = KC_NO;
            if (record -> event.pressed) { // On key press.
                const uint8_t mods = get_mods();
                #ifndef NO_ACTION_ONESHOT
                uint8_t shift_mods = (mods | get_oneshot_mods()) & MOD_MASK_SHIFT;
                uint8_t gui_mods = (mods | get_oneshot_mods()) & MOD_MASK_GUI;
                #else // NO_ACTION_ONESHOT
                uint8_t shift_mods = mods & MOD_MASK_SHIFT;
                uint8_t gui_mods = mods & MOD_MASK_GUI;
                #endif

                if (gui_mods) { // At least one GUI key is held.
                    if (gui_mods != MOD_MASK_GUI) { // Single GUI key held, delete line
                        // Temporarily clear GUI to not interfere with the macro
                        #ifndef NO_ACTION_ONESHOT
                        del_oneshot_mods(MOD_MASK_GUI);
                        #endif // NO_ACTION_ONESHOT
                        unregister_mods(MOD_MASK_GUI);
                        
                        // Delete line
                        register_code(KC_LSFT);
                        tap_code(KC_HOME);
                        unregister_code(KC_LSFT);
                        tap_code(KC_BSPC);
                        
                        return false; // Prevent further processing
                    }
                    // For BOTH GUIs, we do nothing special. The code will fall through
                    // and register a normal Backspace
                } else if (shift_mods) { // At least one shift key is held.
                    registered_key = KC_DEL;

                    if (shift_mods != MOD_MASK_SHIFT) {
                        // If one Shift is held, cancel Shift so that a plain Delete is sent
                        #ifndef NO_ACTION_ONESHOT
                        del_oneshot_mods(MOD_MASK_SHIFT);
                        #endif // NO_ACTION_ONESHOT
                        unregister_mods(MOD_MASK_SHIFT);
                    }
                    // For both Shifts, we do nothing to the mods. This will result
                    // in Shift + Delete being sent.
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
            
    }
    return true;
}