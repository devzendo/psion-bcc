/*
  File: ATS.H
  Copyright (C) Psion PLC 1993
  Started by : DavidW
  Started on:  12/02/93
*/

#define ATS_H

#ifndef P_STD_H
#include <p_std.h>
#endif

#ifndef EPOC_H
#include <epoc.h>
#endif

typedef struct
    {
    UWORD main;
    UWORD mainlen;
    UWORD buts;
    WORD butslen;
    } ATS_DIAL_DEF;

typedef struct
    {
    UWORD key;
    UWORD mod;
    } ATS_KEY_DEF;

typedef union
    {
    UWORD position;
    ATS_KEY_DEF k;
    ATS_DIAL_DEF d;
    UWORD delay;
    VOID *offs;
    WORD par;
    UWORD wid;
    } ATS_MESS_BODY;

typedef struct
    {
    E_MESSAGE mess;
    ATS_MESS_BODY u;
    } ATS_MESS;

#define TY_ATS_CLIENT_POS   0x30
#define TY_ATS_KEY          0x31
#define TY_ATS_PAUSE        0x32
#define TY_ATS_MESSAGE      0x33
#define TY_ATS_DIALOG       0x34
#define TY_ATS_SELF_CHECK   0x35
#define TY_ATS_WINDOW_XSUM  0x36
#define TY_ATS_RECORD       0x37
#define TY_ATS_GET_KEY      0x38
#define TY_ATS_ALLCOUNT     0x39

#define TY_ATS_START_RANGE  0x30
#define TY_ATS_END_RANGE    0x3f

typedef struct
    {
    UWORD time;
    UWORD keycode;
    UBYTE modifiers;
    UBYTE count;
    } ATS_KEY;

#define ATS_MAX_EDITOR_LEN      256     /* includes trailing zero */
