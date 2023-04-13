/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  timeb.h -  header file for ftime.                                       *
*                                                                          *
*  COPYRIGHT (C) 1989, 1990 Jensen and Partners. All Rights Reserved.      *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _TIMEB_INC_
#define _TIMEB_INC_

#ifndef _TIME_DEF
#define _TIME_DEF
typedef long  time_t;
#endif

/* structure returned by ftime */

struct timeb {
    time_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
};

#ifdef __cplusplus
extern "C" {
#endif
extern void ftime(struct timeb *);
#ifdef __cplusplus
}
#endif
#endif
