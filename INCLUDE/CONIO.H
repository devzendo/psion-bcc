/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  conio.h -  header file for console input and output.                    *
*                                                                          *
*  COPYRIGHT (C) 1989, 1990 Jensen and Partners. All Rights Reserved       *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _CONIO_INC_
#define _CONIO_INC_

#ifdef __cplusplus
extern "C" {
#endif
extern char *  cgets(char *_str);
extern void	cputs(const char *_str);
extern int	cprintf(const char *_format, ...);
extern int	cscanf(const char *_format, ...);
extern int	getch(void);
extern int	getche(void);
extern int	kbhit(void);
extern int	putch(int _ch);
extern int	ungetch(unsigned _ch);

#ifndef _PORTIO_DEF
#define _PORTIO_DEF
#if (defined _IL_MTF) | ( defined __STDC__)

extern unsigned char inportb(int _portid);
extern void          outportb(int _portid, unsigned char _value);
extern unsigned int  inportw(int _portid);
extern void          outportw(int _portid, unsigned int _value);
extern void          _disable(void);
extern void          _enable(void);

#define inp(portid)       inportb(portid)
#define outp(portid, v)   outportb(portid, v)
#define inpw(portid)      inportw(portid)
#define outpw(portid, v)  outportw(portid, v)

#else

#define RET 0xC3

#pragma save,call(reg_param=>(dx,ax),reg_saved=>(bx,cx,si,di,es,ds,st1,st2), inline=>on)
static void __outportb__(int _port, unsigned char _byte) =
{
   0xEE, RET         /* out dx,al */
};

static unsigned char __inportb__(int _port) =
{
   0xEC, RET         /* in  dx,al */
};

static void __outportw__(int _port, unsigned _word) =
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

#pragma restore

#define inportb(portid)     __inportb__(portid)     /* Byte IN instruction */
#define outportb(portid, v) __outportb__(portid,v)  /* Byte OUT instruction */
#define inportw(portid)     __inportw__(portid)     /* Word IN instruction */
#define outportw(portid, v) __outportw__(portid,v)  /* Word OUT instruction */

/* some compilers use inp, outp for inportb, outportb */

#define inp(portid)       __inportb__(portid)
#define outp(portid, v)   __outportb__(portid, v)
#define inpw(portid)      __inportw__(portid)
#define outpw(portid, v)  __outportw__(portid, v)

#endif
#define enable() _enable()
#define disable() _disable()
#endif

#ifdef __cplusplus
}
#endif
#endif

