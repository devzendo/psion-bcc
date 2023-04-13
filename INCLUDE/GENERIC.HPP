/* Release 3.10 */
/*-------------------------------------------------------------------------*
*                                                                          *
*  GENERIC.HPP -  header file for creating generic classes.                *
*                                                                          *
*  COPYRIGHT (C) 1990..1992 Clarion Software Corporation                   *
*  All Rights Reserved                                                     *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _GENERIC_INC_
#define _GENERIC_INC_

#define _PASTE2(x, y)          _PASTE2_x(x, y)
#define _PASTE2_x(x, y)        x##y
#define _PASTE3(x, y, z)       _PASTE3_x(x, y, z)
#define _PASTE3_x(x, y, z)     x##y##z
#define _PASTE4(w, x, y, z)    _PASTE4_x(w, x, y, z)
#define _PASTE4_x(w, x, y, z)  w##x##y##z

#define _ALT_PASTE2(x, y)          _ALT_PASTE2_x(x, y)
#define _ALT_PASTE2_x(x, y)        x##y
#define _ALT_PASTE3(x, y, z)       _ALT_PASTE3_x(x, y, z)
#define _ALT_PASTE3_x(x, y, z)     x##y##z
#define _ALT_PASTE4(w, x, y, z)    _ALT_PASTE4_x(w, x, y, z)
#define _ALT_PASTE4_x(w, x, y, z)  w##x##y##z

// macros for the declaration and implementation of classes
#define declare(x, y)       _PASTE2(x, declare)(y)
#define implement(x, y)     _PASTE2(x, implement)(y)
#define declare2(x, y, z)   _PASTE2(x, declare2)(y, z)
#define implement2(x, y, z) _PASTE2(x, implement2)(y, z)

// macros for the declaration of error-handling functions

extern genericerror(int, char*);
typedef int (*GPT)(int, char*);
#define set_handler(generic, type, x)  _PASTE4(set_, type, generic, _handler)(x)
#define errorhandler(generic, type)    _PASTE3(type, generic, handler)
#define callerror(generic, type, x, y) (*errorhandler(generic, type))(x, y)

#define name2(x, y) _ALT_PASTE2_x(x, y)
#define name3(x, y, z) _ALT_PASTE3_x(x, y, z)
#define name4(w, x, y, z) _ALT_PASTE4_x(w, x, y, z)

#endif
