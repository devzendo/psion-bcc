/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  clib.h -  internal header file for C library.                           *
*                                                                          *
*  COPYRIGHT (C) 1989, 1990 Jensen and Partners. All Rights Reserved       *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _CLIB_INC_
#define _CLIB_INC_

#pragma warn(wall => on)           /* enable all warnings */

#define _STATIC static             /* hide local stuff */

#define _IO_MTF
#define _CT_MTF

#define LONGDOUBLE long double
#define FLOORL(x) floorl(x)
#define LOG10L(x) log10l(x)

#include <epocdefs.h>
#include <alloc.h>
#ifdef _USE_CONIO
#include <conio.h>
#endif
#include <ctype.h>
#include <dir.h>
#include <errno.h>
#include <dos.h>
#include <fcntl.h>
#ifdef _USE_FLOAT
#include <float.h>
#endif
#ifndef _NO_IO
#include <io.h>
#endif
#include <limits.h>
#include <locale.h>
#include <mem.h>
#include <math.h>
#include <process.h>
#include <search.h>
#include <setjmp.h>
#include <share.h>
#include <signal.h>
#include <stat.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _USE_TIME
#include <time.h>
#include <timeb.h>
#endif

typedef struct sfc {               /* control structure for vscanner */
    FILE *_stream;                 /* file pointer */
    int  (*_vs_fill)(FILE *st);    /* filler function pointer */
    int _vs_count;                 /* character count */
    int _s_args;                   /* argument count */
    jmp_buf _EOFhandler;           /* EOF jump environment */
} SF ;

typedef struct  pf {
    FILE *_stream;                           /* file pointer */
    int (*_vp_flush)(FILE *st);        /* output function pointer */
    int _vp_ret;                             /* character count */
                   } PF;

extern int   (*_vs_fill)(FILE *st);    /* filler function pointer */
extern int   (*_vp_flush)(FILE *st);   /* output function pointer */

#ifdef __cplusplus
extern "C" {
#endif
extern int         _filler(FILE *st);
extern int         _flusher(FILE *st);

extern int      _dup(int handle);	   /* low level I/O */
extern int      _dup2(int h1, int h2);	
extern void     _ioerr(int code);
extern unsigned lsl(unsigned sel);

extern void        _exit1(void);
extern void        _exit2(void);
extern void        _exitf(void);

extern char          *_d_cgets(char *s);
extern int            _d_putch(int c);
extern int   (*_i_putch)(int c);
extern char *(*_i_cgets)(char *s);

extern char *_ld_format(char *fmt_buf, LONGDOUBLE num, int flag, int prec);
extern char *_v_format(unsigned long l, char *s);

extern int  _matherr(struct exception *x);
extern int  _flsbuf(int  ch, FILE *st);
extern int  _filbuf(FILE *st);

#ifdef _USE_TIME
extern clock_t        _clock_time(void);
extern size_t         _set_date(char *s, size_t scount, size_t lim, char *st);
extern unsigned long  _t_calc(struct date dte, struct time tme);
extern int            _t_to_struct(unsigned long val, struct date *dte, struct time *tme);
extern struct tm    * _t_to_tm(unsigned long clock);
extern unsigned long  _t_norm(struct tm *timeptr);
extern unsigned long  _ytable(int n);
#endif

extern va_list          _rreal_out(va_list _v_argptr, int flag, int wid, int prec);
extern va_list          _real_pdef(va_list _v_argptr, int flag, int wid, int prec);
extern va_list          _rreal_in(int pmod, int smod, unsigned flag, int width, va_list _v_argptr);
extern va_list          _real_sdef(int pmod, int smod, unsigned flag, int width, va_list _v_argptr);

extern char      *_f_fmt(char *_fmt_buf, LONGDOUBLE num, int flag, int prec);
extern char      *_fptoa(unsigned long, char *s);

extern double      _atof(const char *s, int flag, int *pos);

extern int         _pf_entry(FILE *st);
extern void        _pf_exit(FILE *st, int flag);
extern void        _vp_setbuf(FILE *st, char *buf);
extern void        _vp_freebuf(FILE *st);

extern FILE       *_alloc_stream(FILE *stream, int handle, int flag);
extern void        _flushall(void);
extern int         _free_stream(void);
extern int         _getfmode(const char *path);
extern int         _open_stream(const char *path, int *fptr, int mode);
extern int         _scan_type(const char *type, int *fptr, int *mptr);
extern int         _valid_stream(FILE *st);

#pragma save
#pragma call(reg_saved=>(ds, di, si,st1,st2), reg_param=>(ax,bx,cx,dx))
extern int    _vgetc(void);
extern int    _vungetc(int c);

extern void   _justify(char *s, int flag, int width);
extern void   _str_out(char *s, int flag, int width, int precision);
extern void   _vputc(int ch);
#pragma restore

extern unsigned char _exists(const char *path);

extern void        _swap(void *b1, void *b2, size_t width);

extern LONGDOUBLE  _acvt(int flag, char *mbuf, int exp, int len);
extern void        _cvt(LONGDOUBLE x, int n, int *dec, int *sign, char * buf);
extern void        _seterrno(int type);

extern LONGDOUBLE  _pow_int(LONGDOUBLE x,int y);
extern LONGDOUBLE  _round( LONGDOUBLE x );
extern void        _bcd(LONGDOUBLE x,char * p);

extern void _FatalError(unsigned address, int code);
extern unsigned _FatalErrorPos(void);

extern void (*_exit_stk[32])(void); 		 /* at/onexit function stack */

#pragma save,check(index=>off)
extern void  (**_exit_ptr)(void);
extern void  (**_exit_top)(void);
#pragma restore

extern void  (*_exit_io)(void);
extern void  (*_exit_tmp)(void);

extern va_list (*_real_in)(int pmod, int smod, unsigned flag, int width, va_list _v_argptr);
extern va_list (*_real_out)(va_list _v_argptr, int flag, int wid, int prec);

extern void  (*_exit_proc)(void);
#ifdef __cplusplus
}
#endif

