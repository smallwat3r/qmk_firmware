#include QMK_KEYBOARD_H

enum layers {
    BASE,
    SYM,
    NUM,
    NAV,
    NAV2,
    EDIT,
    FUN,
    FRENCH,
    SYS,
};

// define one name per key to use on the base layer, this is a
// useful level of abstraction in order to define combos
#define CK_1 KC_L
#define CK_2 KC_D
#define CK_3 KC_M
#define CK_4 MT(MOD_LSFT, KC_H)
#define CK_5 LT(SYM, KC_R)
#define CK_6 LT(NUM, KC_T)
#define CK_7 LT(NAV, KC_S)
#define CK_8 KC_G
#define CK_9 MT(MOD_LCTL, KC_TAB)
#define CK_10 MT(MOD_LALT, KC_QUOT)
#define CK_11 MT(MOD_LGUI, KC_C)
#define CK_12 MO(EDIT)
#define CK_13 LT(FUN, KC_SPC)
#define CK_14 KC_F
#define CK_15 KC_O
#define CK_16 KC_U
#define CK_17 KC_Y
#define CK_18 LT(FRENCH, KC_N)
#define CK_19 LT(NUM, KC_A)
#define CK_20 LT(SYM, KC_E)
#define CK_21 MT(MOD_LSFT, KC_I)
#define CK_22 MT(MOD_LGUI, KC_P)
#define CK_23 MT(MOD_LALT, KC_COMM)
#define CK_24 MT(MOD_LCTL, KC_DOT)
#define CK_25 LT(SYS, KC_BSPC)
#define CK_26 LT(SYM, KC_ENT)
#define KC_EURO LSFT(LALT(KC_2))

// need to be included after custom keycode definition
#include "g/keymap_combo.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
               CK_1,  CK_2,  CK_3,                CK_14, CK_15, CK_16,
         CK_4, CK_5,  CK_6,  CK_7,  CK_8,  CK_17, CK_18, CK_19, CK_20, CK_21,
               CK_9,  CK_10, CK_11,               CK_22, CK_23, CK_24,
                             CK_12, CK_13, CK_25, CK_26
    ),
    [NUM] = LAYOUT(
               KC_7, KC_8, KC_9,                KC_7, KC_8, KC_9,
        KC_0,  KC_4, KC_5, KC_6, KC_NO,  KC_NO, KC_4, KC_5, KC_6, KC_0,
               KC_1, KC_2, KC_3,                KC_1, KC_2, KC_3,
                       KC_TRNS, KC_SPC,  KC_BSPC, KC_DEL
    ),
    [SYM] = LAYOUT(
              KC_AT, LSFT(KC_3), LSFT(KC_4),                   KC_BSLS, KC_SLASH, LSFT(KC_SLASH),
 LSFT(KC_8), LSFT(KC_EQUAL), KC_EQUAL, LSFT(KC_QUOTE), LSFT(KC_5), LSFT(KC_1), LSFT(KC_SCLN), RALT(KC_3), LSFT(KC_GRAVE), LSFT(KC_BSLS),
              KC_MINUS, LSFT(KC_7), KC_GRAVE,                  LSFT(KC_COMMA), LSFT(KC_DOT), KC_NO,
                                KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS
    ),
    [NAV] = LAYOUT(
                 KC_TRNS, KC_TRNS, KC_TRNS,                     LSFT(KC_LBRC), LSFT(KC_RBRC), KC_TRNS,
        KC_TRNS, KC_TRNS, MO(NAV2), KC_TRNS, KC_TRNS,   KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS,                     KC_LBRC, KC_RBRC, KC_TRNS,
                                KC_TRNS, KC_TRNS,      KC_BSPC, KC_DEL
    ),
    [EDIT] = LAYOUT(
                 SGUI(KC_G), LGUI(KC_F), LGUI(KC_G), LSFT(KC_LBRC), LSFT(KC_RBRC), KC_TRNS,
        LGUI(KC_A), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), LCTL(KC_C),  KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS,
                 KC_TRNS, LGUI(KC_Z), SGUI(KC_Z),                    KC_LBRC, KC_RBRC, KC_TRNS,
                                KC_TRNS, KC_TRNS,      KC_BSPC, KC_DEL
    ),
    [NAV2] = LAYOUT(
                 KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  LALT(KC_LEFT), KC_TRNS, KC_TRNS, LALT(KC_RIGHT), KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS,
                                KC_TRNS, KC_TRNS,     LALT(KC_BSPC), LALT(KC_DEL)
    ),
    [FUN] = LAYOUT(
                 KC_TRNS, KC_TRNS, KC_TRNS,                    KC_F7, KC_F8, KC_F9,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_F4, KC_F5, KC_F6, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS,                    KC_F1, KC_F2, KC_F3,
                                KC_TRNS, KC_TRNS,      LALT(KC_BSPC), LALT(KC_DEL)
    ),
    [SYS] = LAYOUT(
                 KC_TRNS, KC_BTN4, KC_BTN5,                    KC_VOLD, KC_VOLU, KC_MUTE,
        RGB_HUD, KC_BRIU, KC_WH_U, KC_WH_D, KC_TRNS,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, RGB_HUI,
                 KC_BRID, RGB_SAD, RGB_SAI,                   LGUI(KC_KP_MINUS), LGUI(KC_KP_PLUS), KC_TRNS,
                                KC_BTN2, KC_BTN1,      KC_TRNS, KC_TRNS
    ),
    [FRENCH] = LAYOUT(
                 KC_TRNS, KC_BTN4, KC_BTN5,                    KC_VOLD, KC_VOLU, KC_MUTE,
        RGB_HUD, KC_BRIU, KC_WH_U, KC_WH_D, KC_TRNS,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, RGB_HUI,
                 KC_BRID, RGB_SAD, RGB_SAI,                   LGUI(KC_KP_MINUS), LGUI(KC_KP_PLUS), KC_TRNS,
                                KC_BTN2, KC_BTN1,      KC_TRNS, KC_TRNS
    ),
};

#ifdef RGBLIGHT_ENABLE
const rgblight_segment_t PROGMEM capslock_layer[]  = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_RED});
const rgblight_segment_t PROGMEM osm_shift_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_YELLOW});

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(capslock_layer, osm_shift_layer);
void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

/* light up led in red when caps lock in on */
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

/* light up led in yellow when sticky shift is activated */
void oneshot_mods_changed_user(uint8_t mods) {
    if (mods & MOD_MASK_SHIFT) {
        rgblight_set_layer_state(1, true);
    }
    if (!mods) {
        rgblight_set_layer_state(1, false);
    }
}
#endif
