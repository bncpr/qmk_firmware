// Copyright 2021-2023 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file select_word.c
 * @brief Select word implementation
 *
 * For full documentation, see
 * <https://getreuer.info/posts/keyboards/select-word>
 */

#include "select_word.h"
#include "action.h"
#include "modifiers.h"
#include <stdint.h>

// Mac users, uncomment this line:
// #define MAC_HOTKEYS

// clang-format off
enum {
    STATE_NONE,        // No selection.
    STATE_WORD,        // Macro held with word(s) selected.
    STATE_LINE         // Macro held with multiple lines selected.
};
// clang-format on
static uint8_t state = STATE_NONE;

// Idle timeout timer to disable Select Word after a period of inactivity.
#if SELECT_WORD_TIMEOUT > 0
static uint16_t idle_timer = 0;

void select_word_task(void) {
    if (state && timer_expired(timer_read(), idle_timer)) {
        state = STATE_NONE;
    }
}
#endif // SELECT_WORD_TIMEOUT > 0

bool process_select_word(uint16_t keycode, keyrecord_t *record,
                         uint16_t up, uint16_t right, uint16_t down, uint16_t left) {
#if SELECT_WORD_TIMEOUT > 0
    idle_timer = record->event.time + SELECT_WORD_TIMEOUT;
#endif // SELECT_WORD_TIMEOUT > 0

    if (record->event.pressed && (keycode == left || keycode == right || keycode == up || keycode == down)) {
        if (keycode == left || keycode == right) {
            register_mods(MOD_BIT_LCTRL);
            if (state == STATE_NONE) {
                if (keycode == left) {
                    tap_code(KC_LEFT);
                    tap_code(KC_RIGHT);
                } else {
                    tap_code(KC_RIGHT);
                    tap_code(KC_LEFT);
                }
            }
            register_mods(MOD_BIT_LSHIFT);
            if (keycode == left) {
                tap_code(KC_LEFT);
            } else {
                tap_code(KC_RIGHT);
            }
            state = STATE_WORD;
            unregister_mods(MOD_BIT_LCTRL | MOD_BIT_LSHIFT);
        }
        if (keycode == up || keycode == down) {
            if (state == STATE_NONE) {
                if (keycode == up) {
                    tap_code(KC_END);
                } else {
                    tap_code(KC_HOME);
                }
            }
            register_mods(MOD_BIT_LSHIFT);
            if (state == STATE_NONE || state == STATE_WORD) {
                if (keycode == up) {
                    tap_code(KC_HOME);
                } else {
                    tap_code(KC_END);
                }
            } else {
                if (keycode == up) {
                    tap_code(KC_UP);
                } else {
                    tap_code(KC_DOWN);
                }
            }
            unregister_mods(MOD_BIT_LSHIFT);
            state = STATE_LINE;
        }

        return false;
    }

    // `keycode` was released, or another key was pressed.
    switch (state) {
        case STATE_WORD:
        case STATE_LINE:
            if (keycode == KC_ESC) {
                tap_code(KC_RGHT);
                state = STATE_NONE;
                return false;
            }
            return true;
        default:
            state = STATE_NONE;
    }

    return true;
}
