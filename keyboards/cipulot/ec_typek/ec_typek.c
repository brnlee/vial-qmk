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

#include "ec_switch_matrix.h"
#include "quantum.h"
#include "layers.h"
#include "print.h"

void eeconfig_init_kb(void) {
    // Default values
    eeprom_ec_config.num.h                          = 0;
    eeprom_ec_config.num.s                          = 0;
    eeprom_ec_config.num.v                          = 60;
    eeprom_ec_config.num.enabled                    = true;
    eeprom_ec_config.caps.h                         = 0;
    eeprom_ec_config.caps.s                         = 0;
    eeprom_ec_config.caps.v                         = 60;
    eeprom_ec_config.caps.enabled                   = true;
    eeprom_ec_config.scroll.h                       = 0;
    eeprom_ec_config.scroll.s                       = 0;
    eeprom_ec_config.scroll.v                       = 60;
    eeprom_ec_config.scroll.enabled                 = true;
    eeprom_ec_config.actuation_mode                 = DEFAULT_ACTUATION_MODE;
    eeprom_ec_config.mode_0_actuation_threshold     = DEFAULT_MODE_0_ACTUATION_LEVEL;
    eeprom_ec_config.mode_0_release_threshold       = DEFAULT_MODE_0_RELEASE_LEVEL;
    eeprom_ec_config.mode_1_initial_deadzone_offset = DEFAULT_MODE_1_INITIAL_DEADZONE_OFFSET;
    eeprom_ec_config.mode_1_actuation_offset        = DEFAULT_MODE_1_ACTUATION_OFFSET;
    eeprom_ec_config.mode_1_release_offset          = DEFAULT_MODE_1_RELEASE_OFFSET;

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            eeprom_ec_config.bottoming_reading[row][col] = DEFAULT_BOTTOMING_READING;
        }
    }
    // Write default value to EEPROM now
    eeconfig_update_kb_datablock(&eeprom_ec_config, 0, EECONFIG_KB_DATA_SIZE);

    eeconfig_init_user();
}

// On Keyboard startup
void keyboard_post_init_kb(void) {
    // Read custom menu variables from memory
    eeconfig_read_kb_datablock(&eeprom_ec_config, 0, EECONFIG_KB_DATA_SIZE);

    // Set runtime values to EEPROM values
    ec_config.actuation_mode                 = eeprom_ec_config.actuation_mode;
    ec_config.mode_0_actuation_threshold     = eeprom_ec_config.mode_0_actuation_threshold;
    ec_config.mode_0_release_threshold       = eeprom_ec_config.mode_0_release_threshold;
    ec_config.mode_1_initial_deadzone_offset = eeprom_ec_config.mode_1_initial_deadzone_offset;
    ec_config.mode_1_actuation_offset        = eeprom_ec_config.mode_1_actuation_offset;
    ec_config.mode_1_release_offset          = eeprom_ec_config.mode_1_release_offset;
    ec_config.bottoming_calibration          = false;
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            ec_config.bottoming_calibration_starter[row][col]           = true;
            ec_config.bottoming_reading[row][col]                       = eeprom_ec_config.bottoming_reading[row][col];
            ec_config.rescaled_mode_0_actuation_threshold[row][col]     = rescale(ec_config.mode_0_actuation_threshold, 0, 1023, ec_config.noise_floor[row][col], eeprom_ec_config.bottoming_reading[row][col]);
            ec_config.rescaled_mode_0_release_threshold[row][col]       = rescale(ec_config.mode_0_release_threshold, 0, 1023, ec_config.noise_floor[row][col], eeprom_ec_config.bottoming_reading[row][col]);
            ec_config.rescaled_mode_1_initial_deadzone_offset[row][col] = rescale(ec_config.mode_1_initial_deadzone_offset, 0, 1023, ec_config.noise_floor[row][col], eeprom_ec_config.bottoming_reading[row][col]);
            ec_config.rescaled_mode_1_actuation_offset[row][col]        = rescale(ec_config.mode_1_actuation_offset, 0, 1023, ec_config.noise_floor[row][col], eeprom_ec_config.bottoming_reading[row][col]);
            ec_config.rescaled_mode_1_release_offset[row][col]          = rescale(ec_config.mode_1_release_offset, 0, 1023, ec_config.noise_floor[row][col], eeprom_ec_config.bottoming_reading[row][col]);
        }
    }

    // Set the RGB LEDs range that will be used for the effects
    rgblight_set_effect_range(3, 66);

    keyboard_post_init_user();
}

// This function is called when layers change
__attribute__((weak)) layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_sethsv_range(0, 0, 0, SCROLL_INDICATOR_INDEX, NUM_INDICATOR_INDEX + 1);

    switch(get_highest_layer(state)) {
        case _NAV:   
            set_indicator(NUM_INDICATOR_INDEX);
            break;
        case _NUM:   
            set_indicator(CAPS_INDICATOR_INDEX);
            break;
        case _SYM:
            set_indicator(NUM_INDICATOR_INDEX);
            set_indicator(CAPS_INDICATOR_INDEX);
            break;
        default:
            break;
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            set_indicator(SCROLL_INDICATOR_INDEX);
            break;
        default:
            break;
    }

    return state;
}

// INDICATOR CALLBACK ------------------------------------------------------------------------------
/* LED index to physical position
 *
 * LED2 | LED1 |  LED0
 * -----+------+--------
 * Num  | Caps | Scroll |
 */
bool set_indicator(uint8_t index) {
    switch (index) {
        case NUM_INDICATOR_INDEX:
            if (eeprom_ec_config.num.enabled) {
                rgblight_sethsv_at(eeprom_ec_config.num.h, eeprom_ec_config.num.s, eeprom_ec_config.num.v, index);
            } else {
                rgblight_sethsv_at(0, 0, 0, index);
            }
            break;
        case CAPS_INDICATOR_INDEX:
            if (eeprom_ec_config.caps.enabled) {
                rgblight_sethsv_at(eeprom_ec_config.caps.h, eeprom_ec_config.caps.s, eeprom_ec_config.caps.v, index);
            } else {
                rgblight_sethsv_at(0, 0, 0, index);
            }
            break;
        case SCROLL_INDICATOR_INDEX:
            if (eeprom_ec_config.scroll.enabled) {
                rgblight_sethsv_at(eeprom_ec_config.scroll.h, eeprom_ec_config.scroll.s, eeprom_ec_config.scroll.v, index);
            } else {
                rgblight_sethsv_at(0, 0, 0, index);
            }
            break;
        default:
            return false;
    }

    rgblight_set();
    return true;
}
