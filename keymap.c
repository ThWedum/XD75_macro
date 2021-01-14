#include QMK_KEYBOARD_H

/* This is a Equation macro board made by ThWedum.
 * Big credit goes out to kattn for guiding me trough the coding
 * IMPORTANT NOTICE: This is built upon using Norwegian keyboard layout. therfore you will see things like "}" in macro wich will print as "^"
 */


enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  // Row 1
  exponent,   // ×10^X
  box,        // Word equation box
  Ans2,       // one line under answer (word equation)
  Ans,        // Two lines under answer (Word equation)
  explination,      // Explination of how to make this keyboard work 
  Pow_3,      // The power of 3 (^3)
  fraction_1, // Fraction horizontal
  fraction_2, // Fraction linear
  sinus,
  sinus_1,
  cosinus,
  cosinus_1,
  tangens,
  tangens_1,
  number_1,
  number_2
};

enum unicode_names {
    AE,
    ae,
    OE,
    oe,
    AA,
    aa,
    Alpha,
    alpha,
    Beta,
    beta,
    Gamma,
    gamma,
    Delta,
    delta,
    Epsilon,
    epsilon,
    Zeta,
    zeta,
    Eta,
    eta,
    Theta,
    theta,
    Iota,
    iota,
    Lambda,
    lambda,
    Mu,
    mu,
    Xi,
    xi,
    Pi,
    pi,
    Rho,
    rho,
    Sigma,
    sigma,
    Tau,
    tau,
    Upsilon,
    upsilon,
    Phi,
    phi,
    Chi,
    chi,
    Psi,
    psi,
    Omega,
    omega,
    times,
    bullet,
    divide,
    plus,
    minus,
    Equals,
    equals,
    Sqrt,
    angle,
    degree,
    low_line,
    r_above,
    super_minus,
    super_1,
    super_2,
    super_3,
    l_par,
    r_par,
    lower_1,
    lower_2,
    lower_3,
    dots_3,
    arrowup,
    arrowdown,
    circumflex,
    SNEK
};

const uint32_t PROGMEM unicode_map[] = {
    [AE]      = 0x00C6, // Æ
    [ae]      = 0x00E6, // æ
    [OE]      = 0x00D8, // Ø
    [oe]      = 0x00F8, // ø
    [AA]      = 0x00C5, // Å
    [aa]      = 0x00E5, // å
    [Alpha]   = 0x0391, // A
    [alpha]   = 0x03B1, // α
    [Beta]    = 0x0392, // B
    [beta]    = 0x03B2, // β
    [Gamma]   = 0x0393, // Γ
    [gamma]   = 0x03B3, // γ
    [Delta]   = 0x0394, // Δ
    [delta]   = 0x03B4, // δ
    [Epsilon] = 0x0395, // Ε
    [epsilon] = 0x03B5, // ε
    [Zeta]    = 0x0396, // Z
    [zeta]    = 0x03B6, // ζ
    [Eta]     = 0x0397, // Η
    [eta]     = 0x03B7, // η
    [Theta]   = 0x03D1, // ϑ
    [theta]   = 0x03B8, // ϴ
    [Iota]    = 0x0399, // Ι
    [iota]    = 0x0269, // ɩ
    [Lambda]  = 0x039B, // Λ
    [lambda]  = 0x03BB, // λ
    [Mu]      = 0x039C, // M
    [mu]      = 0x03BC, // μ
    [Xi]      = 0x039E, // Ξ
    [xi]      = 0x03BE, // ξ
    [Pi]      = 0x03A0, // Π
    [pi]      = 0x03C0, // π
    [Rho]     = 0x03A1, // P
    [rho]     = 0x03C1, // ρ
    [Sigma]   = 0x03A3, // Σ
    [sigma]   = 0x03C3, // σ
    [Tau]     = 0x03A4, // T
    [tau]     = 0x03C4, // τ
    [Upsilon] = 0x03A5, // Y
    [upsilon] = 0x03C5, // υ
    [phi]     = 0x03D5, // ϕ
    [Phi]     = 0x03C6, // φ
    [Chi]     = 0x03A7, // Χ
    [chi]     = 0x03C7, // χ
    [Psi]     = 0x03A8, // Ψ
    [psi]     = 0x03C8, // ψ
    [Omega]   = 0x03A9, // Ω
    [omega]   = 0x03C9, // ω
    [times]   = 0x00D7, // ×
    [bullet]  = 0x2219, // ∙
    [divide]  = 0x00F7, // ÷
    [plus]    = 0x002B, // +
    [minus]   = 0x002D, // -
    [Equals]  = 0x003D, // =
    [equals]  = 0x2248, // ≈
    [Sqrt]    = 0x221A, // √
    [angle]   = 0x2220, // ∠
    [degree]  = 0x00B0, // °
    [low_line]= 0x005F, // _
    [r_above] = 0x20D7, // ⃗
    [super_minus] = 0x207B, // ⁻
    [super_1] = 0x00B9, // ¹
    [super_2] = 0x00B2, // ²
    [super_3] = 0x00B3, // ³
    [lower_1] = 0x2081, // ₁
    [lower_2] = 0x2082, // ₂
    [lower_3] = 0x2083, // ₃
    [l_par] = 0x0028, // (
    [r_par] = 0x0029, // )
    [dots_3] = 0x2234, // ∴
    [arrowup] = 0x2191, // ↑
    [arrowdown] = 0x2193, // ↓
    [circumflex] = 0x0302, // ̂
    [SNEK] = 0x1F40D, // 🐍
};

