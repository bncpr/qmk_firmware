#include "bncpr.h"
#include "oled_sugar/oled_sugar.h"
#include "transactions.h"
#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

enum layers {
    _QWERTY,
    _COLEMAK_DH,
    _GAME,
    _LOWER,
    _RAISE,
    _L2,
    _R2,
    _ADJUST,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    LOWER,
    RAISE,
    ALT_TAB,
};

#define TMUX_PREFIX LCTL(KC_B)
#define TMUX_PRE LCTL(KC_B)
#define OSM_HYPR OSM(MOD_HYPR)
#define RAISE_T(kc_code) LT(_RAISE, kc_code)
#define LOWER_T(kc_code) LT(_LOWER, kc_code)
#define ALTTTMUX LALT_T(TMUX_PREFIX)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_4(
        KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                            KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     ALT_TAB,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        ALTTTMUX, KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                            KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        KC_LGUI,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                            KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_UNDS,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                    OSM_HYPR, MO(_L2), LOWER_T(KC_TAB), CTL_T(KC_SPC),           SFT_T(KC_BSPC),  RAISE_T(KC_ENT),  MO(_R2),  QK_LEAD
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_COLEMAK_DH] = LAYOUT_split_3x6_4(
        KC_ESC,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,                            KC_J,      KC_L,    KC_U,     KC_Y,     KC_SCLN,  ALT_TAB,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        ALTTTMUX, KC_A,     KC_R,     KC_S,     KC_T,     KC_G,                            KC_M,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        KC_LGUI,  KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,                            KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_UNDS,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                    OSM_HYPR, MO(_L2), LOWER_T(KC_TAB), CTL_T(KC_SPC),           SFT_T(KC_BSPC),  RAISE_T(KC_ENT),  MO(_R2),  QK_LEAD
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
    [_LOWER] = LAYOUT_split_3x6_4(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         C(KC_X),  C(KC_C), S(C(KC_V)),C(KC_Z),  C(KC_Y),  KC_BSPC,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        KC_DEL,   KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,                         KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        KC_BSPC,  XXXXXXX,  XXXXXXX,  KC_ENT,   KC_SPC,   XXXXXXX,                         XXXXXXX,  KC_END,   KC_HOME,  KC_PGDN,  KC_PGUP,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      _______,  _______,  _______,  _______,     _______,  LT(_ADJUST, KC_ENT),  _______,  _______
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_RAISE] = LAYOUT_split_3x6_4(
        XXXXXXX,  KC_LBRC,  KC_7,     KC_8,     KC_9,     KC_RBRC,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_PLUS,  KC_4,     KC_5,     KC_6,     KC_EQL,                          XXXXXXX,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_SLSH,                         XXXXXXX,  KC_SPC,   KC_ENT,   TMUX_PRE, XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                           _______,  KC_DOT, LT(_ADJUST, KC_0), KC_MINS,           _______,  _______,  _______,  _______
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_L2] = LAYOUT_split_3x6_4(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        KC_DEL,   KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,                         KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_BTN4,  KC_BTN5,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      _______,  _______,  _______,  _______,     KC_BTN1,  KC_BTN2,  KC_BTN3,  KC_NO
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_R2] = LAYOUT_split_3x6_4(
        KC_TILD,  KC_LPRN,  KC_AMPR,  KC_ASTR,  KC_BSLS,  KC_RPRN,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        KC_PIPE,  KC_LCBR,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_RCBR,                         XXXXXXX,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_LABK,  KC_EXLM,  KC_AT,    KC_HASH,  KC_RABK,                         XXXXXXX,  KC_SPC,   KC_ENT,   XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  KC_UNDS,  KC_MINS,  KC_PLUS,     _______,  _______,  _______,  _______
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_ADJUST] = LAYOUT_split_3x6_4(
        XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                           KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  XXXXXXX,  DM_RSTP,  DM_REC2,  DM_REC1,  XXXXXXX,                         XXXXXXX,  QWERTY,   COLEMAK,  TO(_GAME),XXXXXXX,  KC_F12,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  DM_PLY2,  DM_PLY1,  XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                            XXXXXXX,  DB_TOGG,  _______,  XXXXXXX,               XXXXXXX,  _______,  QK_REBOOT, QK_BOOT
    //                                -------   -------   -------   -------      -------   -------   -------    -------
    ),
};
// clang-format on
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void keyboard_post_init_user(void) {
#ifdef OLED_ENABLE
    transaction_register_rpc(USER_SYNC_KEY_CNTR, user_sync_a_update_keyCntr_on_other_board);
#endif
}

extern uint16_t keyCntr;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
#ifdef OLED_ENABLE
    keyCntr++;
    transaction_rpc_send(USER_SYNC_KEY_CNTR, sizeof(keyCntr), &keyCntr);
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
        case CTL_T(KC_SPC):
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    tap_code(KC_MINS);
                    return false;
                }
            }
            return true;
        case SFT_T(KC_BSPC):
            if (record->tap.count && record->event.pressed) {
                if (get_mods() & MOD_MASK_CTRL) {
                    tap_code(KC_SPACE);
                    return false;
                }
            }
            return true;
        // replace shift + esc to shift + enter
        case KC_ESC:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    tap_code(KC_ENTER);
                    return false;
                }
            }
            return true;
        // modify the tap behaviour of LALT to send TMUX_PREFIX
        case ALTTTMUX:
            if (record->tap.count && record->event.pressed) {
                tap_code16(TMUX_PREFIX);
                return false;
            }
            return true;
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;
    }
    return true;
}

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
}

#define ALT_TAB_TIMEOUT 750
void matrix_scan_user(void) {
    if (is_alt_tab_active && timer_elapsed(alt_tab_timer) > ALT_TAB_TIMEOUT) {
        is_alt_tab_active = false;
        unregister_code(KC_LALT);
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Capture all mod-tap keycodes.
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            if (keycode == SFT_T(KC_BSPC) || keycode == CTL_T(KC_SPC)) {
                // Disable HOLD_ON_OTHER_KEY_PRESS for LCTL_T(KC_A)
                // aka enable IGNORE_MOD_TAP_INTERRUPT for LCTL_T(KC_A).
                return false;
            } else {
                // Enable HOLD_ON_OTHER_KEY_PRESS for every other mod-tap keycode.
                return true;
            }
        default:
            return false;
    }
}

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
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
        case _GAME:
            oled_write_P(PSTR("Layer: "), false);
            oled_write_P(PSTR("Game\n"), false);
            break;
        case _L2:
            oled_write_P(PSTR("Layer: "), false);
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        case _R2:
            oled_write_P(PSTR("Layer: "), false);
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Layer: "), false);
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Layer: "), false);
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Layer: "), false);
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Layer: "), false);
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_sugar();
    } else {
        render_status();
        // oled_render_logo();
        // oled_scroll_left();  // Turns on scrolling
    }
    return false;
}
#endif
