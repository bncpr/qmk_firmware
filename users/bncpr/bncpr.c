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
    return process_record_keymap(keycode, record) && process_record_secrets(keycode, record);
}

#ifdef OLED_ENABLE
void oled_render_qwerty(void) {
    // clang-format off
    static const char PROGMEM querty[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,224,248,252, 30, 14,  7,  7,  7, 15, 30,254,252,224,  0,  0,  0,  7, 63,255,248,192,  0,  0,  0,192,248,255, 63,255,248,192,  0,  0,  0,192,248,255, 63,  7,  0,  0,255,255,255,135,135,135,135,135,135,135,135,  0,  0,252,254,255, 15,  7,  3,  3,  7, 15,255,254,252,  0,  0,  7,  7,  7,  7,255,255,255,  7,  7,  7,  7,  0,  0,  3,  7, 14, 28, 56,112,224,224,224,112, 56, 28, 14,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  7, 31, 63,120,112,224,224,236,252,120, 63,127,231,192,  0,  0,  0,  0,  1, 15,127,254,240,254,127, 15,  1,  0,  1, 15,127,254,240,254,127, 15,  1,  0,  0,  0,  0,255,255,255,227,227,227,227,227,227,227,227,  0,  0,255,255,255,  7, 14, 30, 62,126,255,247,227,193,  0,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
	oled_write_raw_P(querty, sizeof(querty));
    // clang-format on
}

void oled_render_colemak_dh(void) {
    // clang-format off
    static const char PROGMEM colemak_dh[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0,  0,  0,  0,  0,  0,
        0,  0,240,252,254, 15,  7,  7,  7, 15, 14, 12,  0,  0,240,248,254, 15,  7,  7,  7, 15,254,248,240,  0,  0,255,255,255,  0,  0,  0,  0,  0,  0, 0,  0,255,255,255,135,135,135,135,135,135,  0,  0, 0,  0,255,255,255,126,248,224,224,248,126,255,255,255,  0,  0,248,252,254, 15,  7,  3,  3,  7, 31,254,248,224,  0,  0,255,255,255,192,240,248,124, 30, 15,  7,  3,  0,  0,128,128,128,128,128,128,  0,  0,255,255,255,  7,  7,  7, 14, 30,252,248,  0,  0,255,255,255,128,128,128,128,255,255,255, 0,  0,  0,  0,  0,  0,
        0,  0, 15, 63,127,112,224,224,224,240,112, 48,  0,  0, 15, 63,127,240,224,224,224,240,127, 63, 15,  0,  0,255,255,255,224,224,224,224,224,224, 0,  0,255,255,255,227,227,227,227,227,227,  0,  0, 0,  0,255,255,255,  0,  0,  1,  1,  0,  0,255,255,255,  0,  0,255,255,255,  7,  7,  7,  7,  7,  7,255,255,255,  0,  0,255,255,255,  7, 15, 31, 60,120,240,224,192,  0,  0,  3,  3,  3,  3,  3,  3,  0,  0,255,255,255,224,224,224,112,120, 63, 31,  0,  0,255,255,255,  3,  3,  3,  3,255,255,255, 0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0,  0,  0,  0,  0,  0,
    };
	oled_write_raw_P(colemak_dh, sizeof(colemak_dh));
    // clang-format on
}
#endif
