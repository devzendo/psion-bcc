/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  values.h -  Value ranges for common data types.			   *
*                                                                          *
*  COPYRIGHT (C) 1988 Jensen and Partners. All Rights Reserved. 	   *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _VALUES_INC_
#define _VALUES_INC_

#define MAXCHAR		      127
#define MINCHAR	             -128
#define MAXUCHAR              255
#define MINUCHAR	        0
#define MAXSHORT            32767
#define MINSHORT     ((-32767)-1)
#define MAXINT		    32767
#define MININT	     ((-32767)-1)
#define MAXUINT		    65535U
#define MINUINT		        0
#define MAXLONG	       2147483647L
#define MINLONG	((-2147483647L)-1)
#define MAXULONG       4294967295UL
#define MINULONG	        0
#define DMAXEXP		      308
#define FMAXEXP		       38
#define DMINEXP              -307
#define FMINEXP	              -37
#define MAXDOUBLE   1.797693e+308
#define MAXFLOAT     3.402823e+38
#define MINDOUBLE   2.225074e-308
#define MINFLOAT     1.175494e-38

#endif
