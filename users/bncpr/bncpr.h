#pragma once
#include "quantum.h"

#ifdef OLED_ENABLE
#include "features/oled.h"
#endif // OLDED_ENABLE

#define SECRET_MACRO_DELAY 10

#define REDO C(KC_Y)
#define UNDO C(KC_Z)
#define CUT C(KC_X)
#define COPY C(KC_C)
#define PASTE C(KC_V)
#define ALT_TAB A(KC_TAB)
#define CH_LANG G(KC_SPACE)

enum custom_keycodes_user {
    SECRET_0_MACRO = SAFE_RANGE,
    SECRET_1_MACRO,
    SECRET_2_MACRO,
    SECRET_N_MACRO,
    SELRGHT,
    SELLEFT,
    SELUP,
    SELDOWN,
    PAREN,
    SQBRC,
    CBRC,
    QUOT,
    SQUOT,
    TRIAG,
    CA_PASTE,
    SPC_MIN,
    SPC_PLS,
    SPC_EQ,
    SPC_AST,
    SPC_LT,
    SPC_GT,
    SPC_M_E,
    SPC_P_E,
    SPC_E_E,
    SPC_N_E,
    SPC_LTE,
    SPC_GTE,
    WALRUS,
    N_BSPC3,
    N_BSPC4,
    SPC_COMMA,
    WORD_I,
    ALTCASE,
    NEW_SAFE_RANGE,
};

#define DO_IF_PRESSED(keycode, expr) \
    case keycode:                    \
        if (record->event.pressed) { \
            expr;                    \
        }                            \
        return false;
