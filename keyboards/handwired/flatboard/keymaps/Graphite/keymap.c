// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum {
	_GRAPHITE, 
	_GAME,
	_QWERTY,
	_NUMBERS,
	_ARROWS,
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

// Layer-taps / mod-taps for thumb keys
#define MT_DEL_ALT MT(MOD_LALT, KC_DEL)
#define LT_SPC_NUM LT(_NUMBERS, KC_SPC)
#define LT_SPC_SPE LT(_SPECIAL, KC_SPC)
#define MT_BSP_SFT MT(MOD_LSFT, KC_BSPC)
#define MT_ESC_CTL MT(MOD_LCTL, KC_ESC)
#define LT_ENT_ARR LT(_ARROWS,  KC_ENT)
#define LT_ENT_SPE LT(_SPECIAL,  KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
      * │  B  [  L  ]  D  ~  W  │  Z  │       │  '  │  F (|) O  ;  U  =  J  │
      * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
      * │  N  (  R  )  T Tab S  │  G  │       │  Y  │  H  ,  A  ?  E  +  I  │
      * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
      * │  Q  {  X  }  M  `  C  │  V  │       │  K  │  P  \  .  <  -  >  /  │
      * └─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
      *             ┌─────┐                               ┌─────┐
      *             │ Del │                               │ Met │
      *             │ Alt ├─────┐                   ┌─────┤     │
      *             └─────┤ Spc │                   │ Ent ├─────┘
      *                   │ NUM ├─────┐       ┌─────┤ ARR │
      *                   └─────┤ Bsp │       │ Esc ├─────┘
      *                         │ Sft │       │ Ctr │
      *                         └─────┘       └─────┘
      */
    [_GRAPHITE] = LAYOUT_split_3x5_3(
        KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,             KC_QUOT, KC_F,    KC_O,    KC_U,    KC_J,
        KC_N,    KC_R,    KC_T,    KC_S,    KC_G,             KC_Y,    KC_H,    KC_A,    KC_E,    KC_I,
        KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,             KC_K,    KC_P,    KC_DOT,  KC_MINS, KC_SLSH,
                 MT_DEL_ALT, LT_SPC_NUM, MT_BSP_SFT,          MT_ESC_CTL, LT_ENT_ARR, KC_LGUI
    ),

     /*
      * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
      * │  B  │  L  │  D  │  W  │  Z  │       │  '  │  F  │  O  │  U  │  J  │
      * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
      * │  N  │  R  │  T  │  S  │  G  │       │  Y  │  ←  │  ↑  │  →  │  I  │
      * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
      * │  Q  │  X  │  M  │  C  │  V  │       │  K  │  P  │  ↓  │  -  │  /  │
      * └─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
      *             ┌─────┐                               ┌─────┐
      *             │ Del ├─────┐                   ┌─────┤ GRA │
      *             └─────┤ Spc ├─────┐       ┌─────┤ Ent ├─────┘
      *                   └─────┤ Bsp │       │ Esc ├─────┘
      *                         └─────┘       └─────┘
      */
    [_GAME] = LAYOUT_split_3x5_3(
        KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,             KC_QUOT, KC_F,    KC_O,    KC_U,    KC_J,
        KC_N,    KC_R,    KC_T,    KC_S,    KC_G,             KC_Y,    KC_LEFT, KC_UP,   KC_RGHT, KC_I,
        KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,             KC_K,    KC_P,    KC_DOWN, KC_MINS, KC_SLSH,
                          KC_DEL,  KC_SPC,  KC_BSPC,          KC_ESC,  KC_ENT,  TO(_GRAPHITE)
    ),


     /*
      * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
      * │  Q  [  W  ]  E  ~  R  │  T  │       │  Y  │  U (|) I  ;  O  =  P  │
      * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
      * │  A  (  S  )  D Tab F  │  G  │       │  H  │  J  ,  K  ?  L  +  ;  │
      * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
      * │  Z  {  X  }  C  `  V  │  B  │       │  N  │  M  \  ,  <  .  >  /  │
      * └─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
      *             ┌─────┐                               ┌─────┐
      *             │ Del │                               │ Met │
      *             │ Alt ├─────┐                   ┌─────┤     │
      *             └─────┤ Spc │                   │ Ent ├─────┘
      *                   │ NUM ├─────┐       ┌─────┤ ARR │
      *                   └─────┤ Bsp │       │ Esc ├─────┘
      *                         │ Sft │       │ Ctr │
      *                         └─────┘       └─────┘
      */
    [_QWERTY] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                 MT_DEL_ALT, LT_SPC_NUM, MT_BSP_SFT,          MT_ESC_CTL, LT_ENT_ARR, KC_LGUI
    ),

     /*
      * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
      * │     │     │ Del │ Ins │     │       │     │  7  │  8  │  9  │  ,  │
      * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
      * │  +  │  -  │  *  │  /  │     │       │     │  4  │  5  │  6  │  0  │
      * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
      * │     │     │     │     │     │       │     │  1  │  2  │  3  │  .  │
      * └─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
      *             ┌─────┐                               ┌─────┐
      *             │ Del │                               │ Met │
      *             │ Alt ├─────┐                   ┌─────┤     │
      *             └─────┤ ⬤   │                   │ Ent ├─────┘
      *                   │     ├─────┐       ┌─────┤ SPE │
      *                   └─────┤ Bsp │       │ Esc ├─────┘
      *                         │ Sft │       │ Ctr │
      *                         └─────┘       └─────┘
      */
   [_NUMBERS] = LAYOUT_split_3x5_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_7,    KC_8,    KC_9,    KC_COMM,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_4,    KC_5,    KC_6,    KC_0,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_1,    KC_2,    KC_3,    KC_DOT,
                      MT_DEL_ALT, KC_NO, MT_BSP_SFT,          MT_ESC_CTL, LT_ENT_SPE, KC_LGUI
    ),

     /*
      * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
      * │     │     │     │     │     │       │ Hom │ PgD │ PgU │ End │     │
      * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
      * │     │ Prv │ Nxt │ Ply │     │       │  ←  │  ↓  │  ↑  │  →  │     │
      * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
      * │     │     │     │     │     │       │     │ Vl- │ Vl+ │ Mut │     │
      * └─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
      *             ┌─────┐                               ┌─────┐
      *             │ Del │                               │ Met │
      *             │ Alt ├─────┐                   ┌─────┤     │
      *             └─────┤ Spc │                   │ ⬤   ├─────┘
      *                   │ SPE ├─────┐       ┌─────┤     │
      *                   └─────┤ Bsp │       │ Esc ├─────┘
      *                         │ Sft │       │ Ctr │
      *                         └─────┘       └─────┘
      */
   [_ARROWS] = LAYOUT_split_3x5_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,
        KC_NO,   KC_MPRV, KC_MNXT, KC_MPLY, KC_NO,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_VOLD, KC_VOLU, KC_MUTE, KC_NO,
                 MT_DEL_ALT, LT_SPC_SPE, MT_BSP_SFT,          MT_ESC_CTL, KC_NO, KC_LGUI
    ),

     /*
      * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
      * │ Esc │ Bsp │ Del │     │     │       │     │ F7  │ F8  │ F9  │ F11 │
      * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
      * │     │ GAM │ QWE │ GRA │     │       │     │ F4  │ F5  │ F6  │ F10 │
      * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
      * │ DFU │     │     │     │ Psc │       │     │ F1  │ F2  │ F3  │ F12 │
      * └─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
      *             ┌─────┐                               ┌─────┐
      *             │ Del │                               │ Met │
      *             │ Alt ├─────┐                   ┌─────┤     │
      *             └─────┤ ⬤   │                   │ ⬤   ├─────┘
      *                   │     ├─────┐       ┌─────┤     │
      *                   └─────┤ Bsp │       │ Esc ├─────┘
      *                         │ Sft │       │ Ctr │
      *                         └─────┘       └─────┘
      */
   [_SPECIAL] = LAYOUT_split_3x5_3(
        KC_ESC,  KC_BSPC, KC_DEL,  KC_NO,   KC_NO,            KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F11,
    KC_NO, TO(_GAME), TO(_QWERTY), TO(_GRAPHITE), KC_NO,      KC_NO,   KC_F4,   KC_F5,   KC_F6,   KC_F10,
        QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_PSCR,          KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12,
                      MT_DEL_ALT, KC_NO, MT_BSP_SFT,          MT_ESC_CTL, KC_NO, KC_LGUI
     )
};

// Combos used on all layers except GAME
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
	COMBO(comboBL,       KC_LBRC),
	COMBO(comboLD,       KC_RBRC),
	COMBO(comboDW,       KC_TILD),
	COMBO(comboNR,       KC_LPRN),
	COMBO(comboRT,       KC_RPRN),
	COMBO(comboTS,       KC_TAB),
	COMBO(comboQX,       KC_LCBR),
	COMBO(comboXM,       KC_RCBR),
	COMBO(comboMC,       KC_GRV),
	COMBO(comboFO,       KC_PIPE),
	COMBO(comboOU,       KC_SCLN),
	COMBO(comboUJ,       KC_EQL),
	COMBO(comboHA,       KC_COMM),
	COMBO(comboAE,       KC_QUES),
	COMBO(comboEI,       KC_PLUS),
	COMBO(comboPDot,     KC_BSLS),
	COMBO(comboDotMins,  KC_LABK),
	COMBO(comboMinsSlsh, KC_RABK)
};

// Disable combos on certain layers
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
	if (layer_state_is(_GAME) || layer_state_is(_NUMBERS) || layer_state_is(_ARROWS) || layer_state_is(_SPECIAL)) {
		return false;
	}
	return true;
}

