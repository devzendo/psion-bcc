/* Release 3.10 */
/*-------------------------------------------------------------------------*
*                                                                          *
*  NEW.H -  header file for C++ memory allocation operators.               *
*                                                                          *
*  COPYRIGHT (C) 1990..1992 Clarion Software Corporation                   *
*  All Rights Reserved                                                     *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _NEW_INC_
#define _NEW_INC_

#include <stddef.h>

extern void (* set_new_handler(void(*)()))();

void *   operator new(size_t _size, void *_place);

#endif
