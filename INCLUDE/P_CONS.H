/*	HEADER - P_CONS.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_CONS_H
#include <stdepoc.h>
#ifndef P_GRAF_H
#include <p_graf.h>
#endif
typedef struct
{
unsigned int window_handle;
unsigned int font_handle;
unsigned int line_height;
unsigned int char_width;
} CONSOLE_INFO;
typedef struct
{
unsigned short int code;
unsigned char modifier_mask;
unsigned char dont_care_mask;
} CONSOLE_CAPTURE_KEY;
typedef struct
{
unsigned short int id;
unsigned short int style;
} P_SCR_SET_FONT;
typedef struct
{
P_EXTENT extent;
P_SCR_SET_FONT font;
} P_SCR_SET_FONT_EXT;
#ifndef _P_CON_KBREC
#define _P_CON_KBREC
typedef struct
{
unsigned short int keycode;
unsigned char modifiers;
unsigned char count;
} P_CON_KBREC;
#endif
#define P_MAXEDITSTR  256
#ifndef _P_CEDIT
#define _P_CEDIT
typedef struct
{
unsigned char cursorpos;
unsigned char trap;
unsigned char string[P_MAXEDITSTR];
} P_CEDIT;
#endif
#define CONS_SPECIAL_EVENT 0x4
#define CONS_EVENT_FOREGROUND ((CONS_SPECIAL_EVENT*256)+1)
#define CONS_EVENT_BACKGROUND ((CONS_SPECIAL_EVENT*256)+2)
#define CONS_EVENT_ON_OFF ((CONS_SPECIAL_EVENT*256)+3)
#define CONS_EVENT_COMMAND ((CONS_SPECIAL_EVENT*256)+4)
#define CONS_EVENT_DATE_CHANGED ((CONS_SPECIAL_EVENT*256)+5)
#define CONS_EVENT_OTHER ((CONS_SPECIAL_EVENT*256)+255)
#define P_SCR_NORMAL 0
#define P_SCR_BOLD 0x01
#define P_SCR_REVERSE 0x02
#define P_SCR_UNDLINE 0x04
#define P_SCR_BLINK 0x08
#define P_SCR_ITALIC 0x10
#define P_SCR_ATTRB 0
#define P_SCR_SCROLL 1
#define P_SCR_CLR 2
#define P_SCR_POSA 3
#define P_SCR_POSR 4
#define P_SCR_WSET 5
#define P_SCR_SLOCK 6
#define P_SCR_WLOCK 7
#define P_SCR_NEL 8
#define P_SCR_CURSOR 9
#define P_SCR_ESCAPE 10
#define P_SCR_FLUSH 11
#define P_SCR_CSET 12
#define P_SCR_CAPTURE_KEY 13
#define P_SCR_CANCEL_CAPTURE_KEY 14
#define P_SCR_CLIENT_FOREGROUND 15
#define P_SCR_LAST_LINE_WRAP 16
#define P_SCR_FONT 17
#define P_SCR_DISABLE_READS 18
#define P_SCR_SET_PRIORITY_CONTROL 19
#define P_SCR_COMPATIBILITY  20
#define P_SCR_GREY           21
#define P_SCR_FONT_EXT       22
#define P_FWFLUSH P_FRSUPER
#define P_EVENT_READ P_FSTOP
#define P_EVENT_TEST P_FSTART
