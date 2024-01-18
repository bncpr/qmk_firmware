#pragma once

#include QMK_KEYBOARD_H

#ifdef OLDED_ENABLE
void oled_render_qwerty(void);
void oled_render_colemak_dh(void);
#endif // OLDED_ENABLE

#define MACRO_TIMER 10

enum custom_keycodes_user {
    SECRET_0_MACRO = SAFE_RANGE,
    SECRET_1_MACRO,
    SECRET_2_MACRO,
    SECRET_3_MACRO,
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
