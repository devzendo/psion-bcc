/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  io.h -  Definitions for low level I/O functions.                        *
*                                                                          *
*  COPYRIGHT (C) 1989, 1990 Jensen and Partners. All Rights Reserved.      *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _IO_INC_
#define _IO_INC_

struct	ftime	{
	unsigned	ft_tsec	 : 5;	/* Two second interval */
	unsigned	ft_min	 : 6;	/* Minutes */
	unsigned	ft_hour	 : 5;	/* Hours */
	unsigned	ft_day	 : 5;	/* Days */
	unsigned	ft_month : 4;	/* Months */
	unsigned	ft_year	 : 7;	/* Year */
};

#define HANDLE_MAX	20U
#define SEEK_SET         0
#define SEEK_CUR         1
#define SEEK_END         2

extern unsigned _openfd[HANDLE_MAX];

#ifdef __cplusplus
extern "C" {
#endif
extern int      access(const char *_path, int _access);
extern int      chmod(const char *_path, int _mode);
extern int      _chmod(const char *_path, int _func, int _mode);
extern int      chsize(int _handle, long _size);
extern int      close(int _handle);
extern int      _close(int _handle);
extern int      creat(const char *_path, int _access);
extern int      _creat(const char *_path, int _permission);
extern int      _creat_trunc(const char *_path, int _permission);
extern int      creatnew(const char *_path, int _premission);
extern int      _creat_new(const char *_path, int _permission);
extern int      creattemp(const char *_path, int _permission);
extern int      _creat_temp(char *_path, int _permission);
extern int      dup(int _handle);
extern int      dup2(int _oldhandle, int _newhandle);
extern int      eof(int _handle);
extern int      _dup(int _handle);
extern int      _dup2(int _oldhandle, int _newhandle);
extern int      _eof(int _handle);
extern long     filelength(int _handle);
extern int      _filedrive(int _handle);
extern int      getftime(int _handle, struct ftime *_ftimep);
extern int      isatty(int _handle);
extern long     lseek(int _handle, long _offset, int _fromwhere);
extern int      open(const char *_path, int _access,... /*unsigned mode*/);
extern int      _open(const char *_path, int _oflags);
extern int      read(int _handle, void *_buf, unsigned _num);
extern int      _read(int _handle, void *_buf, unsigned _num);
extern int      setmode(int _handle, unsigned _mode);
extern int      sopen(const char *_path, int _access, int _shflag, ... /*unsigned mode*/);
extern long     tell(int _handle);
extern unsigned umask(unsigned _cmask);
extern int      unlink(const char *_path);
extern int      write(int _handle, void *_buf, unsigned _num);
extern int      _write(int _handle, const void *_buf, unsigned _num);
#ifdef __cplusplus
}
#endif
#endif
