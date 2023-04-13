/*      HEADER - WR_IO.H
World structures and constants.
Copyright (c) Psion PLC 1991.

 VER	DATE	BY  DESCRIPTION
----- -------- ---- -----------
1.00F			NSM	Final release
2.00A  1/6/93	MHS	S3B release
*/
#define WR_IO_H
#ifndef P_GRAF_H
#include <p_graf.h>
#endif
#ifndef P_GEN_H
#include <p_gen.h>
#endif
#ifndef EPOC_H
#include <epoc.h>
#endif
#define WR_FIND_CITY 10
#define WR_FIND_COUNTRY 11
#define WR_FIND_EXACT 12
#define WR_NEXT 13
#define WR_BACK 14
#define WR_GET_HOME 15
#define WR_SET_HOME 16
#define WR_GET_DEFAULT_COUNTRY 17
#define WR_SET_DEFAULT_COUNTRY 18
#define WR_GET_DIAL_STRING 19
#define WR_EXTRA 20
#define WR_SET_EXTRA 21
#define WR_GET_CITY_DATA 22
#define WR_GET_COUNTRY_DATA 23
#define WR_CALC 24
#define WR_NEXT_LOCK 25
#define WR_GET_DIAL_STRING_B 26

#define WR_MAX_NAME 20
#define WR_MAX_DIAL 16
#define WR_MAX_CODE 8
#define WR_MAX_INTRA 4
#define WR_MAX_INTER 4
#define WR_MAX_DIAL_STRING 24
/* new (S3B) max length of output string 40 - E_MAX_DTMF_DIAL_B */
#define WR_MAX_DIAL_STRING_B 40
#define WR_MAX_IN_STRING 64

#define WR_UNITS_MILES 0
#define WR_UNITS_KILOMETERS 1
#define WR_UNITS_NAUTICAL 2

#define WR_START_STATE 1
#define WR_END_STATE 0

#define WR_HOME_DONE 0
#define WR_HOME_SET 1
#define WR_HOME_DOING 2

#define WR_NOT_FOUND E_GEN_FAIL
#define WR_FOUND 0

#define WR_EXTRA_ADD_CITY 0
#define WR_EXTRA_UPDATE_CITY 1
#define WR_EXTRA_DELETE_CITY 2
#define WR_EXTRA_UPDATE_COUNTRY 3
#define WR_EXTRA_ADD_HOME 4

#define WR_DELETED 0
#define WR_REVERTED 1

#define WR_TOO_MANY_ERR -23
#define WR_NOTVALID_ERR -25
#define WR_DELHOME_ERR -26
#define WR_DELCAPITAL_ERR -27
#define WR_DUPLICATE_ERR -28

typedef struct /* Lat long */
	{
	WORD  iLat;
	WORD  iLong;
	} LATL;

typedef struct
	{
	TEXT city[WR_MAX_NAME+1];
	TEXT country[WR_MAX_NAME+1];
	} WR_FIND_RES;

typedef struct
	{
	WR_FIND_RES f;
	UBYTE units; /* Also baseGMT */
	UBYTE DST;
	WORD GMT;
	LATL latl;
	TEXT dial[WR_MAX_DIAL+1];
	TEXT STD[WR_MAX_CODE+1];
	P_POINT pos;
	} WR_CITY_DATA;

typedef struct
	{
	TEXT dialIntra[WR_MAX_INTRA+1];
	TEXT dialInter[WR_MAX_INTER+1];
	TEXT dial[WR_MAX_CODE+1];
	UBYTE dummy;
	} CO_DIAL;

typedef struct
	{
	WR_FIND_RES f;
	BYTE baseGMT;
	UBYTE DST;
	WORD GMT;
	CO_DIAL dial;
	} WR_COUNTRY_DATA;

typedef union
	{
	WR_CITY_DATA ci;
	WR_COUNTRY_DATA co;
	} WR_EXTRA_DATA;

typedef struct
	{
	WORD distance;
	WORD sunRise;
	WORD sunSet;
	WORD always;
	} WR_CALC_OUT;

typedef union
	{
	WR_CITY_DATA in;
	WR_CALC_OUT out;
	} WR_CALC_DATA;

typedef struct
	{
	UWORD time;
	UWORD date;
    UWORD amPm;
	} TIMEDATE;

