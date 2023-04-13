/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  stdio.h -  header file for stream input and output.                     *
*                                                                          *
*  COPYRIGHT (C) 1989, 1990 Jensen and Partners. All Rights Reserved.      *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _STDIO_INC_
#define _STDIO_INC_

#ifndef  _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

#ifndef NULL
#define NULL   0
#endif

#ifndef _STDARG_INC_
#include <stdarg.h>
#endif

#ifndef _ERRNOS_INC_
#define _ERRNOS_INC_
extern int   _doserrno;          /* global DOS error variable */
extern int   errno;              /* global error variable */
#endif

/* Number of files that can be open simultaneously */

#define OPEN_MAX 20			/* Total of 20 open files */
#define SYS_OPEN 20

/* define file control block */

#ifndef _IOB
#define _IOB
typedef struct _iobuf {
    char *_ptr; 	 /* current char pointer */
    short _cnt; 	 /* buffer free space */
    short _size;	 /* buffer size */
    char *_base;	 /* buffer address */
    int   _flag;	 /* file attrib flag */
    int  _file; 	 /* file handle */
    int  _pback;	 /* ungot char if no buffer */
} FILE;
extern FILE  _iob[OPEN_MAX];
#endif

/* Buffer type to be used as 3rd argument for "setvbuf" function */

#define _IOFBF	0
#define _IOLBF	1
#define _IONBF	2

/* End-of-file constant definition  */

#define EOF	(-1)

/* Standard I/O predefined streams */

#define stdin	(&_iob[0])
#define stdout	(&_iob[1])
#define stderr	(&_iob[2])

/* flags bit definitions */

#define _F_RDWR 0x0003			/* Read/write  */
#define _F_READ 0x0001			/* Read only file */
#define _F_WRIT 0x0002			/* Write only file */
#define _F_UBUF 0x0004			/* User allocated buffer */
#define _F_APP	0x0008			/* Append data */
#define _F_ERR	0x0010			/* Error */
#define _F_EOF	0x0020			/* EOF */
#define _F_BIN	0x0040			/* Binary file */
#define _F_IN	0x0080			/* Data is incoming */
#define _F_OUT	0x0100			/* Data is outgoing */
#define _F_DEV	0x0200			/* File is terminal */
#define _F_RST	0x0400			/* Newly opened stream */
#define _F_LBUF 0x0800			/* line buffered stream */
#define _F_CTZ	0x1000

/* Default buffer size use by "setbuf" function */

#define BUFSIZ	512			/* Buffer size for stdio */

/* Constants to be used as 3rd argument for "fseek" function */

#define SEEK_SET	0
#define SEEK_CUR	1
#define SEEK_END	2

#ifndef _FPOS_T_DEF
#define _FPOS_T_DEF
typedef long fpos_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern void	  clearerr(FILE *_st);
extern int	  fclose(FILE *_st);
extern int	  fflush(FILE *_st);
extern int	  fgetc(FILE *_st);
extern char *    fgets(char *s, int _n, FILE *_st);
extern FILE *    fopen(const char *_path, const char *_mode);
extern int	  fprintf(FILE *_st, const char *_format, ...);
extern int	  fputc(int _c, FILE *_st);
extern int	  fputs(const char *_s, FILE *_st);
extern size_t	  fread(void *_ptr, size_t _size, size_t _n, FILE *_st);
extern FILE *    freopen(const char *_path, const char *_mode,FILE *_oldfile);
extern int	  fscanf(FILE *_st, const char *_format, ...);
extern int	  fseek(FILE *_st, long _offset, int _whence);
extern long	  ftell(FILE *_st);
extern size_t	  fwrite(const void *_ptr, size_t _size, size_t _n,FILE *_st);
extern char *    gets(char *_s);
extern void	  perror(const char *_s);
extern int	  printf(const char *_format, ...);
extern int	  puts(const char *_s);
extern int	  rename(const char *_oldname, const char *_newname);
extern void	  rewind(FILE *_st);
extern int       rmtmp(void);
extern int	  scanf(const char *_format, ...);
extern void	  setbuf(FILE *_st, char *_buf);
extern int	  setvbuf(FILE *_st, char *_buf, int _type, size_t _size);
extern int	  sprintf(char *_s, const char *_format, ...);
extern int	  sscanf(const char *_s, const char *_format, ...);
extern char *    strerror(int _errnum);
extern FILE *    tmpfile(void);
extern int	  ungetc(int _c, FILE *_st);
extern int	  vfprintf(FILE *_st, const char *_format, va_list _argptr);
extern int	  vfscanf(FILE *_st, const char *_format, va_list _argptr);
extern int	  vprintf(const char *_format, va_list _argptr);
extern int	  vscanf(const char *_format, va_list _argptr);
extern int	  vsprintf(char *_s, const char *_format, va_list _argptr);
extern int	  vsscanf(const char *_s, const char *_format, va_list _argptr);
extern int       fcloseall(void);
extern FILE *    fdopen(int _handle, char *_type);
extern int       fgetchar(void);
extern int       fgetpos(FILE *_st, fpos_t *_fp);
extern int       fsetpos(FILE *_st, const fpos_t *_fp);
extern int       flushall(void);
extern int       fputchar(int _c);
extern int       getw(FILE *_st);
extern int       putw(int _w, FILE *_st);
extern char *    _strerror(const char *_s);
extern int       unlink(const char *_path);

/*   common functions normally implemented as macros */

extern int  putchar(int _c);
extern int  getchar(void);
extern int  putc(int _c, FILE *_st);
extern int  getc(FILE *_st);
extern int  remove(const char *_path);
extern int  fileno(FILE *_st);
extern int  feof(FILE *_st);
extern int  ferror(FILE *_st);
#ifdef __cplusplus
}
#endif

#ifndef __STDC__
#ifndef _IO_MTF
#define ferror(f)	((f)->_flag & _F_ERR)
#define feof(f) 	((f)->_flag & _F_EOF)
#define fileno(f)	((f)->_file)
#define remove(path)    unlink(path)
#define getc(f)         fgetc(f)
#define putc(c,f)       fputc(c,f)
#define getchar()       fgetc(stdin)
#define putchar(c)      fputc((c), stdout)
#endif
#endif

#endif