// Light LEDs 1 and 8 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED},       // Light 1 LED, starting with LED 1
    {6, 1, HSV_RED}       // Light 1 LED, starting with LED 8
);
// Light LEDs 1 to 8 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_ORANGE}
);
// Light LEDs 1 to 8 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_PURPLE}
);
 
// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* MACRO
 * .--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 * | F13        | Aα         | Bβ         | Γγ         | ^-         | √          | ∴          | box        | sin        | sin-1      |            |            |            |            |            |
 * |------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------|
 * | F14        | Δδ         | Εε         | Ηη         | ^1_1       | ∠          | °          | Ans2       | tan        | tan-1      |            |            |            |            |            |
 * |------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------|
 * | F15        | Θθ         | Λλ         | Μμ         | ^2_2       | =  ≈       |  ⃗   ̂       | Ans        | cos        | cos-1      |            |            |            |            |            |
 * |------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------|
 * | LSHIFT     | Ππ         | Ρρ         | Σσ         | ^3_3       | +  -       | _          | Fraction 1 |            |            |            |            |            |            |            |
 * |------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------|
 * | SPACE      | Ττ         | φϕ         | Ωω         | ( )        | ∙ ÷        | 10^x       | Fraction 2 |            | BACKSP     |  F16       | F17        | F18        | Explination|            |
 * '--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */


 [0] = LAYOUT_ortho_5x15(/* MACRO */
    KC_F13,        XP(alpha,Alpha), XP(beta,Beta),   		XP(gamma,Gamma),    X(super_minus),			X(Sqrt), 			X(dots_3),   			box,    	sinus,		sinus_1,	_______,    _______,	_______,    _______,     _______, 
    KC_F14,        XP(delta,Delta), XP(epsilon,Epsilon), 	XP(eta,Eta),   		XP(super_1,lower_1),	X(angle),        	X(degree),   			Ans2,       tangens,  	tangens_1,	_______,	_______,    _______,    _______,     _______, 
    KC_F15,        XP(theta,Theta), XP(lambda,Lambda), 		XP(mu,Mu),      	XP(super_2,lower_2),	XP(Equals,equals),  XP(r_above,circumflex), Ans,        cosinus,    cosinus_1,	_______,    _______,    _______,    _______,		_______,
    KC_LSHIFT,     XP(pi,Pi),		XP(rho,Rho), 			XP(sigma,Sigma), 	XP(super_3,lower_3), 	XP(plus,minus),     X(low_line), 			fraction_1, _______,    _______,    _______,    _______,    _______,	_______,     _______,
    LALT(KC_RPRN),        XP(tau,Tau), 	XP(Phi,phi),       		XP(omega,Omega),    XP(l_par,r_par),  		XP(bullet,divide),  exponent,    		fraction_2, _______,    KC_BSPC,    KC_F16,     KC_F17,     KC_F18,     explination, LALT(KC_RPRN)
 ),

