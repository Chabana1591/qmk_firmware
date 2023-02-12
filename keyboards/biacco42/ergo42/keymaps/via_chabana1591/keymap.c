#include QMK_KEYBOARD_H

#include <eeconfig.h>
#include "keycode.h"
#include "keymap_japanese.h"
#include "custom_keymap.h"
#include <twpair_on_jis.h>

#define BASE 0
#define META 1
#define NUM  2
#define ADJ 3


// Chabana1591: See custom_keymap.h
user_config_t user_config = {};

// Chabana1591: Keycodes JIS / US Switching
enum custom_keycodes {
	CK_EnJIS = SAFE_RANGE,
	CK_EnUS
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   ,--------------------------------------------------------------. ,--------------------------------------------------------------.
   |  Esc   |   Q    |   W    |   E    |   R    |   T    | Insert | | Delete |   `    |  RSft  |   '    |   [    |   ]    |  Bksp  |
   |--------+--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------+--------|
   |  Tab   |   A    |   S    |   D    |   F    |   G    | Adjust | | IME    |   Y    |   U    |   I    |   O    |   P    |   \    |
   |--------+--------+--------+--------+--------+--------+--------| |--------|--------+--------+--------+--------+--------+--------|
   |  LSft  |   Z    |   X    |   C    |   V    |   B    |   =    | |   -    |   H    |   J    |   K    |   L    |   ;    | Enter  |
   |--------+--------+--------+--------+--------+--------+--------| |--------+--------|--------+--------+--------+--------+--------|
   |  Ctrl  |  Appl  |  LAlt  | Print  |  Code  |   Fn   | Space  | | Space  |   N    |   M    |   ,    |   .    |   /    |  RSft  |
   `--------------------------------------------------------------' `--------------------------------------------------------------'
   */
  [BASE] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_INS,    KC_DEL,  KC_GRV,  KC_RSFT, KC_QUOT, KC_LBRC, KC_RBRC, KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    MO(ADJ),   KC_F13,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_EQUAL,  KC_MINUS,KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LCTL, KC_LWIN, KC_LALT, KC_PSCR, MO(NUM), MO(META),KC_SPC,    KC_SPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT
  ),

  /* META
   ,--------------------------------------------------------------. ,--------------------------------------------------------------.
   |  Esc   |   !    |   @    |   #    |   $    |   %    | Insert | | Delete |   ^    |   &    |   *    |   (    |   )    |  Bksp  |
   |--------+--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------+--------|
   |  Tab   |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   | |   F7   |   F8   |   F9   |  F10   |  F11   |  F12   |  PgUp  |
   |--------+--------+--------+--------+--------+--------+--------| |--------|--------|--------+--------+--------+--------+--------|
   |  LSft  |  Vol0  |  kVol-  |  Vol+  | Lght+  | Lght- |   =    | |   -    |  Left  |  Down  |   Up   | Right  |  Home  |  PgDn  |
   |--------+--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------+--------|
   |  Ctrl  |  Appl  |  LAlt  | Print  |  Code  |   Fn   | Space  | | Space  |  Alt   |   [    |   `    |   '    |   ]    |  End   |
   `--------------------------------------------------------------' `--------------------------------------------------------------'
   */
  [META] = LAYOUT(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,   _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,    
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PGUP,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, _______,   _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_PGDN,
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, KC_END 
  ),

  /* NUM
   ,--------------------------------------------------------------. ,--------------------------------------------------------------.
   |  Esc   |   7    |   8    |   9    |        |        | Insert | | Delete |   7    |   8    |   9    |        |        |  Bksp  |
   |--------+--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------+--------|
   |  Tab   |   4    |   5    |   6    |        |        | Adjust | | IME    |   4    |   5    |   6    |        |        |  Enter |
   |--------+--------+--------+--------+--------+--------+--------| |--------|--------+--------+--------+--------+--------+--------|
   |  LSft  |   1    |   2    |   3    |        |        |        | |        |   1    |   2    |   3    |        |        |  Sft   |
   |--------+--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------+--------|
   |  Ctrl  |   0    |  LAlt  | Print  |  Code  |   Fn   | Space  | | Space  |   0    |   [    |   `    |   '    |   ]    |   \    |
   `--------------------------------------------------------------' `--------------------------------------------------------------'
   */
  [NUM] = LAYOUT(
    _______, KC_7,    KC_8,    KC_9,    _______, _______, _______,   _______,  KC_7,   KC_8,    KC_9,    _______, _______, _______,
    _______, KC_4,    KC_5,    KC_6,    _______, _______, _______,   _______,  KC_4,   KC_5,    KC_6,    _______, _______, _______,
    _______, KC_1,    KC_2,    KC_3,    _______, _______, _______,   _______,  KC_1,   KC_2,    KC_3,    _______, _______, _______,
    _______, KC_0,    _______, _______, _______, _______, _______,   _______,  KC_0,   _______, _______, _______, _______, _______
  ),

  /* ADJ
   * 
   * meta Layer
   */
  [ADJ] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______, _______, CK_EnUS, CK_EnJIS
  )
};




// -------- EEPROM functions --------

// impl: custom_keymap.h
void load_persistent(void) {
    user_config.raw = eeconfig_read_user();
}

// impl: custom_keymap.h
void save_persistent(void) {
    eeconfig_update_user(user_config.raw);
}

// impl: eeconfig.h
void eeconfig_init_user(void) {
    save_persistent();
}

// impl: eeconfig.h
void keyboard_post_init_user(void) {
    if (is_keyboard_master()) {
        load_persistent();
    }
}


// -------- Keyboard functions --------

// impl: custom_keymap.h
void set_keyboard_lang_to_jis(bool set_jis){
  if ( user_config.jis == set_jis){ return; }
	if (set_jis){
    user_config.jis = 1;
  } else {
    user_config.jis = 0;
  }
  save_persistent();
}

/*
 * Interrupt sending keycode to PC.
 *   - US to JIS keycodes. See https://github.com/tttza/qmk_firmware/blob/custom/lily58/keyboards/lily58/keymaps/via_tttza
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CK_EnJIS: // Chabana1591: write UserSetting to_jis to EEPROM.
        set_keyboard_lang_to_jis(true);
        return false;
    case CK_EnUS: // Chabana1591: write UserSetting to_jis to EEPROM.
        set_keyboard_lang_to_jis(false);
        return false;
    default:
      if (user_config.jis){ // Chabana1591: Replace keycodes from US to JIS.
          return twpair_on_jis(keycode, record); // See twpair_on_jis.c
      } else {
          return true;
      }
  }
}






