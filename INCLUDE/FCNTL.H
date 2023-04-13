/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  fcntl.h -  definitions for opening files.                               *
*                                                                          *
*  COPYRIGHT (C) 1989 Jensen and Partners. All Rights Reserved             *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _FCNTL_INC_
#define _FCNTL_INC_

extern unsigned  _fmode;

/* Flag values for open  */

#define O_RDONLY	     0
#define O_WRONLY	     1
#define O_RDWR		     2

#define O_CREAT		0x0100	/* create and open file */
#define O_TRUNC		0x0200	/* open with truncation */
#define O_EXCL		0x0400	/* exclusive open */

#define _O_EOF		0x0200 /* set when text file hits ^Z   */

/* A file in append mode may be written to only at its end. */

#define O_APPEND	0x0800	/* to end of file */

/* File mode special bits. User may only read these bits */

#define O_CHANGED	0x1000	/* File has been written */
#define O_DEVICE	0x2000	/* user read only flag	 */
#define O_TEXT		0x4000	/* CR-LF translation	*/
#define O_BINARY	0x8000	/* no translation	*/

/* DOS 3.x file sharing options */

#define SH_NOINHERIT	 0x80
#define SH_COMPAT	 0x00
#define SH_DENYRW	 0x10
#define SH_DENYWR	 0x20
#define SH_DENYRD	 0x30
#define SH_DENYNO	 0x40

#define SH_DENYNONE	SH_DENYNO     /* MS documentation uses both */
#endif
