/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  stdarg.h - defines for ANSI macros for varaible argument functions      *
*                                                                          *
*  COPYRIGHT (C) 1989 Jensen and Partners. All Rights Reserved             *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _STDARG_INC_
#define _STDARG_INC_

#ifndef NULL
#define NULL   0
#endif

typedef  char  *va_list;

#define va_start(ap, plist) ap = (va_list)&plist + sizeof(plist)
#define va_arg(ap, t)       (*(t*)((ap += sizeof(t)+(sizeof(t)&1))-(sizeof(t)+(sizeof(t)&1))))
#define va_end(ap)          ap = NULL
#endif