/*  Internal Data Declarations.  */

extern char         _cvt_buf[64];    /* real number conversion buffer */
extern char         _ctype[257];     /* ctype data */
extern struct lconv _lconv;
#ifdef _USE_TIME
extern time_t       _proc_time;	     /* time at beginning of process */
#endif
extern char         _sys_errbuf[128];/* error message buffer */
extern char         *sys_errlist[];  /* error messages */
extern int           sys_nerr;	     /* number of system error strings */
extern double       _tens[32];
extern char         _upperHex;       /* conversion case */

extern jmp_buf    _EOFhandler;	     /* EOF error jump environment */
extern unsigned   _fmask;
extern            _iosetup;	     /* initialisation flag */
extern int        _p_init;
extern int        _s_args;           /* argument count */
extern FILE      *_stream;           /* file pointer */
extern int        _ungotchar;        /* temporary storage for console I/O */
extern int        _vp_ret;           /* character count */
extern int        _vs_count;         /* character count */
extern int        _open_max;         /* maximum number of open files */
extern char       *_tmpfiles[];
extern FILE       *_tmpfptrs[];

extern char          _argbuf[128];	  /* command line buffer */
extern unsigned      _assign_init_magic;

/*****************************************************************************/
/* CPP Definitions.                                                          */
/*****************************************************************************/

typedef void *(*ctor_t)(void *);
typedef void (*dtor_t)(void *);

#pragma save, call(reg_param=>(), reg_saved=>(ds,si,di,st1,st2), near_call=>on, c_conv=>on)
#ifdef __cplusplus
extern "C" {
#endif
extern void   _call_ctors(ctor_t, char *obj_ptr, int vbnum, int n, int siz);
extern void   _call_dtors(dtor_t, char *obj_ptr, int vbnum, int n, int siz);
#ifdef __cplusplus
}
#endif
#pragma restore

/* Macro Definitions.   */

#define TRUE       1
#define FALSE      0

#define _CTLZ    0x01A
#define _O_LRD   0x400
#define _WRITE	     2
#define _NODEFMODE   4
#define _READ	     8

#define _MNEG        1
#define _ENEG        2
#define _STD         8
#define _HMAX       54
#define _HEX         1
#define _OCT         2
#define _NEG         4
#define _OFL         8

#define _DAYSECS       86400L	  /* seconds in year */
#define _SEVENTIES 315532800L     /* seconds between 1970 and 1980 */

#define InternalError(c) _FatalError(_FatalErrorPos(), (c))

#define PF_VBSIZE 256
#define PF_TEMP_BUF 128

#define DEC_POINT _lconv.decimal_point[0]

#define PF_LEFT	     0x0001	      /* justification */
#define PF_SIGN	     0x0002	      /* force leading PF_SIGN */
#define PF_SPACE     0x0004	      /* force leading PF_SPACE */
#define PF_HASH	     0x0008	      /* PF_HASH flag */
#define PF_NOPOINT   0x0010	      /* supress radix point */
#define PF_UPPER     0x0020	      /* PF_UPPER case type */
#define PF_IS_SIGNED 0x0040	      /* signed data-type */
#define PF_ZFLAG     0x0080	      /* format with 0 */
#define PF_HEX	     0x0100	      /* PF_HEX integer  */
#define PF_OCT	     0x0200	      /* octal integer */
#define PF_GTYPE     0x0400	      /* g real type */
#define PF_EXP	     0x0800	      /* e real type */
#define PF_PSET	     0x1000	      /* precison set */
#define PF_LDMOD     0x2000	      /* long real */
#define PF_CPP       0x4000	      /* C++ formatting rules */

#define SF_WILD	     0x0004	      /* any int type */
#define SF_SUPRESS   0x0008	      /* star flag */
#define SF_UPPER     0x0010	      /* upper case type */
#define SF_NSIGNED   0x0020	      /* unsigned data-type */
#define SF_HEX	     0x0040	      /* hex integer  */
#define SF_OCT	     0x0080	      /* octal integer */
#define SF_LDMOD     0x0100           /* LONGDOUBLE */

#endif






