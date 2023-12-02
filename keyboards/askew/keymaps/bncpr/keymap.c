#include "quantum.h"
#include QMK_KEYBOARD_H
#include "bncpr.h"
#ifdef OLED_SUGAR
#include "oled_sugar/oled_sugar.h"
#include "transactions.h"
#endif
#include "keymap_steno.h"

enum layers {
    _QWERTY,
    _COLEMAK_DH,
    _DVORAK,
    _PLOVER,
    _GAME,
    _MEDIA,
    _NAV,
    _MOUSE,
    _SYM,
    _CODE1,
    _CODE2,
    _NUM,
    _FUN,
    _ADJUST,
};

enum custom_keycodes {
    QWERTY = NEW_SAFE_RANGE,
    COLEMAK,
    DVORAK,
    PAREN_MACRO,
    SQBRC_MACRO,
    CBRC_MACRO,
    QUOT_MACRO,
    SQUOT_MACRO,
    TRIAG_MACRO,
    CA_PASTE_MACRO,
    SPC_MINS_MACRO,
    SPC_PLS_MACRO,
    SPC_EQ_MACRO,
    SPC_AST_MACRO,
    SPC_LT_MACRO,
    SPC_GT_MACRO,
    SPC_MINS_EQ_MACRO,
    SPC_PLS_EQ_MACRO,
    SPC_EQ_EQ_MACRO,
    SPC_NOT_EQ_MACRO,
    SPC_LTE_MACRO,
    SPC_GTE_MACRO,
    WALRUS_MACRO,
    SPC_COMMA_MACRO,
    WORD_I_MACRO,
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
#define CODE1_T(key) LT(_CODE1, key)
#define CODE2_T(key) LT(_CODE2, key)
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
        ALT_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                            KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     CH_LANG,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        KC_LBRC,  P(KC_A),  R(KC_S),  M(KC_D),  I(KC_F),  F(KC_G),                         F(KC_H),  I(KC_J),  M(KC_K),  R(KC_L),  P(KC_QUOT),KC_RBRC,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        OSM_SFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                            KC_N,     CODE1_T(KC_M),     CODE2_T(KC_COMM),  KC_DOT,   KC_SLSH,  OSM_SFT,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      QK_LEAD,  THUMBL3,  THUMBL1,  THUMBL2,     THUMBR2,  THUMBR1,  THUMBR3,  QK_LEAD
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_COLEMAK_DH] = LAYOUT_split_3x6_4(
        ALT_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,                            KC_J,      KC_L,    KC_U,     KC_Y,     KC_QUOT,  CH_LANG,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        KC_LBRC,  P(KC_A),  R(KC_R),  M(KC_S),  I(KC_T),  F(KC_G),                         F(KC_M),  I(KC_N),  M(KC_E),  R(KC_I),  P(KC_O),  KC_RBRC,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        OSM_SFT,  KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,                            KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,  OSM_SFT,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      QK_LEAD,  THUMBL3,  THUMBL1,  THUMBL2,     THUMBR2,  THUMBR1,  THUMBR3,  QK_LEAD
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_DVORAK] = LAYOUT_split_3x6_4(
        ALT_TAB,   KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,                            KC_F,      KC_G,    KC_C,     KC_R,     KC_L,     CH_LANG,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  P(KC_A),  R(KC_O),  M(KC_E),  I(KC_U),  F(KC_I),                         F(KC_D),  I(KC_H),  M(KC_T),  R(KC_N),  P(KC_S),  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  KC_SLSH,    KC_Q,     KC_J,     KC_K,     KC_X,                          KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,     XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  THUMBL3,  THUMBL1,  THUMBL2,     THUMBR2,  THUMBR1,  THUMBR3,  XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_GAME] = LAYOUT_split_3x6_4(
        KC_ESC,   KC_T,     KC_Q,     KC_W,     KC_E,     KC_R,                            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        KC_I,     KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,                            OSM_HYP,  OSM_SFT,  OSM_CTL,  OSM_ALT,  OSM_GUI,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        KC_M,     KC_TAB,   KC_Z,     KC_X,     KC_C,     KC_V,                            KC_B,     KC_SPC,   KC_ENT,   XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                     TG(_GAME), KC_G,     KC_LCTL,  KC_SPC,      _______,  _______,  _______,  _______
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
// [_PLOVER] = LAYOUT_planck_grid(
//   STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC ,
//   STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR ,
//   XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR ,
//   EXT_PLV, XXXXXXX, XXXXXXX, STN_A,   STN_O,   XXXXXXX, XXXXXXX, STN_E,   STN_U,   STN_PWR, STN_RE1, STN_RE2
// ),
    [_PLOVER] = LAYOUT_split_3x6_4(
        STN_N1,   STN_N2,   STN_N3,   STN_N4,   STN_N5,   STN_N6,                          STN_N7,   STN_N8,   STN_N9,   STN_NA,   STN_NB,   STN_NC,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        STN_FN,   STN_S1,   STN_TL,   STN_PL,   STN_HL,   STN_ST1,                         STN_ST3,  STN_FR,   STN_PR,   STN_LR,   STN_TR,   STN_DR,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  STN_S2,   STN_KL,   STN_WL,   STN_RL,   STN_ST2,                         STN_ST4,  STN_RR,   STN_BR,   STN_GR,   STN_SR,   STN_ZR,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                    TG(_PLOVER),STN_PWR,  STN_A,    STN_O,       STN_E,    STN_U,    STN_RE1,  STN_RE2
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
    [_CODE1] = LAYOUT_split_3x6_4(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  SPC_AST_MACRO,  SPC_EQ_MACRO,  SPC_PLS_MACRO,  SPC_MINS_MACRO,  XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  SPC_GT_MACRO,  SPC_LT_MACRO,  XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
    [_CODE2] = LAYOUT_split_3x6_4(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  WALRUS_MACRO,  XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  SPC_NOT_EQ_MACRO,  SPC_EQ_EQ_MACRO,  SPC_PLS_EQ_MACRO,  SPC_MINS_EQ_MACRO,  XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  SPC_GTE_MACRO,  SPC_LTE_MACRO,  XXXXXXX,                         XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
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
        XXXXXXX,  OSM_GUI,  OSM_ALT,  OSM_CTL,  OSM_SFT,  OSM_HYP,                         TG(_GAME),QWERTY,   COLEMAK,  DVORAK, TG(_PLOVER),XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         QK_BOOT,  QK_MAKE,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //  -------   -------   -------   -------   -------   -------                          -------   -------   -------   -------   -------   -------
                                      XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,     XXXXXXX,  _______,  XXXXXXX,  XXXXXXX
    //                                -------   -------   -------   -------      -------   -------   -------   -------
    ),
};
// clang-format on

// extern uint16_t keyCntr;

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
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
        DO_IF_PRESSED(PAREN_MACRO, SEND_STRING("()" SS_TAP(X_LEFT)));
        DO_IF_PRESSED(SQBRC_MACRO, SEND_STRING("[]" SS_TAP(X_LEFT)));
        DO_IF_PRESSED(CBRC_MACRO, SEND_STRING("{}" SS_TAP(X_LEFT)));
        DO_IF_PRESSED(QUOT_MACRO, SEND_STRING("\"\"" SS_TAP(X_LEFT)));
        DO_IF_PRESSED(SQUOT_MACRO, SEND_STRING("''" SS_TAP(X_LEFT)));
        DO_IF_PRESSED(TRIAG_MACRO, SEND_STRING("<>" SS_TAP(X_LEFT)));
        DO_IF_PRESSED(CA_PASTE_MACRO, tap_code16(C(KC_A)); tap_code16(PASTE));
        DO_IF_PRESSED(SPC_MINS_MACRO, SEND_STRING(" - "));
        DO_IF_PRESSED(SPC_PLS_MACRO, SEND_STRING(" + "));
        DO_IF_PRESSED(SPC_EQ_MACRO, SEND_STRING(" = "));
        DO_IF_PRESSED(SPC_AST_MACRO, SEND_STRING(" * "));
        DO_IF_PRESSED(SPC_LT_MACRO, SEND_STRING(" < "));
        DO_IF_PRESSED(SPC_GT_MACRO, SEND_STRING(" > "));
        DO_IF_PRESSED(SPC_MINS_EQ_MACRO, SEND_STRING(" -= "));
        DO_IF_PRESSED(SPC_PLS_EQ_MACRO, SEND_STRING(" += "));
        DO_IF_PRESSED(SPC_EQ_EQ_MACRO, SEND_STRING(" == "));
        DO_IF_PRESSED(SPC_NOT_EQ_MACRO, SEND_STRING(" != "));
        DO_IF_PRESSED(SPC_LTE_MACRO, SEND_STRING(" <= "));
        DO_IF_PRESSED(SPC_GTE_MACRO, SEND_STRING(" >= "));
        DO_IF_PRESSED(WALRUS_MACRO, SEND_STRING(" := "));
        DO_IF_PRESSED(SPC_COMMA_MACRO, SEND_STRING(", " SS_TAP(X_LEFT) SS_TAP(X_LEFT)));
        DO_IF_PRESSED(WORD_I_MACRO, SEND_STRING("I "));
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
}
#endif /* ifdef LEADER_ENABLE */

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
        OLED_WRITE_LAYER(_PLOVER, "Plover");
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

#ifdef COMBO_ENABLE

enum combos {
    IM_R_COMBO,   // Index + Middle Right Hand
    IT1_L_COMBO,  // Index + Thumb1 Left Hand
    IT1_R_COMBO,  // Index + Thumb1 Right Hand
    IT2_L_COMBO,  // Index + Thumb2 Left Hand
    MT1_L_COMBO,  // Middle + Thumb1 Left Hand
    MT2_L_COMBO,  // Middle + Thumb2 Left Hand
    RT1_L_COMBO,  // Ring + Thumb1 Left Hand
    RT2_L_COMBO,  // Ring + Thumb2 Left Hand
    PT1_L_COMBO,  // Pinky + Thumb1 Left Hand
    PT2_L_COMBO,  // Pinky + Thumb2 Left Hand
    IDT1_L_COMBO, // IndexDown + Thumb1 Left Hand
    IDT2_L_COMBO, // IndexDown + Thumb2 Left Hand
    MDT1_L_COMBO, // MiddleDown + Thumb1 Left Hand
    MDT2_L_COMBO, // MiddleDown + Thumb2 Left Hand
    MR_R_COMBO,   // Middle + Ring Right Hand
    MR_L_COMBO,   // Middle + Ring Right Hand
    RP_R_COMBO,   // Ring + Pinky Right Hand
    RP_L_COMBO,   // Ring + Pinky Left Hand
    ID_R_COMBO,   // Index Down Right Hand
    FU_R_COMBO,   // Far Up Right Hand
    FD_R_COMBO,   // Far Down Right Hand
    IU_R_COMBO,   // Index Up Right Hand
    MU_R_COMBO,   // Middle Up Right Hand
    RU_R_COMBO,   // Ring Up Right Hand
    PU_R_COMBO,   // Pinky Up Right Hand
    ID_L_COMBO,   // Index Down Left Hand
    FU_L_COMBO,   // Far Up Left Hand
    FD_L_COMBO,   // Far Down Left Hand
    IU_L_COMBO,   // Index Up Left Hand
    MU_L_COMBO,   // Middle Up Left Hand
    RU_L_COMBO,   // Ring Up Left Hand
    PU_L_COMBO,   // Pinky Up Left Hand
    WORD_I_COMBO,
    SPC_COMMA_COMBO,
    THUMBL_COMBO,
    THUMBR_COMBO,
    THUMBR_SYM_COMBO,
    SHIFT_PASTE_COMBO,
    PAREN_COMBO,
    SQBRC_COMBO,
    CBRC_COMBO,
    QUOTE_COMBO,
    SQUOTE_COMBO,
    TRIAG_COMBO,
    CA_PASTE_COMBO,
    SECRET_0_COMBO,
    SECRET_1_COMBO,
    SECRET_2_COMBO,
    SECRET_3_COMBO,
};

const uint16_t PROGMEM im_r_combo[] = {I(KC_J), M(KC_K), COMBO_END};
const uint16_t PROGMEM it1_l_combo[] = {THUMBL1, I(KC_F), COMBO_END};
const uint16_t PROGMEM it1_r_combo[] = {THUMBR1, I(KC_J), COMBO_END};
const uint16_t PROGMEM it2_l_combo[] = {THUMBL2, I(KC_F), COMBO_END};
const uint16_t PROGMEM mt1_l_combo[] = {THUMBL1, M(KC_D), COMBO_END};
const uint16_t PROGMEM mt2_l_combo[] = {THUMBL2, M(KC_D), COMBO_END};
const uint16_t PROGMEM rt1_l_combo[] = {THUMBL1, R(KC_S), COMBO_END};
const uint16_t PROGMEM rt2_l_combo[] = {THUMBL2, R(KC_S), COMBO_END};
const uint16_t PROGMEM pt1_l_combo[] = {THUMBL1, P(KC_A), COMBO_END};
const uint16_t PROGMEM pt2_l_combo[] = {THUMBL2, P(KC_A), COMBO_END};
const uint16_t PROGMEM idt1_l_combo[] = {THUMBL1, KC_V, COMBO_END};
const uint16_t PROGMEM idt2_l_combo[] = {THUMBL2, KC_V, COMBO_END};
const uint16_t PROGMEM mdt1_l_combo[] = {THUMBL1, KC_C, COMBO_END};
const uint16_t PROGMEM mdt2_l_combo[] = {THUMBL2, KC_C, COMBO_END};
const uint16_t PROGMEM word_i_combo[] = {THUMBL1, KC_I, COMBO_END};
const uint16_t PROGMEM spc_comma_combo[] = {THUMBL1, KC_COMMA, COMBO_END};
const uint16_t PROGMEM mr_r_combo[] = {M(KC_K), R(KC_L), COMBO_END};
const uint16_t PROGMEM mr_l_combo[] = {M(KC_D), R(KC_S), COMBO_END};
const uint16_t PROGMEM rp_r_combo[] = {R(KC_L), P(KC_QUOT), COMBO_END};
const uint16_t PROGMEM rp_l_combo[] = {R(KC_S), P(KC_A), COMBO_END};
const uint16_t PROGMEM id_r_combo[] = {I(KC_J), KC_M, COMBO_END};
const uint16_t PROGMEM id_l_combo[] = {I(KC_F), KC_V, COMBO_END};
const uint16_t PROGMEM fu_l_combo[] = {F(KC_G), KC_T, COMBO_END};
const uint16_t PROGMEM fd_l_combo[] = {F(KC_G), KC_B, COMBO_END};
const uint16_t PROGMEM iu_l_combo[] = {I(KC_F), KC_R, COMBO_END};
const uint16_t PROGMEM mu_l_combo[] = {M(KC_D), KC_E, COMBO_END};
const uint16_t PROGMEM ru_l_combo[] = {R(KC_S), KC_W, COMBO_END};
const uint16_t PROGMEM pu_l_combo[] = {P(KC_A), KC_Q, COMBO_END};
const uint16_t PROGMEM fu_r_combo[] = {F(KC_H), KC_Y, COMBO_END};
const uint16_t PROGMEM fd_r_combo[] = {F(KC_H), KC_N, COMBO_END};
const uint16_t PROGMEM iu_r_combo[] = {I(KC_J), KC_U, COMBO_END};
const uint16_t PROGMEM mu_r_combo[] = {M(KC_K), KC_I, COMBO_END};
const uint16_t PROGMEM ru_r_combo[] = {R(KC_L), KC_O, COMBO_END};
const uint16_t PROGMEM pu_r_combo[] = {P(KC_QUOT), KC_P, COMBO_END};
const uint16_t PROGMEM thumbl_combo[] = {THUMBL1, THUMBL2, COMBO_END};
const uint16_t PROGMEM thumbr_combo[] = {THUMBR1, THUMBR2, COMBO_END};
const uint16_t PROGMEM thumbr_sym_combo[] = {KC_RPRN, KC_UNDS, COMBO_END};
const uint16_t PROGMEM shift_paste_combo[] = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM paren_combo[] = {I(KC_F), I(KC_J), COMBO_END};
const uint16_t PROGMEM sqbrc_combo[] = {M(KC_D), M(KC_K), COMBO_END};
const uint16_t PROGMEM cbrc_combo[] = {R(KC_S), R(KC_L), COMBO_END};
const uint16_t PROGMEM quote_combo[] = {KC_V, KC_M, COMBO_END};
const uint16_t PROGMEM squote_combo[] = {KC_C, KC_COMMA, COMBO_END};
const uint16_t PROGMEM triag_combo[] = {KC_X, KC_DOT, COMBO_END};
const uint16_t PROGMEM ca_paste_combo[] = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM secret_0_combo[] = {I(KC_J), KC_I, R(KC_L), COMBO_END};
const uint16_t PROGMEM secret_1_combo[] = {I(KC_J), KC_I, R(KC_L), KC_X, COMBO_END};
const uint16_t PROGMEM secret_2_combo[] = {I(KC_J), KC_I, R(KC_L), KC_C, COMBO_END};
const uint16_t PROGMEM secret_3_combo[] = {I(KC_J), KC_I, R(KC_L), KC_V, COMBO_END};

combo_t key_combos[] = {
    [THUMBL_COMBO] = COMBO(thumbl_combo, THUMBL3),
    [THUMBR_COMBO] = COMBO(thumbr_combo, THUMBR3),
    [THUMBR_SYM_COMBO] = COMBO(thumbr_sym_combo, KC_LPRN),
    [IM_R_COMBO] = COMBO(im_r_combo, KC_ESC),
    [IT1_L_COMBO] = COMBO(it1_l_combo, SPC_MINS_MACRO),
    [IT1_R_COMBO] = COMBO(it1_r_combo, OSM_SFT),
    [IT2_L_COMBO] = COMBO(it2_l_combo, SPC_MINS_EQ_MACRO),
    [MT1_L_COMBO] = COMBO(mt1_l_combo, SPC_PLS_MACRO),
    [MT2_L_COMBO] = COMBO(mt2_l_combo, SPC_PLS_EQ_MACRO),
    [RT1_L_COMBO] = COMBO(rt1_l_combo, SPC_EQ_MACRO),
    [RT2_L_COMBO] = COMBO(rt2_l_combo, SPC_EQ_EQ_MACRO),
    [PT1_L_COMBO] = COMBO(pt1_l_combo, SPC_AST_MACRO),
    [PT2_L_COMBO] = COMBO(pt2_l_combo, SPC_NOT_EQ_MACRO),
    [IDT1_L_COMBO] = COMBO(idt1_l_combo, SPC_GT_MACRO),
    [MDT1_L_COMBO] = COMBO(mdt1_l_combo, SPC_LT_MACRO),
    [IDT2_L_COMBO] = COMBO(idt2_l_combo, SPC_GTE_MACRO),
    [MDT2_L_COMBO] = COMBO(mdt2_l_combo, SPC_LTE_MACRO),
    [WORD_I_COMBO] = COMBO(word_i_combo, WORD_I_MACRO),
    [SPC_COMMA_COMBO] = COMBO(spc_comma_combo, SPC_COMMA_MACRO),
    [MR_R_COMBO] = COMBO(mr_r_combo, KC_RIGHT),
    [MR_L_COMBO] = COMBO(mr_l_combo, KC_LEFT),
    [RP_R_COMBO] = COMBO(rp_r_combo, KC_END),
    [RP_L_COMBO] = COMBO(rp_l_combo, KC_HOME),
    [ID_R_COMBO] = COMBO(id_r_combo, KC_MINS),
    [ID_L_COMBO] = COMBO(id_l_combo, KC_UNDS),
    [FD_R_COMBO] = COMBO(fd_r_combo, KC_SCLN),
    [FU_R_COMBO] = COMBO(fu_r_combo, KC_6),
    [IU_R_COMBO] = COMBO(iu_r_combo, KC_7),
    [MU_R_COMBO] = COMBO(mu_r_combo, KC_8),
    [RU_R_COMBO] = COMBO(ru_r_combo, KC_9),
    [PU_R_COMBO] = COMBO(pu_r_combo, KC_0),
    [FD_L_COMBO] = COMBO(fd_l_combo, KC_COLN),
    [FU_L_COMBO] = COMBO(fu_l_combo, KC_5),
    [IU_L_COMBO] = COMBO(iu_l_combo, KC_4),
    [MU_L_COMBO] = COMBO(mu_l_combo, KC_3),
    [RU_L_COMBO] = COMBO(ru_l_combo, KC_2),
    [PU_L_COMBO] = COMBO(pu_l_combo, KC_1),
    [SHIFT_PASTE_COMBO] = COMBO(shift_paste_combo, S(C(KC_V))),
    [PAREN_COMBO] = COMBO(paren_combo, PAREN_MACRO),
    [SQBRC_COMBO] = COMBO(sqbrc_combo, SQBRC_MACRO),
    [CBRC_COMBO] = COMBO(cbrc_combo, CBRC_MACRO),
    [QUOTE_COMBO] = COMBO(quote_combo, QUOT_MACRO),
    [SQUOTE_COMBO] = COMBO(squote_combo, SQUOT_MACRO),
    [TRIAG_COMBO] = COMBO(triag_combo, TRIAG_MACRO),
    [CA_PASTE_COMBO] = COMBO(ca_paste_combo, CA_PASTE_MACRO),
    [SECRET_0_COMBO] = COMBO(secret_0_combo, SECRET_0_MACRO),
    [SECRET_1_COMBO] = COMBO(secret_1_combo, SECRET_1_MACRO),
    [SECRET_2_COMBO] = COMBO(secret_2_combo, SECRET_2_MACRO),
    [SECRET_3_COMBO] = COMBO(secret_3_combo, SECRET_3_MACRO),
};

#define COMBO_REF_DEFAULT _QWERTY

uint8_t combo_ref_from_layer(uint8_t layer) {
    switch (get_highest_layer(layer_state)) {
        case _SYM:
            return _SYM;
        case _NAV:
            return _NAV;
        default:
            return _QWERTY;
    }
    return layer; // important if default is not in case.
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(_PLOVER)) {
        return false;
    }

    return true;
}
#endif
