#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"

#define TRANS KC_TRANSPARENT
#define WMAN 0
#define QWER 1
#define SYMB 2
#define EMOJ 3
#define FUN  4
#define ARRW 5

enum custom_keycodes {
	ALT_TAB = SAFE_RANGE
};

enum unicodeChars {
	nbsp,		flipEx,		cent,		sect,
	cprite,		degree,		plsMin,		flipQ,
	Delta,		Sigma,		Phi,		Omega,
	alpha,		beta,		gamma,		theta,
	lambda,		mu,			pi,			rho,
	omega,		enDash,		emDash,		ellip,
	heart,		B,			moon,		eggpl,
	party,		eyes,		OK,			boi,
	vein,		sweat,		poop,		hundo,
	fire,		gun,		joy,		anime,
	xd,			wink,		blush,		love,
	smirk,		kiss,		cry,		noMouth,
	flip,		praise,		bless,		think
};

const uint32_t PROGMEM unicode_map[] = {
	0x000A0,	0x000A0,	0x000A2,	0x000A7,
	0x000A9,	0x000B0,	0x000B1,	0x000BF,
	0x00394,	0x003A3,	0x003A6,	0x003A9,
	0x003B1,	0x003B2,	0x003B3,	0x003B8,
	0x003BB,	0x003BC,	0x003C0,	0x003C1,
	0x003C9,	0x02013,	0x02014,	0x02026,
	0x02764,	0x1F171,	0x1F31A,	0x1F346,
	0x1F389,	0x1F440,	0x1F44C,	0x1F44F,
	0x1F4A2,	0x1F4A6,	0x1F4A9,	0x1F4AF,
	0x1F525,	0x1F52B,	0x1F602,	0x1F605,
	0x1F606,	0x1F609,	0x1F60A,	0x1F60D,
	0x1F60F,	0x1F618,	0x1F62D,	0x1F636,
	0x1F643,	0x1F64C,	0x1F64F,	0x1F914
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Workman (base)
[WMAN] = LAYOUT_ergodox(
	KC_ESC,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_INS,
	KC_GRV,		KC_Q,		KC_D,		KC_R,		KC_W,		KC_B,		KC_NO,
	KC_TAB,		KC_A,		KC_S,		KC_H,		KC_T,		KC_G,
	ALT_TAB,	KC_Z,		KC_X,		KC_M,		KC_C,		KC_V,		KC_LBRC,
	KC_HOME,	KC_END,		KC_PGUP,	KC_PGDN,	KC_PSCR,
	KC_LGUI,	MO(FUN),	KC_LALT,	KC_SPC,		KC_BSPC,	KC_LCTL,

	KC_DEL,		KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_BSLS,
	KC_NO,		KC_J,		KC_F,		KC_U,		KC_P,		KC_SCLN,	KC_EQL,
				KC_Y,		KC_N,		KC_E,		KC_O,		KC_I,		KC_QUOT,
	KC_RBRC,	KC_K,		KC_L,		KC_COMM,	KC_DOT,		KC_SLSH,	KC_MINS,
							MO(ARRW),	TG(ARRW),	TG(SYMB),	TG(EMOJ),	TG(QWER),
	MO(FUN),	KC_RGUI,	KC_RALT,	KC_RCTL,	KC_ENT,		KC_RSFT
),

// QWERTY
[QWER] = LAYOUT_ergodox(
	TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS,
	TRANS,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		TRANS,
	TRANS,		KC_A,		KC_S,		KC_D,		KC_F,		KC_G,
	TRANS,		KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		TRANS,
	TRANS,		TRANS,		TRANS,		TRANS,		TRANS,
	TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS,

	TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS,
	TRANS,		KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		TRANS,
				KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,	TRANS,
	TRANS,		KC_N,		KC_M,		TRANS,		TRANS,		TRANS,		TRANS,
							TRANS,		TRANS,		TRANS,		TRANS,		TRANS,
	TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS
),

// Greek/common special chars
[SYMB] = LAYOUT_ergodox(
	X(flipEx),	KC_NO,		KC_NO,		KC_NO,		X(cent),	KC_NO,		KC_NO,
	KC_NO,		KC_NO,		X(Delta),	X(rho),		X(omega),	X(beta),	KC_NO,
	KC_NO,		X(alpha),	X(sect),	KC_NO,		X(theta),	X(gamma),
	KC_NO,		KC_NO,		KC_NO,		X(emDash),	X(cprite),	KC_NO,		KC_NO,
	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
	KC_NO,		TRANS,		KC_NO,		TRANS,		TRANS,		KC_NO,

	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		X(degree),	KC_NO,
	KC_NO,		KC_NO,		KC_NO,		X(mu),		X(pi),		KC_NO,		X(plsMin),
				KC_NO,		X(enDash),	X(Sigma),	X(Omega),	X(Phi),		KC_NO,
	KC_NO,		KC_NO,		KC_NO,		KC_NO,		X(ellip),	X(flipQ),	KC_NO,
							TRANS,		TRANS,		TRANS,		KC_NO,		KC_NO,
	TRANS,		KC_NO,		KC_NO,		KC_NO,		TRANS,		KC_NO
),

// Emoji
[EMOJ] = LAYOUT_ergodox(
	KC_NO,		X(hundo),	KC_NO,		X(heart),	KC_NO,		KC_NO,		KC_NO,
	KC_NO,		KC_NO,		KC_NO,		X(blush),	X(wink),	X(B),		KC_NO,
	KC_NO,		X(anime),	X(smirk),	X(love),	X(sweat),	X(gun),
	KC_NO,		X(moon),	X(xd),		KC_NO,		X(cry),		X(vein),	KC_NO,
	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
	KC_NO,		TRANS,		KC_NO,		TRANS,		TRANS,		KC_NO,

	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
	KC_NO,		X(joy),		X(fire),	X(flip),	X(poop),	X(party),	KC_NO,
				KC_NO,		X(noMouth),	X(eggpl),	X(OK),		X(eyes),	KC_NO,
	KC_NO,		X(kiss),	X(boi),		X(praise),	X(bless),	X(think),	KC_NO,
							TRANS,		TRANS,		KC_NO,		TRANS,		KC_NO,
	TRANS,		KC_NO,		KC_NO,		KC_NO,		TRANS,		KC_NO
),

// Function mode/special keys
[FUN] = LAYOUT_ergodox(
	KC_NO,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_F11,
	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_MUTE,		KC_VOLU,
	KC_NO,		KC_NO,		KC_NO,		KC_MPRV,	KC_MNXT,	KC_MPLY,
	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_VOLD,
	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
	TRANS,		KC_NO,		TRANS,		TRANS,		KC_DEL,		TRANS,

	KC_F12,		KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_SLCK,
	KC_NO,		KC_PMNS,	KC_P7,		KC_P8,		KC_P9,		KC_PSLS,	KC_NLCK,
				KC_PPLS,	KC_P4,		KC_P5,		KC_P6,		KC_PAST,	KC_PENT,
	KC_NO,		KC_P0,		KC_P1,		KC_P2,		KC_P3,		KC_PDOT,	KC_NO,
							TRANS,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
	KC_NO,		TRANS,		TRANS,		TRANS,		TRANS,		KC_LSFT
),

// Arrow keys in vim locations (YNEO)
[ARRW] = LAYOUT_ergodox(
	TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS,
	TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS,
	TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS,
	TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS,
	TRANS,		TRANS,		TRANS,		TRANS,		TRANS,
	TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS,

	TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS,
	TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS,
				KC_LEFT,	KC_DOWN,	KC_UP,		KC_RGHT,	TRANS,		TRANS,
	TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS,
							KC_NO,		TRANS,		TRANS,		TRANS,		TRANS,
	TRANS,		TRANS,		TRANS,		TRANS,		TRANS,		TRANS
),
};

