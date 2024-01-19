#include "bncpr.h"
#include "features/alternate_case.h"
#include "features/select_word.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
};

__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    return true;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_select_word(keycode, record, SELWORD)) {
        return false;
    }
    if (!process_alternate_case(keycode, record, ALTCASE)) {
        return false;
    }
    if (!process_record_secrets(keycode, record)) {
        return false;
    }

    const uint8_t mods = get_mods();
    const uint8_t one_shot_mods = get_oneshot_mods();

    switch (keycode) {
        DO_IF_PRESSED(CA_PASTE, tap_code16(C(KC_A)); tap_code16(C(KC_V)));
        DO_IF_PRESSED(N_BSPC3, tap_code(KC_BSPC); tap_code(KC_BSPC); tap_code(KC_BSPC));
        DO_IF_PRESSED(N_BSPC4, tap_code(KC_BSPC); tap_code(KC_BSPC); tap_code(KC_BSPC); tap_code(KC_BSPC));
        DO_IF_PRESSED(PAREN, SEND_STRING("()" SS_TAP(X_LEFT)));
        DO_IF_PRESSED(SQBRC, SEND_STRING("[]" SS_TAP(X_LEFT)));
        DO_IF_PRESSED(CBRC, SEND_STRING("{}" SS_TAP(X_LEFT)));
        DO_IF_PRESSED(QUOT, SEND_STRING("\"\"" SS_TAP(X_LEFT)));
        DO_IF_PRESSED(SQUOT, SEND_STRING("''" SS_TAP(X_LEFT)));
        DO_IF_PRESSED(TRIAG, SEND_STRING("<>" SS_TAP(X_LEFT)));
        DO_IF_PRESSED(SPC_MIN, SEND_STRING(" - "));
        DO_IF_PRESSED(SPC_PLS, SEND_STRING(" + "));
        DO_IF_PRESSED(SPC_EQ, SEND_STRING(" = "));
        DO_IF_PRESSED(SPC_AST, SEND_STRING(" * "));
        DO_IF_PRESSED(SPC_LT, SEND_STRING(" < "));
        DO_IF_PRESSED(SPC_GT, SEND_STRING(" > "));
        DO_IF_PRESSED(SPC_M_E, SEND_STRING(" -= "));
        DO_IF_PRESSED(SPC_P_E, SEND_STRING(" += "));
        DO_IF_PRESSED(SPC_E_E, SEND_STRING(" == "));
        DO_IF_PRESSED(SPC_N_E, SEND_STRING(" != "));
        DO_IF_PRESSED(SPC_LTE, SEND_STRING(" <= "));
        DO_IF_PRESSED(SPC_GTE, SEND_STRING(" >= "));
        DO_IF_PRESSED(WALRUS, SEND_STRING(" := "));
        DO_IF_PRESSED(SPC_COMMA, SEND_STRING(", " SS_TAP(X_LEFT) SS_TAP(X_LEFT)));
        DO_IF_PRESSED(WORD_I, SEND_STRING("I "));
        case KC_PGDN:
            if (record->event.pressed) {
                clear_oneshot_mods();
                unregister_mods(mods);
                if ((mods | one_shot_mods) & MOD_MASK_SHIFT) {
                    tap_code16(C(KC_D));
                    register_mods(mods);
                    return false;
                }
                register_mods(mods);
            }
            return true;
        case KC_PGUP:
            if (record->event.pressed) {
                clear_oneshot_mods();
                unregister_mods(mods);
                if ((mods | one_shot_mods) & MOD_MASK_SHIFT) {
                    tap_code16(C(KC_U));
                    register_mods(mods);
                    return false;
                }
                register_mods(mods);
            }
            return true;
    }
    return process_record_keymap(keycode, record);
}

void matrix_scan_user(void) {
    alternate_case_task();
}
