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
    return process_record_keymap(keycode, record);
}

void matrix_scan_user(void) {
    alternate_case_task();
}
