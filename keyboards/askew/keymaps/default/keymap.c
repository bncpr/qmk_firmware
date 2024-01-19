#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _COLEMAK_DH,
    _DVORAK,
    _MEDIA,
    _NAV,
    _MOUSE,
    _SYM,
    _NUM,
    _FUN,
    _ADJUST,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    DVORAK,
};

#define OSM_HYP OSM(MOD_HYPR)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_GUI OSM(MOD_LGUI)

#define THUMBL3 LT(_MEDIA, KC_ESC)
#define THUMBL1 LT(_NAV, KC_SPC)
#define THUMBL2 LT(_MOUSE, KC_TAB)
#define THUMBR2 LT(_SYM, KC_ENT)
#define THUMBR1 LT(_NUM, KC_BSPC)
#define THUMBR3 LT(_FUN, KC_DEL)
#define F(key) ALL_T(key)
#define I(key) SFT_T(key)
#define M(key) CTL_T(key)
#define R(key) ALT_T(key)
#define P(key) GUI_T(key)

#define REDO C(KC_Y)
#define UNDO C(KC_Z)
#define CUT C(KC_X)
#define COPY C(KC_C)
#define PASTE C(KC_V)
#define ALT_TAB A(KC_TAB)
#define CH_LANG G(KC_SPACE)

// clang-format off
#define LAYOUT_default( \
       L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, \
       L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, \
       L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24  \
  ) \
LAYOUT_split_3x6_4( \
        ALT_TAB,  L01,      L02,      L03,      L04,      L05,                             R00,      R01,        R02,        R03,      R04,      CH_LANG, \
        KC_LBRC,  P(L11),   R(L12),   M(L13),   I(L14),   F(L15),                          F(R10),   I(R11),     M(R12),     R(R13),   P(R14),   KC_RBRC, \
        OSM_SFT,  L21,      L22,      L23,      L24,      L25,                             R20,      R21,        R22,        R23,      R24,      OSM_SFT, \
                                      QK_LEAD,  THUMBL3,  THUMBL1,  THUMBL2,     THUMBR2,  THUMBR1,  THUMBR3,    QK_LEAD \
    ) \

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_default(
                  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                            KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                            KC_H,     KC_J,     KC_K,     KC_L,     KC_QUOT,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                            KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_COLEMAK_DH] = LAYOUT_default(
                  KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,                            KC_J,     KC_L,     KC_U,     KC_Y,     KC_QUOT,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                  KC_A,     KC_R,     KC_S,     KC_T,     KC_G,                            KC_M,     KC_N,     KC_E,     KC_I,     KC_O,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                  KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,                            KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_DVORAK] = LAYOUT_default(
                  KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,                            KC_F,     KC_G,     KC_C,     KC_R,     KC_L,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                  KC_A,     KC_O,     KC_E,     KC_U,     KC_I,                            KC_D,     KC_H,     KC_T,     KC_N,     KC_S,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                  KC_SLSH,  KC_Q,     KC_J,     KC_K,     KC_X,                            KC_B,     KC_M,     KC_W,     KC_V,     KC_Z
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_NAV] = LAYOUT_split_3x6_4(
        XXXXXXX,  UNDO,     CUT,      COPY,     PASTE,    REDO,                            C(KC_F),  C(KC_D),  C(KC_U),  C(KC_B),  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  OSM_GUI,  OSM_ALT,  OSM_CTL,  OSM_SFT,  OSM_HYP,                         KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, CW_TOGG,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_DEL,   XXXXXXX,                         KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_INS,   XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,     KC_ENT,   LT(_ADJUST, KC_BSPC),   KC_DEL,   XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_NUM] = LAYOUT_split_3x6_4(
        XXXXXXX,  KC_LBRC,  KC_7,     KC_8,     KC_9,     KC_RBRC,                         REDO,     PASTE,    COPY,     CUT,      UNDO,     XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        KC_COMM,  KC_SCLN,  KC_4,     KC_5,     KC_6,     KC_EQL,                          OSM_HYP,  OSM_SFT,  OSM_CTL,  OSM_ALT,  OSM_GUI,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_BSLS,                         XXXXXXX,  KC_SPC,   KC_BSPC,  KC_ENT,   XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  KC_DOT,   LT(_ADJUST, KC_0),     KC_MINS,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_MOUSE] = LAYOUT_split_3x6_4(
        XXXXXXX,  UNDO,     CUT,      COPY,     PASTE,    REDO,                            REDO,     PASTE,    COPY,     CUT,      UNDO,     XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  OSM_GUI,  OSM_ALT,  OSM_CTL,  OSM_SFT,  OSM_HYP,                         KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_BTN4,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  KC_BTN5,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,     KC_BTN2,  KC_BTN1,  KC_BTN3,  XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_SYM] = LAYOUT_split_3x6_4(
        XXXXXXX,  KC_LCBR,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RCBR,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_COLN,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_PLUS,                         OSM_HYP,  OSM_SFT,  OSM_CTL,  OSM_ALT,  OSM_GUI,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_PIPE,                         XXXXXXX,  KC_SPC,   KC_BSPC,  KC_ENT,   XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  KC_LPRN,  KC_RPRN,  KC_UNDS,     _______,  XXXXXXX,  XXXXXXX,  XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_MEDIA] = LAYOUT_split_3x6_4(
        XXXXXXX,  UNDO,     CUT,      COPY,     PASTE,    REDO,                            REDO,     PASTE,    COPY,     CUT,      UNDO,     XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  OSM_GUI,  OSM_ALT,  OSM_CTL,  OSM_SFT,  OSM_HYP,                         KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  KC_MUTE,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,     KC_MSTP,  KC_MPLY,  KC_MUTE,  XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_FUN] = LAYOUT_split_3x6_4(
        XXXXXXX,  KC_F12,   KC_F7,    KC_F8,    KC_F9,    KC_PSCR,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_F11,   KC_F4,    KC_F5,    KC_F6,    XXXXXXX,                         OSM_HYP,  OSM_SFT,  OSM_CTL,  OSM_ALT,  OSM_GUI,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_F10,   KC_F1,    KC_F2,    KC_F3,    XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  KC_APP,   KC_SPC,   KC_TAB,      XXXXXXX,  XXXXXXX,  _______,  XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_ADJUST] = LAYOUT_split_3x6_4(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  OSM_GUI,  OSM_ALT,  OSM_CTL,  OSM_SFT,  OSM_HYP,                         XXXXXXX,  QWERTY,   COLEMAK,  DVORAK,   XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         QK_BOOT,  QK_MAKE,  DB_TOGG,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,     XXXXXXX,  _______,  XXXXXXX,  XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
};
// clang-format on

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK_DH);
            }
            return false;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
    }
    return true;
}

