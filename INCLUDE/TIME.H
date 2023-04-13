/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  time.h - structure and function definitions for time.                   *
*                                                                          *
*  COPYRIGHT (C) 1989 Jensen and Partners. All Rights Reserved             *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _TIME_INC_
#define _TIME_INC_

#ifndef  _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

#ifndef _TIME_T
#define _TIME_T
#ifndef _TIME_DEF
#define _TIME_DEF
typedef long  time_t;
#endif
typedef long  clock_t;
#define CLK_TCK 100
#define CLOCKS_PER_SEC 100
#endif

#ifndef NULL
#define NULL   0
#endif

#ifndef _TM_DEF
#define _TM_DEF
struct  tm   {
   int  tm_sec;
   int  tm_min;
   int  tm_hour;
   int  tm_mday;
   int  tm_mon;
   int  tm_year;
   int  tm_wday;
   int  tm_yday;
   int  tm_isdst;
};
#endif

#ifndef _TMT_DEF
#define _TMT_DEF
struct date {
    int da_year;
    unsigned char da_day;
    unsigned char da_mon;
};

struct time {
    unsigned char ti_hour;
    unsigned char ti_min;
    unsigned char ti_sec;
    unsigned char ti_hund;
};
#endif

#ifndef _UTMT_DEF
#define _UTMT_DEF
struct utm {  int u_sec;
              int u_min;
	      int u_hour;
	      int u_day;
              int u_mon;
	      int u_year;
};
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern char *       asctime(const struct tm *_tblock);
extern char *       ctime(const time_t *_timer);
extern clock_t      clock(void);
extern double       difftime(time_t _time2, time_t _time1);
extern struct tm *  gmtime(const time_t *_timer);
extern struct tm *  localtime(const time_t *_timer);
extern time_t       mktime(struct tm *_timeptr);
extern size_t       strftime(char *_s, size_t _maxsize, const char *_format,
                      const struct tm *_timeptr);
extern time_t       time(time_t *_timer);
extern int          stime(time_t *_tp);
extern void         tzset(void);
extern void         settime(const struct time *_tptr);
extern void         gettime(struct time *_tptr);
extern void         setdate(const struct date *_dptr);
extern void         getdate(struct date *_dptr);
extern char *       _strdate(char *_dt);
extern char *       _strtime(char *_tm);
extern int          utime(char *_path, struct utm *_time);
extern time_t       get_utime(int _handle);
extern int          _filetime(int _handle, struct utm *_ubuf);
#ifdef __cplusplus
}
#endif

extern time_t  timezone;
extern int daylight;
#endif
