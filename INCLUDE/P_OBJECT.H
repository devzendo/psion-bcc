/*	HEADER - P_OBJECT.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_OBJECT_H
#include <stdepoc.h>
#define METHOD  
typedef struct p_class
{
unsigned short int cat; /* category id */ 
struct p_class *super; /* superclass class */ 
unsigned short int len; /* length of instance */ 
unsigned char base; /* base function number */ 
unsigned char sig_6b; /* signature - should be 0x6b */ 
unsigned char num; /* number of entries in vector table */ 
unsigned char ncomp; /* number of component objects */ 
} P_CLASS;
typedef struct
{
int hcat;
int hclass;
} P_OBJECT;
typedef int P_CATID; /* category identifier */ 
typedef struct
{
P_CATID cat; /* category identifier */ 
unsigned short int xclass; /* class number */
} P_CLASSID;
#define METHOD_CALL call(reg_param =>(bx,dx,si,di),reg_saved =>(ds,st1,st2))
#define p_send3(o,m,p1) _p_send3(o,m,(void *)(p1))
#define p_send4(o,m,p1,p2) _p_send4(o,m,(void *)(p1),(void *)(p2))
#define p_send5(o,m,p1,p2,p3) _p_send5(o,m,(void *)(p1),(void *)(p2),(void *)(p3))
#define f_send3(o,m,p1) _f_send3(o,m,(void *)(p1))
#define f_send4(o,m,p1,p2) _f_send4(o,m,(void *)(p1),(void *)(p2))
#define f_send5(o,m,p1,p2,p3) _f_send5(o,m,(void *)(p1),(void *)(p2),(void *)(p3))
#define p_entersend3(o,m,p1) _p_entersend3(o,m,(void *)(p1))
#define p_entersend4(o,m,p1,p2) _p_entersend4(o,m,(void *)(p1),(void *)(p2))
#define p_entersend5(o,m,p1,p2,p3) _p_entersend5(o,m,(void *)(p1),(void *)(p2),(void *)(p3))
#define p_supersend3(o,m,p1) _p_supersend3(o,m,(void *)(p1))
#define p_supersend4(o,m,p1,p2) _p_supersend4(o,m,(void *)(p1),(void *)(p2))
#define p_supersend5(o,m,p1,p2,p3) _p_supersend5(o,m,(void *)(p1),(void *)(p2),(void *)(p3))
#ifdef __cplusplus
extern "C" {
#endif
extern int cdecl p_send(void *,unsigned char,...);
extern int cdecl f_send(void *,unsigned char,...);
extern int cdecl p_qsend(void *,unsigned char,...);
extern void * cdecl f_newsend(int,int,unsigned char,...);
extern void * cdecl f_newlibhsend(int,int,unsigned char,...);
extern int cdecl p_entersend(void *,unsigned char,...);
extern int cdecl p_supersend(void *,unsigned char,...);
extern int cdecl p_exactsend(int,int,void *,unsigned char,...);
#pragma save,call(reg_param =>(bx,cx,dx,si,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int f_send2(void *,unsigned char);
extern int _f_send3(void *,unsigned char,void *);
extern int _f_send4(void *,unsigned char,void *,void *);
extern int _f_send5(void *,unsigned char,void *,void *,void *);
#pragma call(reg_param =>(bx,cx,dx,si,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE),inline =>on)
static int p_send2(void *,unsigned char) = {0xcd,0xcf};
static int _p_send3(void *,unsigned char,void *) = {0xcd,0xcf};
static int _p_send4(void *,unsigned char,void *,void *) = {0xcd,0xcf};
static int _p_send5(void *,unsigned char,void *,void *,void *) = {0xcd,0xcf};
static int p_entersend2(void *,unsigned char) = {0xcd,0xd9};
static int _p_entersend3(void *,unsigned char,void *) = {0xcd,0xd9};
static int _p_entersend4(void *,unsigned char,void *,void *) = {0xcd,0xd9};
static int _p_entersend5(void *,unsigned char,void *,void *,void *) = {0xcd,0xd9};
static int p_supersend2(void *,unsigned char) = {0xcd,0xd0};
static int _p_supersend3(void *,unsigned char,void *) = {0xcd,0xd0};
static int _p_supersend4(void *,unsigned char,void *,void *) = {0xcd,0xd0};
static int _p_supersend5(void *,unsigned char,void *,void *,void *) = {0xcd,0xd0};
#pragma restore
#pragma save,call(reg_param =>(bx,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void *p_new(int,int);
extern void *f_new(int,int);
extern int p_getlibh(int);
extern void *p_newlibh(int,int);
extern void *f_newlibh(int,int);
#pragma call(reg_param =>(bx,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_findlib(const char *,int *);
#pragma call(reg_param =>(bx,si,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_linklib(int);
extern int p_loadlib(const char *,int *,int);
extern int p_unloadlib(int);
#pragma call(reg_param =>(bx,ax,si,cx),reg_saved =>(bx,dx,si,di,EPOC_SAVE))
extern int p_loadfilelib(void *,int,int *,int);
#pragma call(reg_param =>(si,bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_openlib(void **,const char *);
#pragma call(reg_param =>(bx,cx,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_reclass(int,int,void *);
extern void p_reclassbyhandle(int,int,void *);
#pragma call(reg_param =>(bx,di,si,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_cpycat(int,void *,void *,unsigned int);
#pragma restore
#ifdef __cplusplus
}
#endif

