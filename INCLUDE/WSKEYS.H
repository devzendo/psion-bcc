/*	HEADER - WSKEYS.H
Copyright (C) Psion PLC 1991
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
*/
#ifndef WSKEYS_H
#define WSKEYS_H

#define W_SHIFT_MODIFIER    0x02
#define W_CTRL_MODIFIER     0x04
#define W_PSION_MODIFIER    0x08
#define W_CAPS_MODIFIER     0x10
#define W_NUM_LOCK_MODIFIER 0x20
#define W_MOUSE_OUTSIDE     0x40
#define W_MOUSE_DOWN        0x80
#define W_FUNC_MODIFIER     0x80  /* Doubles up as mouse or func */
#define W_RUSSIAN_MODIFIER  0x1000

#define W_KEY_REPEATED      0x800
#define W_SPECIAL_KEY       0x0200

#define W_KEY_DELETE_LEFT   8
#define W_KEY_TAB           9
#define W_KEY_RETURN        13
#define W_KEY_ESCAPE        27
#define W_KEY_DELETE_RIGHT  127

#define W_KEY_UP        0x0100
#define W_KEY_DOWN      0x0101
#define W_KEY_RIGHT     0x0102
#define W_KEY_LEFT      0x0103
#define W_KEY_PAGE_UP   0x0104
#define W_KEY_PAGE_DOWN 0x0105
#define W_KEY_HOME      0x0106
#define W_KEY_END       0x0107
#define W_KEY_TASK      0x0108
#define W_KEY_VOICE     0x0109

#define W_KEY_CAPS_LOCK 0x010c

#define W_KEY_BACKLIGHT 0x120
#define W_KEY_INFO 0x121
#define W_KEY_MENU 0x122
#define W_KEY_HELP 0x123
#define W_KEY_DIAMOND 0x124

#define W_KEY_MODE 0x0130
#define W_KEY_APP1 0x0131
#define W_KEY_APP2 0x0132
#define W_KEY_APP3 0x0133
#define W_KEY_APP4 0x0134
#define W_KEY_APP5 0x0135
#define W_KEY_APP6 0x0136
#define W_KEY_APP7 0x0137
#define W_KEY_APP8 0x0138
#define W_KEY_APP9 0x0139

#define W_KEY_IR_BRING          0x0140
#define W_KEY_IR_SEND           0x0141
#define W_KEY_IR_LINK           0x0142

#define W_KEY_CALC_CLEAR        0x001b
#define W_KEY_CALC_MEM_CLEAR    0x0150
#define W_KEY_CALC_MEM_RECALL   0x0151
#define W_KEY_CALC_MEM_MINUS    0x0152
#define W_KEY_CALC_MEM_PLUS     0x0153
#define W_KEY_CALC_CHNG_SIGN    0x0154
#define W_KEY_CALC_PERCENT      0x0155
#define W_KEY_CALC_DECIMAL      0x0156
#define W_KEY_CALC_MEM_INPUT    0x0158

#define W_KEY_LCD 0x2000
#define W_KEY_LCD_MINUS 0x2001
#define W_KEY_ON 0x2002
#define W_KEY_OFF 0x2003

#define PERMITTED_MODS (W_SHIFT_MODIFIER+W_CTRL_MODIFIER+W_PSION_MODIFIER+W_MOUSE_DOWN+W_CAPS_MODIFIER+W_NUM_LOCK_MODIFIER)
#endif

