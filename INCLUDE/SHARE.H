/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  share.h -  header file for file sharing used with sopen.                *
*                                                                          *
*  COPYRIGHT (C) 1989 Jensen and Partners. All Rights Reserved             *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _SHARE_INC_
#define _SHARE_INC_

#define SH_NOINHERIT	0x80
#define SH_COMPAT	0x00
#define SH_DENYRW	0x10
#define SH_DENYWR	0x20
#define SH_DENYRD	0x30
#define SH_DENYNO	0x40

#define SH_ALL          0xF0

#define SH_DENYNONE	SH_DENYNO     /* MS documentation uses both */
#endif
