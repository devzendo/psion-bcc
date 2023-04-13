/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  dir.h -  structure and function definitions for MSDOS pathnames	   *
*  and directories.                                                        *
*                                                                          *
*  COPYRIGHT (C) 1989, 1990 Jensen and Partners. All Rights Reserved.      *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _DIR_INC_
#define _DIR_INC_

#ifdef __cplusplus
extern "C" {
#endif
extern int	  chdir(const char *_path);
extern int	  getcurdir(int _drive, char *_buf);
extern char	* getcwd(char *_buf, int _maxlen);
extern int	  _getdrive(void);
extern int	  mkdir(const char *_path);
extern int	  rmdir(const char *_path);
#ifdef __cplusplus
}
#endif

#define WILDCARDS  0x01
#define EXTENSION  0x02
#define FILENAME   0x04
#define DIRECTORY  0x08
#define DRIVE      0x10

#define MAXPATH      80
#define MAXDRIVE      4
#define MAXDIR	     66
#define MAXFILE       9
#define MAXEXT	      5

#ifndef _FFBLK_DEF
#define _FFBLK_DEF

struct ffblk {
    char ff_reserved[21];
    char ff_attrib;
    int  ff_ftime;
    int  ff_fdate;
    long ff_fsize;
    char ff_name[13];
};
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern int     findfirst(const char *_path, struct ffblk *_ffblk,int _attrib);
extern int     findnext(struct ffblk *_ffblk);
extern void    fnmerge(char *_path, const char *_drive,const char *_dir,
                const char *_name, const char *_ext);
extern int     fnsplit(const char *_path, char *_drive, char *_dir,
	        char *_name, char *_ext);
extern void    _makepath(char *_path, const char *_drive, const char *_dir,
	          const char *_name, const char *_ext);
extern void    _splitpath(const char *_path, char *_drive, char *_dir,
                   char *_name, char *_ext);
extern int     getdisk(void);
extern char *  searchpath(const char *_path);
extern int     setdisk(int _drive);
#ifdef __cplusplus
}
#endif
#endif
