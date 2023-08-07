#include "quantum.h"
#include QMK_KEYBOARD_H
#include "bncpr.h"
#ifdef OLED_SUGAR
#include "oled_sugar/oled_sugar.h"
#include "transactions.h"
#endif
#include "g/keymap_combo.h"
#if __has_include("secrets.h")
#include "secrets.h"
#endif

enum layers {
    _QWERTY,
    _COLEMAK_DH,
    _DVORAK,
    _GAME,
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
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_4(
        KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                            KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     CH_LANG,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        KC_LBRC,  P(KC_A),  R(KC_S),  M(KC_D),  I(KC_F),  F(KC_G),                         F(KC_H),  I(KC_J),  M(KC_K),  R(KC_L),  P(KC_QUOT),KC_RBRC,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                            KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  THUMBL3,  THUMBL1,  THUMBL2,     THUMBR2,  THUMBR1,  THUMBR3,  XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_COLEMAK_DH] = LAYOUT_split_3x6_4(
        KC_ESC,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,                            KC_J,      KC_L,    KC_U,     KC_Y,     KC_QUOT,  CH_LANG,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        KC_LBRC,  P(KC_A),  R(KC_R),  M(KC_S),  I(KC_T),  F(KC_G),                         F(KC_M),  I(KC_N),  M(KC_E),  R(KC_I),  P(KC_O),  KC_RBRC,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,                            KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  THUMBL3,  THUMBL1,  THUMBL2,     THUMBR2,  THUMBR1,  THUMBR3,  XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_DVORAK] = LAYOUT_split_3x6_4(
        KC_ESC,   KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,                            KC_F,      KC_G,    KC_C,     KC_R,     KC_L,     CH_LANG,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  P(KC_A),  R(KC_O),  M(KC_E),  I(KC_U),  F(KC_I),                         F(KC_D),  I(KC_H),  M(KC_T),  R(KC_N),  P(KC_S),  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_SLSH,    KC_Q,     KC_J,     KC_K,     KC_X,                          KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,     XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  THUMBL3,  THUMBL1,  THUMBL2,     THUMBR2,  THUMBR1,  THUMBR3,  XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_GAME] = LAYOUT_split_3x6_4(
        XXXXXXX,  KC_T,     KC_Q,     KC_W,     KC_E,     KC_R,                            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  OSM_SFT,  KC_A,     KC_S,     KC_D,     KC_F,                            OSM_HYP,  OSM_SFT,  OSM_CTL,  OSM_ALT,  OSM_GUI,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_TAB,   KC_Z,     KC_X,     KC_C,     KC_V,                            XXXXXXX,  KC_SPC,   KC_ENT,   XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      TG(_GAME),XXXXXXX,  KC_LCTL,  KC_SPC,      _______,  _______,  _______,  _______
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_NAV] = LAYOUT_split_3x6_4(
        XXXXXXX,  UNDO,     CUT,      COPY,     PASTE,    REDO,                            REDO,     PASTE,    COPY,     CUT,      UNDO,     XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  OSM_GUI,  OSM_ALT,  OSM_CTL,  OSM_SFT,  OSM_HYP,                         KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, CW_TOGG,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  ALT_TAB,  XXXXXXX,                         KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_INS,   XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,     KC_ENT,   LT(_ADJUST, KC_BSPC),   KC_DEL,   XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_NUM] = LAYOUT_split_3x6_4(
        XXXXXXX,  KC_LBRC,  KC_7,     KC_8,     KC_9,     KC_RBRC,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_SCLN,  KC_4,     KC_5,     KC_6,     KC_EQL,                          OSM_HYP,  OSM_SFT,  OSM_CTL,  OSM_ALT,  OSM_GUI,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_BSLS,                         XXXXXXX,  KC_SPC,   KC_BSPC,  KC_ENT,   XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  KC_DOT,   LT(_ADJUST, KC_0),     KC_MINS,     XXXXXXX,  _______,  XXXXXXX,  XXXXXXX
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
    // [_FUN] = LAYOUT_split_3x6_4(
    //     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    // //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
    //     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    // //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
    //     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    // //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
    //                                   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
    // //                                -------   -------   -------   -------      -------   -------   -------   -------
    // ),
    [_ADJUST] = LAYOUT_split_3x6_4(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  OSM_GUI,  OSM_ALT,  OSM_CTL,  OSM_SFT,  OSM_HYP,                         TG(_GAME),QWERTY,   COLEMAK,  DVORAK,   XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         QK_BOOT,  QK_MAKE,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,     XXXXXXX,  _______,  XXXXXXX,  XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
};
// clang-format on

// extern uint16_t keyCntr;

#define DO_IF_PRESSED(keycode, expr) \
    case keycode:                    \
        if (record->event.pressed) { \
            expr;                    \
        }                            \
        return false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_SUGAR
    if (record->event.pressed) {
        keyCntr++;
        transaction_rpc_send(USER_SYNC_KEY_CNTR, sizeof(keyCntr), &keyCntr);
    }
#endif
    switch (keycode) {
        DO_IF_PRESSED(QWERTY, set_single_persistent_default_layer(_QWERTY));
        DO_IF_PRESSED(COLEMAK, set_single_persistent_default_layer(_COLEMAK_DH));
        DO_IF_PRESSED(DVORAK, set_single_persistent_default_layer(_DVORAK));
    }
    return true;
}

#ifdef LEADER_ENABLE
void leader_end_user(void) {
    // Git
    if (leader_sequence_three_keys(KC_G, KC_F, KC_P)) {
        SEND_STRING("git fetch -p\n");
    } else if (leader_sequence_three_keys(KC_G, KC_L, KC_G)) {
        SEND_STRING("git log --oneline --decorate --graph\n");
    } else if (leader_sequence_three_keys(KC_G, KC_P, KC_R)) {
        SEND_STRING("git pull --rebase --autostash");
    } else if (leader_sequence_three_keys(KC_G, KC_R, KC_H)) {
        SEND_STRING("git reset --hard");
    } else if (leader_sequence_three_keys(KC_G, KC_S, KC_S)) {
        SEND_STRING("git status -s\n");
    } else if (leader_sequence_three_keys(KC_G, KC_S, KC_T)) {
        SEND_STRING("git status\n");
    } else if (leader_sequence_two_keys(KC_G, KC_C)) {
        SEND_STRING("sudo git clean -xdf");
    }
    // Equations
    else if (leader_sequence_two_keys(KC_SPC, KC_M)) {
        SEND_STRING(" - ");
    } else if (leader_sequence_two_keys(KC_SPC, KC_P)) {
        SEND_STRING(" + ");
    } else if (leader_sequence_two_keys(KC_SPC, KC_E)) {
        SEND_STRING(" = ");
    } else if (leader_sequence_three_keys(KC_SPC, KC_E, KC_E)) {
        SEND_STRING(" == ");
    } else if (leader_sequence_three_keys(KC_SPC, KC_O, KC_R)) {
        SEND_STRING(" || ");
    } else if (leader_sequence_three_keys(KC_SPC, KC_A, KC_N)) {
        SEND_STRING(" && ");
    }
    // Javascript
    else if (leader_sequence_two_keys(KC_J, KC_A)) {
        SEND_STRING(" => ");
    } else if (leader_sequence_two_keys(KC_J, KC_E)) {
        SEND_STRING(" === ");
    } else if (leader_sequence_three_keys(KC_J, KC_N, KC_E)) {
        SEND_STRING(" !== ");
    }
    // Arrows
    else if (leader_sequence_two_keys(KC_A, KC_R)) {
        SEND_STRING("->");
    }
    // Secrets
    else if (leader_sequence_two_keys(KC_M, KC_M)) {
        send_string_P(secrets[0]);
    } else if (leader_sequence_two_keys(KC_M, KC_G)) {
        send_string_P(secrets[1]);
    } else if (leader_sequence_two_keys(KC_M, KC_P)) {
        send_string_P(secrets[2]);
    } else if (leader_sequence_three_keys(KC_M, KC_P, KC_N)) {
        send_string_P(secrets[5]);
    } else if (leader_sequence_two_keys(KC_S, KC_A)) {
        send_string_P(secrets[3]);
    } else if (leader_sequence_two_keys(KC_S, KC_B)) {
        send_string_P(secrets[4]);
    }
}
#endif /* ifdef LEADER_ENABLE */

// bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         // Capture all mod-tap keycodes.
//         case QK_MOD_TAP ... QK_MOD_TAP_MAX:
//             if (keycode == SFT_T(KC_BSPC) || keycode == CTL_T(KC_SPC)) {
//                 // Disable HOLD_ON_OTHER_KEY_PRESS for LCTL_T(KC_A)
//                 // aka enable IGNORE_MOD_TAP_INTERRUPT for LCTL_T(KC_A).
//                 return false;
//             } else {
//                 // Enable HOLD_ON_OTHER_KEY_PRESS for every other mod-tap keycode.
//                 return true;
//             }
//         default:
//             return false;
//     }
// }

#ifdef OLED_ENABLE

#ifdef OLED_SUGAR
void keyboard_post_init_user(void) {
    transaction_register_rpc(USER_SYNC_KEY_CNTR, user_sync_a_update_keyCntr_on_other_board);
}
#endif

static void oled_render_logo(void) {
    static const char PROGMEM logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(logo, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
#ifdef OLED_SUGAR
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
#endif
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
        OLED_WRITE_LAYER(_DVORAK, "Dvorak");
        OLED_WRITE_LAYER(_GAME, "Game");
        OLED_WRITE_LAYER(_NAV, "Navigation");
        OLED_WRITE_LAYER(_NUM, "Numbers");
        OLED_WRITE_LAYER(_MOUSE, "Mouse");
        OLED_WRITE_LAYER(_SYM, "Symbols");
        OLED_WRITE_LAYER(_MEDIA, "Media");
        OLED_WRITE_LAYER(_FUN, "Function");
        OLED_WRITE_LAYER(_ADJUST, "Adjust");
        case _QWERTY:
            oled_render_qwerty();
            break;
        case _COLEMAK_DH:
            oled_render_colemak_dh();
            break;
        default:
            OLED_WRITE("Unknown");
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
#ifdef OLED_SUGAR
        oled_sugar();
#else
        render_status();
#endif
    } else {
#ifdef OLED_SUGAR
        render_status();
#else
        oled_render_logo();
        // oled_scroll_left();  // Turns on scrolling
#endif
    }
    return false;
}
#endif
