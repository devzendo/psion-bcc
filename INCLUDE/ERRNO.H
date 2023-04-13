/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  errno.h -  defines variable errno and associated error codes.           *
*                                                                          *
*  COPYRIGHT (C) 1989 Jensen and Partners. All Rights Reserved             *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _ERRNO_INC_
#define _ERRNO_INC_

/*  Dos Error Codes */

#ifdef OLDERRORS
#define EZERO	  0		/* No Error			*/
#define EINVFN	  1		/* Invalid function code	*/
#define ENOENT	  2		/* File not found		*/
#define ENOPATH   3		/* Path not found		*/
#define EMFILE	  4		/* Too many open files		*/
#define EACCES	  5		/* Access denied		*/
#define EBADF	  6		/* Invalid handle		*/
#define E2BIG	  7		/* Memory blocks destroyed	*/
#define ENOMEM	  8		/* Insufficient Memory		*/
#define EINVMEM   9		/* Invalid memory block address */
#define EINVENV   10		/* Invalid environment		*/
#define EINVFMT   11		/* Invalid format		*/
#define EINVACC   12		/* Invalid access code		*/
#define EINVDAT   13		/* Invalid data 		*/
#define ENODEV	  15		/* Invalid drive		*/
#define ECURDIR   16		/* Attempt to remove CurDir	*/
#define ENOTSAM   17		/* Not same device		*/
#define ENMFILE   18		/* No more files		*/

/* RTL error codes */

#define EINVAL	  19		/* Invalid argument		*/
#define ENOTDIR   20		/* Not directory		*/
#define EISDIR	  21		/* Is directory 		*/
#define ENOEXEC   22		/* Corrupted exec file		*/
#define EMLINK	  32		/* Cross-device link		*/

#define EDOM	  33		/* Math argument		*/
#define ERANGE	  34		/* Result too large		*/
#define EDEADLOCK 36		/* file locking deadlock	*/
#define EEXIST    80            /* File exists MSDOS 3.0 +      */
#define ENOSPC	   -1		/* UNIX - not in  MSDOS 	*/
#else
#define EZERO	  0		/* No Error			*/
#define ENOENT	  (-33)		/* File not found		*/
#define ENOPATH   (-42)		/* Path not found		*/
#define EMFILE	  (-18)		/* Too many open files		*/
#define EACCES	  (-39)		/* Access denied		*/
#define EBADF	  (-15)		/* Invalid handle		*/
#define E2BIG	  (-6)		/* Memory blocks destroyed	*/
#define ENOMEM	  (-10)		/* Insufficient Memory		*/
#define ENODEV	  (-41)		/* Invalid drive		*/
#define ECURDIR   (-9)		/* Attempt to remove CurDir	*/
#define ENMFILE   (-36)		/* No more files		*/
#define ENOSPC	  (-37)		/* Disk full */

/* RTL error codes */

#define EINVAL	  (-2)		/* Invalid argument		*/
#define ENOEXEC   (-16)		/* Corrupted exec file		*/
#define EMLINK	  (-66)		/* Cross-device link		*/

#define EDOM	  (-2)		/* Math argument		*/
#define ERANGE	  (-7)		/* Result too large		*/
#define EDEADLOCK (-40)		/* file locking deadlock	*/
#define EEXIST    (-32)         /* File exists MSDOS 3.0 +      */

#define ENOTSAM   (-1)		/* Not same device		*/
#define ENOTDIR   (-1)		/* Not directory		*/
#define EISDIR	  (-1)		/* Is directory 		*/
#define EINVFN	  (-1)		/* Invalid function code	*/
#define EINVMEM   (-1)		/* Invalid memory block address */
#define EINVENV   (-1)		/* Invalid environment		*/
#define EINVFMT   (-1)		/* Invalid format		*/
#define EINVACC   (-1)		/* Invalid access code		*/
#define EINVDAT   (-1)		/* Invalid data 		*/
#endif

#define EFAULT	   (-1)		/* Unknown error		*/
#define EPERM	   (-1)		/* UNIX - not in  MSDOS 	*/
#define ESRCH	   (-1)		/* UNIX - not in  MSDOS 	*/
#define EINTR	   (-1)		/* UNIX - not in  MSDOS 	*/
#define EIO	   (-1)		/* UNIX - not in  MSDOS 	*/
#define ENXIO	   (-1)		/* UNIX - not in  MSDOS 	*/
#define ECHILD	   (-1)		/* UNIX - not in  MSDOS 	*/
#define EAGAIN	   (-1)		/* UNIX - not in  MSDOS 	*/
#define ENOTBLK    (-1)		/* UNIX - not in  MSDOS 	*/
#define EBUSY	   (-1)		/* UNIX - not in  MSDOS 	*/
#define ENFILE	   (-1)		/* UNIX - not in  MSDOS 	*/
#define ENOTTY	   (-1)		/* UNIX - not in  MSDOS 	*/
#define ETXTBSY    (-1)		/* UNIX - not in  MSDOS 	*/
#define EFBIG	   (-1)		/* UNIX - not in  MSDOS 	*/
#define ESPIPE	   (-1)		/* UNIX - not in  MSDOS 	*/
#define EROFS	   (-1)		/* UNIX - not in  MSDOS 	*/
#define EPIPE	   (-1)		/* UNIX - not in  MSDOS 	*/
#define EUCLEAN    (-1)		/* UNIX - not in  MSDOS 	*/

extern int _doserrno;          /* global DOS error variable */
extern int errno;              /* global error variable */

#endif
