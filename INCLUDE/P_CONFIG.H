/*	HEADER - P_CONFIG.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_CONFIG_H
#include <stdepoc.h>
#define E_DATE_USA 0 /* MM/DD/YY */ 
#define E_DATE_EUROPE 1 /* DD/MM/YY */ 
#define E_DATE_JAPAN 2 /* YY/MM/DD */ 
#define E_CURRENCY_BEFORE 0
#define E_CURRENCY_AFTER 1
#define E_NOSPACE_BETWEEN 1
#define E_SPACE_BETWEEN 0
#define E_TIME_12 0
#define E_TIME_24 1
#define E_ANALOGUE_CLOCK 0
#define E_DIGITAL_CLOCK 1
#define E_DST_HOME 1
#define E_DST_EUROPEAN 2
#define E_DST_NORTHERN 4
#define E_DST_SOUTHERN 8
#define E_IMPERIAL 0
#define E_METRIC 1
#define P_LANGUAGE_TST 0 /* Test language */
#define P_LANGUAGE_ENG 1 /* English */
#define P_LANGUAGE_FRN 2 /* French */
#define P_LANGUAGE_GRM 3 /* German */
#define P_LANGUAGE_SPA 4 /* Spanish */
#define P_LANGUAGE_ITA 5 /* Italian */
#define P_LANGUAGE_SWE 6 /* Swedish */
#define P_LANGUAGE_DAN 7 /* Danish */
#define P_LANGUAGE_NOR 8 /* Norwegian */
#define P_LANGUAGE_FIN 9 /* Finnish */
#define P_LANGUAGE_USA 10 /* American */
#define P_LANGUAGE_SWF 11 /* Swiss french */
#define P_LANGUAGE_SWG 12 /* Swiss german */
#define P_LANGUAGE_POR 13 /* Portuguese */
#define P_LANGUAGE_TUR 14 /* Turkish */
#define P_LANGUAGE_ICE 15 /* Icelandic */
#define P_LANGUAGE_RUS 16 /* Russian */
#define P_LANGUAGE_HUN 17 /* Hungarian */
#define P_LANGUAGE_DUT 18 /* Dutch */
#define P_LANGUAGE_FLE 19 /* Belgian Flemish */
#define P_LANGUAGE_OZZ 20 /* Australian */
#define P_LANGUAGE_NZL 21 /* New Zealand */
#define P_LANGUAGE_OST 22 /* Austrian */
#define P_LANGUAGE_BEF 23 /* Belgian french */
#define P_MAX_LANGUAGES 24
typedef struct
{
unsigned short int countryCode;
short int gmtOffset; /* In minutes */ 
unsigned char dateType;
unsigned char timeType;
unsigned char currencySymbolPosition;
unsigned char currencySpaceRequired;
unsigned char currencyDecimalPlaces;
unsigned char currencyNegativeInBrackets;
unsigned char currencyTriadsAllowed;
unsigned char thousandsSeparator;
unsigned char decimalSeparator;
unsigned char dateSeparator;
unsigned char timeSeparator;
unsigned char currencySymbol[9];
unsigned char startOfWeek;
unsigned char summerTime;
unsigned char clockType;
unsigned char dayAbbreviation;
unsigned char monthAbbreviation;
unsigned char workDays;
unsigned char units;
unsigned char spare[9];
} E_CONFIG;
#pragma save,call(reg_param =>(bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
#ifdef __cplusplus
extern "C" {
#endif
extern void p_setctd(const E_CONFIG *);
extern void p_getctd(E_CONFIG *);
#pragma restore
#ifdef __cplusplus
}
#endif

