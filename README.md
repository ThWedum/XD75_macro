# XD75_macro
Edited the keyboard layout of my XD75 to work as a secondary macro board.
I've added some extra description in the keymap.c file. Please read it before trying to use my keymap.
Made using:
1. QMK Unicode support https://beta.docs.qmk.fm/using-qmk/software-features/feature_unicode
  Using this keyboard on a windows computer together with "WinCompose" to get the unicode to work. 
2. QMK Macro support https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_macros
  Used SEND_STRING to achieve formulas made for Word Equations

Where to place different files in QMK structure:

keymap.c -> qmk_firmware\keyboards\xd75\keymaps\[KEYBOARD_NAME]

config.h -> qmk_firmware\keyboards\xd75\keymaps\[KEYBOARD_NAME]

rules.mk -> qmk_firmware\keyboards\xd75

process_unicodemap.c -> qmk_firmware\quantum\process_keycode
