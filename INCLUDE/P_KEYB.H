/*	HEADER - P_KEYB.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_KEYB_H
#include <stdepoc.h>
#ifndef _P_CON_KBREC
#define _P_CON_KBREC
typedef struct
{
unsigned short int keycode; /* Code for the key pressed */ 
unsigned char modifiers; /* A bit set for each modifier key held down */ 
unsigned char count;
} P_CON_KBREC;
#endif

