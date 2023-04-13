/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  types.h -  common types                                                 *
*                                                                          *
*  COPYRIGHT (C) 1988 Jensen and Partners. All Rights Reserved             *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _INO_DEF
typedef unsigned short ino_t;       /* i-node number */
#define _INO_DEF
#endif

#ifndef _TIME_DEF
typedef long time_t;
#define _TIME_DEF
#endif

#ifndef _DEV_DEF
typedef short dev_t;                /* device code */
#define _DEV_DEF
#endif

#ifndef _OFF_DEF
typedef long off_t;                 /* file offset value */
#define _OFF_DEF
#endif

