#include "alternate_case.h"

static bool is_active = false;
static bool is_upper = true;

bool process_alternate_case(uint16_t keycode, keyrecord_t *record, uint16_t altcase_keycode) {
    if (!record->event.pressed) {
        return true;
    }

    // Toggle alternate_case
    if (keycode == altcase_keycode) {
        is_active = !is_active;
        is_upper = true;
        return false;
    }

    if (!is_active) {
        return true;
    }

    // Avoid interfering with hotkeys.
    if (((get_mods() | get_oneshot_mods()))) {
        return true;
    }

    // Handle tap-hold keys.
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            if (record->tap.count == 0) {
                return true;
            }
            keycode &= 0xff;
    }

    switch (keycode) {
        case KC_A ... KC_Z:
            if (is_upper) {
                tap_code16(S(keycode));
                is_upper = false;
                return false;
            }
            is_upper = true;
            return true;

        case KC_BSPC:
            is_upper = !is_upper;
            return true;

        case KC_ESC:
            is_active = false;
            is_upper = true;
            return false;
    }

    return true;
}
