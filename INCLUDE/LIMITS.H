/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  limits.h -  Value ranges for common data types.			   *
*                                                                          *
*  COPYRIGHT (C) 1989 Jensen and Partners. All Rights Reserved. 	   *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _LIMITS_INC_
#define _LIMITS_INC_

#define CHAR_BIT	          8
#ifdef  __CHAR_UNSIGNED__
#define CHAR_MIN                  0
#define CHAR_MAX                255
#else
#define CHAR_MIN             (-128)
#define CHAR_MAX                127
#endif
#define MB_LEN_MAX                1
#define SCHAR_MAX               127
#define SCHAR_MIN            (-128)
#define UCHAR_MAX               255
#define SHRT_MAX              32767
#define SHRT_MIN         (-32767-1)
#define USHRT_MAX            65535U
#define INT_MAX               32767
#define INT_MIN          (-32767-1)
#define UINT_MAX            0xFFFFU
#define LONG_MAX        2147483647L
#define LONG_MIN   (-2147483647L-1)
#define ULONG_MAX      4294967295UL
#endif