static void oled_render_logo(void) {
    static const char PROGMEM logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(logo, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_left()) {
        return OLED_ROTATION_180;
    }

    return rotation;
}

#define OLED_WRITE(str) oled_write_ln_P(PSTR(str), false);
#define OLED_WRITE_LAYER(layer, name) \
    case layer:                       \
        OLED_WRITE("Layer: " name);   \
        break;

static void render_status(void) {
    static int last_code = _QWERTY;
    int cur_code = get_highest_layer(layer_state | default_layer_state);
    if (cur_code != last_code) {
        oled_clear();
        last_code = cur_code;
    }
    switch (cur_code) {
        OLED_WRITE_LAYER(_QWERTY, "Qwerty");
        OLED_WRITE_LAYER(_COLEMAK_DH, "Colemak-DH");
        OLED_WRITE_LAYER(_DVORAK, "Dvorak");
        OLED_WRITE_LAYER(_NAV, "Navigation");
        OLED_WRITE_LAYER(_NUM, "Numbers");
        OLED_WRITE_LAYER(_MOUSE, "Mouse");
        OLED_WRITE_LAYER(_SYM, "Symbols");
        OLED_WRITE_LAYER(_MEDIA, "Media");
        OLED_WRITE_LAYER(_FUN, "Function");
        OLED_WRITE_LAYER(_ADJUST, "Adjust");
        default:
            OLED_WRITE("Unknown");
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        oled_render_logo();
        // oled_scroll_left();  // Turns on scrolling
    }
    return false;
}
