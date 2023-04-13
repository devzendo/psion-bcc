/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  dos.h -  structure, union, macro and function definitions for MSDOS and *
*  Intel IAPX86 family.                                                    *
*                                                                          *
*  COPYRIGHT (C) 1989 Jensen and Partners. All Rights Reserved             *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _DOS_INC_
#define _DOS_INC_

#ifndef __STDC__
extern	unsigned int	 _osmajor;
extern	unsigned int	 _osminor;
extern  int              _argc;
extern  char            *_argv[32];
#endif

#define FA_NORMAL	0x00		/* normal file */
#define FA_RDONLY	0x01		/* Read only attribute */
#define FA_HIDDEN	0x02		/* Hidden file */
#define FA_SYSTEM	0x04		/* System file */
#define FA_LABEL	0x08		/* Volume label */
#define FA_DIREC	0x10		/* Directory */
#define FA_ARCH 	0x20		/* Archive */
#define FA_TEXT         0x100           /* Open in text mode */
#define FA_SHARE        0x200           /* Open with sharing */

struct WORDREGS {
    unsigned int ax, bx, cx, dx, si, di, cflag, flags;
};

struct BYTEREGS {
    unsigned char al, ah, bl, bh, cl, ch, dl, dh;
};

union  REGS {
   struct WORDREGS x;
   struct BYTEREGS h;
};

struct SREGS {
    unsigned int es;
    unsigned int cs;
    unsigned int ss;
    unsigned int ds;
};

struct REGPACK {
    unsigned  r_ax, r_bx, r_cx, r_dx;
    unsigned  r_bp, r_si, r_di, r_ds, r_es, r_flags;
};

#ifdef __cplusplus
extern "C" {
#endif
extern int     int86(int _intno, const union REGS * _inregs, union REGS * _outregs);
extern int     int86x(int _intno, const union REGS * _inregs, union REGS * _outregs,
	                                         struct SREGS * _segregs);
extern void    intr(int _intno, struct REGPACK * _preg);
extern void	segread(struct SREGS * _segs);
#ifdef __cplusplus
}
#endif

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
extern int       findfirst(const char * _path, struct ffblk * _buffer, int _attrib);
extern int       findnext(struct ffblk * _buffer);
#ifdef __cplusplus
}
#endif

#ifndef _PORTIO_DEF
#define _PORTIO_DEF

#if (defined _IL_MTF) | ( defined __STDC__)

#ifdef __cplusplus
extern "C" {
#endif
extern unsigned char  inportb(int _portid);
extern void           outportb(int _portid, unsigned char _value);
extern unsigned int   inportw(int _portid);
extern void           outportw(int _portid, unsigned int _value);
extern void           _disable(void);
extern void           _enable(void);
#ifdef __cplusplus
}
#endif

#define inp(portid)      inportb(portid)
#define outp(portid, v)  outportb(portid, v)
#define inpw(portid)      inportw(portid)
#define outpw(portid, v)  outportw(portid, v)
#else

#define RET 0xC3

#ifdef __cplusplus
extern "C" {
#endif
#pragma save,call(reg_param=>(dx,ax),reg_saved=>(bx,cx,si,di,es,ds,st1,st2), inline=>on)
static void __outportb__(int _port, unsigned char _byte) =
{
   0xEE, RET         /* out dx,al */
};

static unsigned char __inportb__(int _port) =
{
   0xEC, RET         /* in  dx,al */
};

static void __outportw__(int _port,int unsigned _word) =
{
   0xEF, RET         /* out dx,ax */
};

static unsigned int __inportw__(int _port) =
{
   0xED, RET         /* in  dx,ax */
};

static void _enable(void)=
{
   0xFB, RET
};

static void _disable(void)=
{
   0xFA, RET
};
#ifdef __cplusplus
}
#endif

#pragma restore

#define inportb(portid) __inportb__(portid)       /* Byte IN instruction */
#define outportb(portid, v) __outportb__(portid,v)/* Byte OUT instruction */
#define inportw(portid) __inportw__(portid)       /* Word IN instruction */
#define outportw(portid, v) __outportw__(portid,v)/* Word OUT instruction */

/* some compilers use inp, outp for inportb, outportb */

#define inp(portid)      __inportb__(portid)
#define outp(portid, v)  __outportb__(portid, v)
#define inpw(portid)      __inportw__(portid)
#define outpw(portid, v)  __outportw__(portid, v)
#endif
#define enable() _enable()
#define disable() _disable()
#endif

#define NFDS	20			/* Maximum number of fds */

#ifndef _TMT_DEF
#define _TMT_DEF
struct date {
    int da_year;
    unsigned char da_day;
    unsigned char da_mon;
};

struct time {
    unsigned char ti_hour;
    unsigned char ti_min;
    unsigned char ti_sec;
    unsigned char ti_hund;
};
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern void       getdate(struct date * _dptr);
extern void       gettime(struct time * _tptr);
extern void       setdate(const struct date * _dptr);
extern void       settime(const struct time * _tptr);
extern void       sleep(unsigned _secs);
extern void	  *getRealHandle(int handle);
#ifdef __cplusplus
}
#endif
#endif


