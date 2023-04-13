/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  setjmp.h -  typedef and function prototypes for setjmp and longjmp.     *
*                                                                          *
*  COPYRIGHT (C) 1989, 1990 Jensen and Partners. All Rights Reserved.      *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _SETJMP_INC_
#define _SETJMP_INC_

#ifndef _JMPTYPE_DEF
#define _JMPTYPE_DEF

typedef struct {
    unsigned  j_flag;
    unsigned  j_ip;
    unsigned  j_sp;
    unsigned  j_bp;
    unsigned  j_si;
    unsigned  j_di;
    unsigned  j_dx;
    unsigned  j_cx;
    unsigned  j_bx;
    unsigned  j_classHandle;
    unsigned  j_classPtr;
    unsigned  j_enterFrame;
    unsigned  j_osFrame;
    char      j_st[2][10];
} jmp_buf[1];
#endif

#ifdef __cplusplus
extern "C" {
#endif
#pragma save,call(reg_saved=>(ax,bx,cx,dx,ds,es,si,di,st0,st1,st2,st3,st4,st5,st6))
extern void  longjmp(jmp_buf _env, int _val);
#pragma restore
extern int setjmp(jmp_buf _env);
#ifdef __cplusplus
}
#endif
#endif
