/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  stddef.h -  definitions of common types.                                *
*                                                                          *
*  COPYRIGHT (C) 1989 Jensen and Partners. All Rights Reserved             *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _STDDEF_INC_
#define _STDDEF_INC_

#ifndef _PTRDIFF_T
    #define _PTRDIFF_T
    typedef int ptrdiff_t;
#endif

#ifndef _SIZE_T
    #define _SIZE_T
    typedef unsigned size_t;
#endif


#ifndef _WCHAR_T
    #define _WCHAR_T
    typedef unsigned char wchar_t;
#endif

#ifndef _OFFSETOF_M
    #define _OFFSETOF_M
    #define offsetof(st, member) (size_t)(&((st*)0)->member)
#endif

#ifndef NULL
#define NULL   0
#endif

#endif
