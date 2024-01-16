// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum {
	_GRAPHITE,
	_QWERTY,
	_NUMBERS,
	_SPECIAL
};

// Graphite has non-standard shifted punctuation
const key_override_t underscoreOverride = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUOT, S(KC_MINS), (1 << _GRAPHITE));
const key_override_t questionOverride   = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, S(KC_SLSH), (1 << _GRAPHITE));
const key_override_t dQuoteOverride     = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINS, S(KC_QUOT), (1 << _GRAPHITE));
const key_override_t lAngBrakOverride   = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLSH, S(KC_COMM), (1 << _GRAPHITE));

const key_override_t **key_overrides = (const key_override_t *[]){
        &underscoreOverride,
        &questionOverride,
        &dQuoteOverride,
        &lAngBrakOverride,
        NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ B │ L │ D │ W │ Z │       │ ' │ F │ O │ J │ J │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ N │ R │ T │ S │ G │       │ Y │ H │ A │ E │ I │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Q │ X │ M │ C │ V │       │ K │ P │ . │ - │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │Nop├───┐           ┌───┤Nop│
      *           └───┤Spc├───┐   ┌───┤Sft├───┘
      *               └───┤Bsp│   │Ent├───┘
      *                   └───┘   └───┘
      */
    [0] = LAYOUT_split_3x5_3(
        KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,             KC_QUOT, KC_F,    KC_O,    KC_U,    KC_J,
        KC_N,    KC_R,    KC_T,    KC_S,    KC_G,             KC_Y,    KC_H,    KC_A,    KC_E,    KC_I,
        KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,             KC_K,    KC_P,    KC_DOT,  KC_MINS, KC_SLSH,
                          KC_NO,   KC_SPC,  KC_BSPC,          KC_ENT,  KC_LSFT, KC_NO
    )
};