/* QWERTY
 * .------------------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC         | 1      | 2       | 3      | 4      | 5      | `      | PG UP  | =      | 6      | 7      | 8      | 9      | 0      | -          |
 * |-------------+--------+------- -+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------------------|
 * | TAB         | Q      | W       | E      | R      | T      | Vol +  | PG DN  | NEXT   | Y      | U      | I      | O      | P      | Å          |
 * |-------------+--------+-------- +--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+------------|
 * | LCTRL       | A      | S       | D      | F      | G      | Vol -  | CAP LK | Prev   | H      | J      | K      | L      | Ø      | Æ          |
 * |-------------+--------+-------- +--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+------------|
 * | LSHIFT(HOME)| Z      | X       | C      | V      | B      | Mute   | UP     | \      | N      | M      | ,      | .      | P/     | RSHIFT(END)|
 * |-------------+--------+-------- +--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+------------|
 * | ENTER       | LGUI   | LALT(F5)| MO(2)  | MO(1)  | SPACE  | LEFT   | DOWN   | RIGHT  | BACKSP | DEL    | MENU   | RALT   | PR SCR | ENTER      |
 * '------------------------------------------------------------------------------------------------------------------------------------------------'
 */


 [1] = LAYOUT_ortho_5x15(/* QWERTY */
  KC_ESC, 		     KC_1, 		KC_2, 		     KC_3,  KC_4,  KC_5, 	 KC_GRV,  KC_PGUP, KC_EQL,  KC_6, 	 KC_7,	 KC_8, 	  KC_9, 		     KC_0, 	  KC_MINS,
  KC_TAB, 		     KC_Q, 		KC_W, 		     KC_E,  KC_R,  KC_T, 	 KC_VOLU, KC_PGDN, KC_MNXT, KC_Y, 	 KC_U, 	 KC_I, 	  KC_O, 		     KC_P, 	  XP(aa,AA),
  KC_LCTL, 		     KC_A, 		KC_S, 		     KC_D,  KC_F,  KC_G, 	 KC_VOLD, KC_CAPS, KC_MPRV, KC_H, 	 KC_J, 	 KC_K, 	  KC_L, 		     XP(oe,OE), XP(ae,AE),
  LSFT_T(KC_HOME), KC_Z, 		KC_X, 		     KC_C,  KC_V,  KC_B, 	 KC_MUTE, KC_UP,   KC_BSLS, KC_N, 	 KC_M, 	 KC_COMM, KC_DOT, 	     KC_SLSH, RSFT_T(KC_END),
  KC_ENT,		       KC_LGUI, LALT_T(KC_F5), TT(1), TT(2), KC_SPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, KC_DEL, KC_APP,  RALT_T(KC_F6), KC_PSCR, KC_ENT
 ),