const uint16_t PROGMEM fn_actions[] = {
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	return MACRO_NONE;
};

void matrix_init_user(void) {
	ergodox_board_led_off();
	ergodox_right_led_1_off();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();
	set_unicode_input_mode(UC_LNX);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch(keycode) {
			case ALT_TAB:
				SEND_STRING(SS_LALT("\t"));
				return false;
		}
	}
	return true;
}

uint32_t layer_state_set_user(uint32_t state) {
	uint8_t layer = biton32(state);
	switch (layer) {
		case WMAN:
			ergodox_board_led_off();
			ergodox_right_led_1_off();
			ergodox_right_led_2_off();
			ergodox_right_led_3_off();
			break;
		case QWER:  // QWERTY
			ergodox_board_led_off();
			ergodox_right_led_1_on();
			ergodox_right_led_2_off();
			ergodox_right_led_3_off();
			break;
		case SYMB:  // greek/special
			ergodox_board_led_off();
			ergodox_right_led_1_off();
			ergodox_right_led_2_on();
			ergodox_right_led_3_off();
			break;
		case EMOJ:  // emoji
			ergodox_board_led_off();
			ergodox_right_led_1_on();
			ergodox_right_led_2_on();
			ergodox_right_led_3_on();
			break;
		case ARRW:  // Vim arrows
			// Do nothing
			break;
		case FUN:  // function/media
			ergodox_board_led_off();
			ergodox_right_led_1_off();
			ergodox_right_led_2_off();
			ergodox_right_led_3_on();
			break;
		default:
			break;
	}
	return state;
};
