/* Release 3.00 */

/*----------------------------------------------------------------------------*
*									      *
*	 stat.h -  Definitions used for file status functions		      *
*									      *
*	 Copyright (c) 1989, 1990 Jensen and Partners. All Rights Reserved.   *
*									      *
*-----------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _STAT_INC_
#define _STAT_INC_

#ifndef _STAT_H
#define _STAT_H

#define S_IFMT  0170000  /* file type mask */
#define S_IFDIR  0x4000  /* directory */
#define S_IFCHR  0x2000  /* character device */
#define S_IFREG  0x8000  /* regular file */
#define S_IREAD  0x0100  /* owner may read */
#define S_IWRITE 0x0080  /* owner may write */
#define S_IEXEC  0x0040  /* owner may execute <directory search> */

struct  stat {
    short st_dev;
    short st_ino;
    short st_mode;
    short st_nlink;
    int   st_uid;
    int   st_gid;
    short st_rdev;
    long  st_size;
    long  st_atime;
    long  st_mtime;
    long  st_ctime;
};

#ifdef __cplusplus
extern "C" {
#endif
extern int   fstat (int _handle, struct stat *_statbuf);
extern int   stat  (const char *_path, struct stat *_statbuf);
#ifdef __cplusplus
}
#endif
#endif
#endif