/* NUM AND F
 * .------------------------------------------------------------------------------------------------------------------------------------------------.
 * | NUM LOCK    | F1     | F2      | F3     | F4     |        |        |        | %      | )      | /      | *      | -      |        | LALT())    |
 * |-------------+--------+------- -+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------------------|
 * | TAB         | F5     | F6      | F7     | F8     |        |RGB_VAI |        |        | P7     | P8     | P9     | +      |        | NUM LCK    |
 * |-------------+--------+-------- +--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+------------|
 * |             | F9     | F10     | F11    | F12    |        |RGB_HUI |RGB_TOG | \      | P4     | P5     | P6     | *      |        |            |
 * |-------------+--------+-------- +--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+------------|
 * | LSHIFT      |        |         |        |        |        |RGB_SAI |RGB_M_P | }      | P1     | P2     | P3     | (      |        |            |
 * |-------------+--------+-------- +--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+------------|
 * | ENTER       | LGUI   | LALT(F5)| MO(2)  |        |        |        |RGB_MOD | ?      | BACKSP | P0     | .      | ENTER  |        |            |
 * '------------------------------------------------------------------------------------------------------------------------------------------------'
 */

 [2] = LAYOUT_ortho_5x15(/* FN */
  KC_NLCK, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, X(arrowup), KC_PERC, KC_RPRN, KC_PSLS, KC_PAST, KC_PMNS, _______, LALT(KC_RPRN),
  KC_TAB,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, RGB_VAI, X(arrowdown), _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______, KC_NLCK,
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, RGB_HUI, RGB_TOG, KC_NUBS, KC_P4,   KC_P5,   KC_P6,   KC_ASTR, _______, _______,
  KC_LSFT, _______, _______, _______, _______, _______, RGB_SAI, RGB_M_P, KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_LPRN, _______, _______,
  KC_ENT,  KC_LGUI, _______, KC_TRNS, _______, _______, _______, RGB_MOD, KC_QUES, KC_BSPC, KC_P0,   KC_DOT,  KC_PENT, _______, _______
 )
	
};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("03BC"SS_LALT("x"));
      } else {
        // when keycode QMKBEST is released
      }
      break;

    case exponent:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("10"SS_LSFT("}"));
      } else {
        // when keycode QMKBEST is released
      }
      break;

    case box:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("=rect*("SS_TAP(X_LEFT));
      } else {
        // when keycode QMKBEST is released
      }
      break;

    case Ans:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("*"SS_TAP(X_END)"(=Ubar  ");
      } else {
        // when keycode QMKBEST is released
      }
      break;

    case Ans2:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("*"SS_TAP(X_END)"(=ubar  ");
      } else {
        // when keycode QMKBEST is released
      }
      break;

    case explination:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("For [ bruke tastaturet her er det viktig [ bruke Norsk tastaturinstillinger. For [ f[ symboler til [ funger m[ det skrives inn EnableHexNumpad i regedit under HKEY_CURRENT_USER Control Panel Input Method. Gj;r sett denne til REG?SZ og sett den til 1. For mer informasjon, s;k p[ QMK Unicode UC?WIN");
      } else {
        // when keycode QMKBEST is released
      }
      break;

    case Pow_3:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_LSFT("}")"3 ");
      } else {
        // when keycode QMKBEST is released
      }
      break;

    case fraction_1:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("& "SS_TAP(X_LEFT)SS_TAP(X_LEFT));
      } else {
        // when keycode QMKBEST is released
      }
      break;

    case fraction_2:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("=&");
      } else {
        // when keycode QMKBEST is released
      }
      break;

    case sinus:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("sin ");
      } else {
        // when keycode QMKBEST is released
      }
      break;

    case sinus_1:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("sin}/1 ");
      } else {
        // when keycode QMKBEST is released
      }
      break;

    case cosinus:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("cos ");
      } else {
        // when keycode QMKBEST is released
      }
      break;

    case cosinus_1:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("cos}/1 ");
      } else {
        // when keycode QMKBEST is released
      }
      break;

    case tangens:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("tan ");
      } else {
        // when keycode QMKBEST is released
      }
      break;

    case tangens_1:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("tan}/1 ");
      } else {
        // when keycode QMKBEST is released
      }
      break;

    case number_1:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("?1 ");
      } else {
        // when keycode QMKBEST is released
      }
      break;

    case number_2:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("?2 ");
      } else {
        // when keycode QMKBEST is released
      }
      break;




  }
  return true;
};

