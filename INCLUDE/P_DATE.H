/*	HEADER - P_DATE.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_DATE_H
#include <stdepoc.h>
#define P_NSECDAY 86400l /* number of seconds in a day */
/* 
Convert day since 1900 to day in week, Monday=0
*/
#define P_WEEK(d) ((INT)((d)%7)) /* JAN 1 1900 was a Monday */
typedef struct
    {
    unsigned long int day; /* day number since 1900, up to 2155, 0 to approx 93000 */
    unsigned long int sec; /* seconds in day, 0 to 86399 */
    } P_DAYSEC;
typedef struct
    {
    unsigned char year; /* Year - 1900 */
    unsigned char month; /* Month number in year, 0 to 11 */
    unsigned char day; /* Day number in month, 0 to 30 */
    unsigned char hour; /* Hour in day, 0 to 23 */
    unsigned char minute; /* Minute in hour, 0 to 59 */
    unsigned char second; /* Second in minute, 0 to 59 */
    unsigned short int yrday; /* day in year */
    } P_DATE;
#ifdef __cplusplus
extern "C" {
#endif
#pragma save,call(reg_param =>(si,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_dstodt(const P_DAYSEC *,P_DATE *);
extern int p_dttods(const P_DATE *,P_DAYSEC *);
#pragma call(reg_param =>(si,di),reg_saved =>(cx,dx,si,di,EPOC_SAVE))
extern int p_dstost(const P_DAYSEC *,unsigned long int *);
#pragma call(reg_param =>(bx,di),reg_saved =>(bx,si,di,EPOC_SAVE))
extern void p_sttods(const unsigned long int *,P_DAYSEC *);
#pragma call(reg_param =>(di,si,bx,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_dt2str(char *str,const char *fmt,const P_DATE *dt);
extern int p_ds2str(char *str,const char *fmt,const P_DAYSEC *ds);
extern int p_now2str(char *str,const char *fmt);
extern int p_st2str(char *str,const char *fmt,const unsigned long int *st);
#pragma restore
#ifdef __cplusplus
}
#endif


