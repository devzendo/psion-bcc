/*	HEADER - P_SCREEN.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_SCREEN_H
#include <stdepoc.h>
#ifndef P_GRAF_H
#include <p_graf.h>
#endif
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
#define P_SCR_NORMAL 0
#define P_SCR_BOLD 0x01
#define P_SCR_REVERSE 0x02
#define P_SCR_UNDLINE 0x04
#define P_SCR_BLINK 0x08
#define P_MAXEDITSTR  256
#define P_FEDIT   P_FCTRL   /* invoke consol edit */ 
#define P_FCONSP1  P_FINQ   /* consol spare 1 */ 
#define P_FCONSP2  P_FRSUPER  /* consol spare 2 */ 
#define P_FCONSP3  P_FSTOP   /* consol spare 3 */ 
#define P_FCONSP4  P_FSTART   /* consol spare 4 */ 
#define P_FWFLUSH   P_FRSUPER
#define P_EVENT_READ P_FSTOP
#define P_EVENT_TEST P_FSTART
#ifndef _P_CEDIT
#define _P_CEDIT
typedef struct /* console driver line editor */ 
{
unsigned char cursorpos;  /* initial cursor position */ 
unsigned char trap;     /* trap input errors or not */ 
unsigned char string[P_MAXEDITSTR]; /* buffer to edit */ 
} P_CEDIT;
#endif
typedef struct /* line editor control block */ 
{
unsigned char *le_scb; /* screen control block */ 
P_RECT le_win; /* window dimensions (relative) */ 
char *le_buf; /* edit buffer */ 
unsigned char le_len; /* length of edit text */ 
unsigned char le_max; /* max length of edit text */ 
unsigned char le_pos; /* position of cursor in buffer */ 
unsigned char spare; /* keep struct word aligned */ 
} P_LECB;
#define P_LE_LEFT    0
#define P_LE_RIGHT   1
#define P_LE_UP     2
#define P_LE_DOWN    3
#define P_LE_START   4
#define P_LE_END    5
#define P_LE_DELETE   6
#define P_LE_CLR    7
