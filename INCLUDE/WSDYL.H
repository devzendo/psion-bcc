/*	HEADER - WSDYL.H
Copyright (C) Psion PLC 1991
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
*/
#ifndef WSDYL_H
#define WSDYL_H
#include <stdepoc.h>
#ifndef P_GRAF_H
#include <p_graf.h>
#endif
#ifndef P_OBJECT_H
#include <p_object.h>
#endif
typedef struct
{
P_OBJECT obj;
P_RECT total;
P_RECT clip;
P_RECT workrect;
/*
The following three elements are grouped together to match the layout of
the unpublished BM_DATA structure.
*/
unsigned short int seg;
unsigned char *addr;
unsigned short int bytewid;
unsigned short int trmode;
short int x_offset;
short int y_offset;
unsigned char *work_space;
unsigned char *user_handle;
P_POINT *alt_offset;
unsigned short int bitmap_segment;
P_POINT size;
unsigned char *bitmap_addr;
unsigned int osdataseg;
unsigned char *reply_addr;
unsigned int reply_len;
} DYL_CALL;
#endif

