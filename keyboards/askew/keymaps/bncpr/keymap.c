#include "quantum.h"
#include QMK_KEYBOARD_H
#include "bncpr.h"
#ifdef OLED_SUGAR
#include "oled_sugar/oled_sugar.h"
#include "transactions.h"
#endif
#include "g/keymap_combo.h"

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
    _BUTTON,
    _ADJUST,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    DVORAK,
    CH_LANG,
};

#define TMUX_PRE LCTL(KC_B)
#define OSM_HYPR OSM(MOD_HYPR)

#define MEDIA_ESC LT(_MEDIA, KC_ESC)
#define NAV_SPC LT(_NAV, KC_SPC)
#define MOUSE_TAB LT(_MOUSE, KC_TAB)
#define SYM_ENT LT(_SYM, KC_ENT)
#define NUM_BSPC LT(_NUM, KC_BSPC)
#define FUN_DEL LT(_FUN, KC_DEL)
#define BUTT_T(key) LT(_BUTTON, key)
#define REDO C(KC_Y)
#define UNDO C(KC_Z)
#define CUT C(KC_X)
#define COPY C(KC_C)
#define PASTE C(KC_V)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_4(
        KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                            KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     CH_LANG,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        QK_REP,   GUI_T(KC_A), ALT_T(KC_S), CTL_T(KC_D), SFT_T(KC_F), ALL_T(KC_G),                ALL_T(KC_H),     RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_QUOT),  QK_REP,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  BUTT_T(KC_Z),     KC_X,     KC_C,     KC_V,     KC_B,                            KC_N,     KC_M,     KC_COMM,  KC_DOT,   BUTT_T(KC_SLSH),  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      OSM_HYPR, MEDIA_ESC, NAV_SPC, MOUSE_TAB,           SYM_ENT,  NUM_BSPC,  FUN_DEL,  QK_LEAD
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_COLEMAK_DH] = LAYOUT_split_3x6_4(
        KC_ESC,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,                            KC_J,      KC_L,    KC_U,     KC_Y,     KC_QUOT,  CH_LANG,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        QK_REP,   GUI_T(KC_A), ALT_T(KC_R), CTL_T(KC_S), SFT_T(KC_T), ALL_T(KC_G),                ALL_T(KC_M),     RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O),  QK_REP,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  BUTT_T(KC_Z),     KC_X,     KC_C,     KC_D,     KC_V,                            KC_K,     KC_H,     KC_COMM,  KC_DOT,   BUTT_T(KC_SLSH),  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      OSM_HYPR, MEDIA_ESC, NAV_SPC, MOUSE_TAB,           SYM_ENT,  NUM_BSPC,  FUN_DEL,  QK_LEAD
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_DVORAK] = LAYOUT_split_3x6_4(
        KC_ESC,   KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,                            KC_F,      KC_G,    KC_C,     KC_R,     KC_L,     CH_LANG,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  GUI_T(KC_A), ALT_T(KC_O), CTL_T(KC_E), SFT_T(KC_U), ALL_T(KC_I),         ALL_T(KC_D), RSFT_T(KC_H), RCTL_T(KC_T), RALT_T(KC_N), RGUI_T(KC_S),  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  BUTT_T(KC_SLSH),    KC_Q,     KC_J,     KC_K,     KC_X,                  KC_B,     KC_M,     KC_W,     KC_V,     BUTT_T(KC_Z),  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      OSM_HYPR, MEDIA_ESC, NAV_SPC, MOUSE_TAB,           SYM_ENT,  NUM_BSPC,  FUN_DEL,  QK_LEAD
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_GAME] = LAYOUT_split_3x6_4(
        XXXXXXX,  KC_T,     KC_Q,     KC_W,     KC_E,     KC_R,                            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,                            XXXXXXX,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_TAB,   KC_Z,     KC_X,     KC_C,     KC_V,                            XXXXXXX,  KC_SPC,   KC_ENT,   XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      TG(_GAME),XXXXXXX,  KC_LCTL,  KC_SPC,      _______,  _______,  _______,  _______
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_NAV] = LAYOUT_split_3x6_4(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         REDO,     PASTE,    COPY,     CUT,      UNDO,     XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,                         KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, CW_TOGG,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,MO(_ADJUST),XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_INS,   XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,     KC_ENT,   KC_BSPC,   KC_DEL,   XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_NUM] = LAYOUT_split_3x6_4(
        XXXXXXX,  KC_LBRC,  KC_7,     KC_8,     KC_9,     KC_RBRC,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_SCLN,  KC_4,     KC_5,     KC_6,     KC_EQL,                          XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_RALT,  KC_RGUI,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_BSLS,                         XXXXXXX,  KC_SPC,   KC_BSPC,  KC_ENT,   XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  KC_DOT,   KC_0,     KC_MINS,     XXXXXXX,  _______,  XXXXXXX,  XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_MOUSE] = LAYOUT_split_3x6_4(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         REDO,     PASTE,     COPY,    CUT,      UNDO,     XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,                         KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_BTN4,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  KC_BTN5,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,     KC_BTN2,  KC_BTN1,  KC_BTN3,  XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_SYM] = LAYOUT_split_3x6_4(
        XXXXXXX,  KC_LCBR,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RCBR,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_COLN,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_PLUS,                         XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_RALT,  KC_RGUI,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_PIPE,                         XXXXXXX,  KC_SPC,   KC_BSPC,  KC_ENT,   XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  KC_LPRN,  KC_RPRN,  KC_UNDS,     _______,  XXXXXXX,  XXXXXXX,  XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_MEDIA] = LAYOUT_split_3x6_4(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,                         KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  KC_MUTE,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,     KC_MSTP,  KC_MPLY,  KC_MUTE,  XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_FUN] = LAYOUT_split_3x6_4(
        XXXXXXX,  KC_F12,   KC_F7,    KC_F8,    KC_F9,    KC_PSCR,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_F11,   KC_F4,    KC_F5,    KC_F6,    XXXXXXX,                         XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_RALT,  KC_RGUI,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_F10,   KC_F1,    KC_F2,    KC_F3,    XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  KC_APP,   KC_SPC,   KC_TAB,      XXXXXXX,  XXXXXXX,  _______,  XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_BUTTON] = LAYOUT_split_3x6_4(
        XXXXXXX,  UNDO,     CUT,      COPY,     PASTE,    REDO,                             REDO,     PASTE,    COPY,     CUT,      UNDO,     XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                           -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_LGUI,  KC_LALT,  KC_LCTL,  OSM(MOD_LSFT),  XXXXXXX,                          XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_RALT,  KC_RGUI,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                           -------   -------   -------   -------   -------   -------
        XXXXXXX,  UNDO,     CUT,      COPY,     PASTE,    REDO,                             REDO,     PASTE,    COPY,     CUT,      UNDO,     XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                           -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
    //                                -------   -------   -------   -------       -------   -------   -------   -------
    ),
    [_ADJUST] = LAYOUT_split_3x6_4(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         XXXXXXX,  DT_DOWN,  DT_UP,    DT_PRNT,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         XXXXXXX,  QWERTY,   COLEMAK,  DVORAK,   XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         XXXXXXX,  TG(_GAME),XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
};
// clang-format on

