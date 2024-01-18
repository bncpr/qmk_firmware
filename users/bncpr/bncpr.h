#pragma once

#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE
#include "features/oled.h"
#endif // OLDED_ENABLE

#define SECRET_MACRO_DELAY 10

enum custom_keycodes_user {
    SECRET_0_MACRO = SAFE_RANGE,
    SECRET_1_MACRO,
    SECRET_2_MACRO,
    SECRET_N_MACRO,
    SELWORD,
    ALTCASE,
    NEW_SAFE_RANGE,
};

#define DO_IF_PRESSED(keycode, expr) \
    case keycode:                    \
        if (record->event.pressed) { \
            expr;                    \
        }                            \
        return false;
