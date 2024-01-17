// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum {
	_GRAPHITE,
	_QWERTY,
	_NUMBERS,
	_SPECIAL
};

const uint16_t PROGMEM comboBL[]       = {KC_B,    KC_L,    COMBO_END};
const uint16_t PROGMEM comboLD[]       = {KC_L,    KC_D,    COMBO_END};
const uint16_t PROGMEM comboDW[]       = {KC_D,    KC_W,    COMBO_END};
const uint16_t PROGMEM comboNR[]       = {KC_N,    KC_R,    COMBO_END};
const uint16_t PROGMEM comboRT[]       = {KC_R,    KC_T,    COMBO_END};
const uint16_t PROGMEM comboTS[]       = {KC_T,    KC_S,    COMBO_END};
const uint16_t PROGMEM comboQX[]       = {KC_Q,    KC_X,    COMBO_END};
const uint16_t PROGMEM comboXM[]       = {KC_X,    KC_M,    COMBO_END};
const uint16_t PROGMEM comboMC[]       = {KC_M,    KC_C,    COMBO_END};
const uint16_t PROGMEM comboFO[]       = {KC_F,    KC_O,    COMBO_END};
const uint16_t PROGMEM comboOU[]       = {KC_O,    KC_U,    COMBO_END};
const uint16_t PROGMEM comboUJ[]       = {KC_U,    KC_J,    COMBO_END};
const uint16_t PROGMEM comboHA[]       = {KC_H,    KC_A,    COMBO_END};
const uint16_t PROGMEM comboAE[]       = {KC_A,    KC_E,    COMBO_END};
const uint16_t PROGMEM comboEI[]       = {KC_E,    KC_I,    COMBO_END};
const uint16_t PROGMEM comboPDot[]     = {KC_P,    KC_DOT,  COMBO_END};
const uint16_t PROGMEM comboDotMins[]  = {KC_DOT,  KC_MINS, COMBO_END};
const uint16_t PROGMEM comboMinsSlsh[] = {KC_MINS, KC_SLSH, COMBO_END};
combo_t key_combos[] = {
	COMBO(comboBL,       KC_ESC),
	COMBO(comboLD,       KC_LBRC),
	COMBO(comboDW,       KC_RBRC),
	COMBO(comboNR,       KC_TILD),
	COMBO(comboRT,       KC_LPRN),
	COMBO(comboTS,       KC_RPRN),
	COMBO(comboQX,       KC_TAB),
	COMBO(comboXM,       KC_LCBR),
	COMBO(comboMC,       KC_RCBR),
	COMBO(comboFO,       KC_PLUS),
	COMBO(comboOU,       KC_EQL),
	COMBO(comboUJ,       KC_SCLN),
	COMBO(comboHA,       KC_COMM),
	COMBO(comboAE,       KC_QUES),
	COMBO(comboEI,       KC_PIPE),
	COMBO(comboPDot,     KC_LABK),
	COMBO(comboDotMins,  KC_RABK),
	COMBO(comboMinsSlsh, KC_BSLS)
};

// Graphite has non-standard shifted punctuation
const key_override_t underscoreOverride = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUOT, S(KC_MINS), (1 << _GRAPHITE));
const key_override_t questionOverride   = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, S(KC_SLSH), (1 << _GRAPHITE));
const key_override_t dQuoteOverride     = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINS, S(KC_QUOT), (1 << _GRAPHITE));
const key_override_t lAngBrakOverride   = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLSH, S(KC_COMM), (1 << _GRAPHITE));

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
      * │  B Esc L  [  D  ]  W  │  Z  │       │  '  │  F  +  O  =  U  ;  J  │
      * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
      * │  N  ~  R  (  T  )  S  │  G  │       │  Y  │  H  ,  A  ?  E (|) I  │
      * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
      * │  Q Tab X  {  M  }  C  │  V  │       │  K  │  P  <  .  >  -  \  /  │
      * └─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
      *             ┌─────┐                               ┌─────┐
      *             │ Nop ├─────┐                   ┌─────┤ Nop │
      *             └─────┤ Spc ├─────┐       ┌─────┤ Sft ├─────┘
      *                   └─────┤ Bsp │       │ Ent ├─────┘
      *                         └─────┘       └─────┘
      */
    [0] = LAYOUT_split_3x5_3(
        KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,             KC_QUOT, KC_F,    KC_O,    KC_U,    KC_J,
        KC_N,    KC_R,    KC_T,    KC_S,    KC_G,             KC_Y,    KC_H,    KC_A,    KC_E,    KC_I,
        KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,             KC_K,    KC_P,    KC_DOT,  KC_MINS, KC_SLSH,
                          KC_NO,   KC_SPC,  KC_BSPC,          KC_ENT,  KC_LSFT, KC_NO
    )
};

const key_override_t **key_overrides = (const key_override_t *[]){
        &underscoreOverride,
        &questionOverride,
        &dQuoteOverride,
        &lAngBrakOverride,
        NULL
};