// extern uint16_t keyCntr;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_SUGAR
    if (record->event.pressed) {
        keyCntr++;
        transaction_rpc_send(USER_SYNC_KEY_CNTR, sizeof(keyCntr), &keyCntr);
    }
#endif
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
        case CH_LANG:
            if (record->event.pressed) {
                tap_code16(LGUI(KC_SPACE));
            }
            return false;
    }
    return true;
}

#ifdef LEADER_ENABLE
void leader_end_user(void) {
    if (leader_sequence_three_keys(KC_G, KC_F, KC_P)) {
        SEND_STRING("git fetch -p" SS_TAP(X_ENTER));
    } else if (leader_sequence_three_keys(KC_G, KC_L, KC_G)) {
        SEND_STRING("git log --oneline --decorate --graph" SS_TAP(X_ENTER));
    } else if (leader_sequence_three_keys(KC_G, KC_P, KC_R)) {
        SEND_STRING("git pull --rebase --autostash");
    } else if (leader_sequence_three_keys(KC_G, KC_R, KC_H)) {
        SEND_STRING("git reset --hard");
    } else if (leader_sequence_three_keys(KC_G, KC_S, KC_S)) {
        SEND_STRING("git status -s" SS_TAP(X_ENTER));
    } else if (leader_sequence_three_keys(KC_G, KC_S, KC_T)) {
        SEND_STRING("git status" SS_TAP(X_ENTER));
    } else if (leader_sequence_two_keys(KC_G, KC_C)) {
        SEND_STRING("sudo git clean -xdf");
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

static void render_status(void) {
    static int last_code = _QWERTY;
    int cur_code = get_highest_layer(layer_state | default_layer_state);
    if (cur_code != last_code) {
        oled_clear();
        last_code = cur_code;
    }
    switch (cur_code) {
        case _QWERTY:
            oled_render_qwerty();
            break;
        case _COLEMAK_DH:
            oled_render_colemak_dh();
            break;
        case _DVORAK:
            oled_write_ln_P(PSTR("Layer: Dvorak"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("Layer: Game"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Layer: Navigation"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Layer: Numbers"), false);
            break;
        case _MOUSE:
            oled_write_ln_P(PSTR("Layer: Mouse"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Layer: Symbols"), false);
            break;
        case _MEDIA:
            oled_write_ln_P(PSTR("Layer: Media"), false);
            break;
        case _FUN:
            oled_write_ln_P(PSTR("Layer: Function"), false);
            break;
        case _BUTTON:
            oled_write_ln_P(PSTR("Layer: Button"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Layer: Adjust"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
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
