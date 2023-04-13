/*	HEADER - P_STD.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_STD_H
#include <stdepoc.h>
#define GLREF_D extern
#define GLDEF_D
#define LOCAL_D static
#define GLREF_C extern
#define LOCAL_C static
#define GLDEF_C
#define CDECL cdecl
#define FOREVER for(;;)
#define TRUE 1
#define FALSE 0
#define NULL 0
#define NULL_D ((VOID *)0)
#define NULL_C ((INT (*)(VOID))0)
#define VOID void
#define FAST register
#define CONST const
#define CLIB_CONST CONST
typedef int INT,HANDLE;
typedef unsigned int UINT;
typedef signed char BYTE;
typedef unsigned char UBYTE;
typedef char TEXT;
typedef short int WORD;
typedef unsigned short int UWORD;
typedef long int LONG;
typedef unsigned long int ULONG;
typedef double DOUBLE;
typedef float FLOAT;
typedef union
    {
    BYTE *b; UBYTE *ub; INT *i; UINT *ui; WORD *w;
    UWORD *uw; LONG *l; ULONG *ul; UBYTE **a; TEXT *t;
    } UPTR;
#ifdef __cplusplus
extern "C" {
#endif
#define ENTER_CALL call(reg_param =>(bx,cx,dx,si,di),reg_saved =>(ds,st1,st2))
#define p_enter1(f) _p_enter1((void *)(f))
#define p_enter2(f,p1) _p_enter2((void *)(f),(void *)(p1))
#define p_enter3(f,p1,p2) _p_enter3((void *)(f),(void *)(p1),(void *)(p2))
#define p_enter4(f,p1,p2,p3) _p_enter4((void *)(f),(void *)(p1),(void *)(p2),(void *)(p3))
#define p_enter5(f,p1,p2,p3,p4) _p_enter5((void *)(f),(void *)(p1),(void *)(p2),(void *)(p3),(void *)(p4))
#define p_enter6(f,p1,p2,p3,p4,p5) _p_enter6((void *)(f),(void *)(p1),(void *)(p2),(void *)(p3),(void *)(p4),(void *)(p5))
extern int cdecl p_ioa(void *,int,short int *,...);
extern void cdecl p_ioc(void *,int,short int *,...);
extern int cdecl p_iow(void *,int,...);
extern int cdecl p_enter(void *,...);
#pragma save,call(reg_param =>(ax,bx,cx,dx,si,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE),inline =>on)
static int _p_enter1(void *) = {0xcd,0xd2};
static int _p_enter2(void *,void *) = {0xcd,0xd2};
static int _p_enter3(void *,void *,void *) = {0xcd,0xd2};
static int _p_enter4(void *,void *,void *,void *) = {0xcd,0xd2};
static int _p_enter5(void *,void *,void *,void *,void *) = {0xcd,0xd2};
static int _p_enter6(void *,void *,void *,void *,void *,void *) = {0xcd,0xd2};
#pragma call(reg_param =>(bx,ax,di,cx,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE),inline=>off)
extern int p_ioa3(void *,unsigned char,short int *);
extern int p_ioa4(void *,unsigned char,short int *,void *);
extern int p_ioa5(void *,unsigned char,short int *,void *,void *);
extern void p_ioc3(void *,unsigned char,short int *);
extern void p_ioc4(void *,unsigned char,short int *,void *);
extern void p_ioc5(void *,unsigned char,short int *,void *,void *);
#pragma call(reg_param =>(bx,ax,cx,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_iow2(void *,unsigned char);
extern int p_iow3(void *,unsigned char,void *);
extern int p_iow4(void *,unsigned char,void *,void *);
#pragma restore
extern void p_abort(void);
extern void cdecl p_atos(char *,const char *,...);
extern int cdecl p_getflg(char *,char *,...);
extern char * cdecl p_scatm(char *,...);
extern char * cdecl p_scpym(char *,...);
extern int cdecl p_stoa(char **,const char *,...);
#pragma save,call(reg_param =>(cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void *f_alloc(unsigned int);
#pragma restore
extern int f_leave(int);
#pragma save,call(reg_param =>(bx,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_sound(unsigned int,unsigned int);
extern void *f_realloc(void *,unsigned int);
#pragma call(reg_param =>(bx,dx,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void *p_adjust(void *,unsigned int,int);
#pragma call(reg_param =>(bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_semcrt(int);
extern void p_semdel(int);
extern unsigned int p_alen(const void *);
extern int p_setpth(const char *);
#pragma restore
extern void p_allchk(int);
#pragma save,call(reg_param =>(cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void *p_alloc(unsigned int);
#pragma call(reg_param =>(di),reg_saved =>(cx,dx,si,di,EPOC_SAVE))
extern unsigned int p_allspc(void **);
#pragma restore
extern void p_allwalk(void (*)(void *,int,unsigned int),void *);
#pragma save,call(reg_param =>(di,si,bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_atob(char *,const char *,void *);
#pragma call(reg_param =>(si,cx,di,bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_bcmp(const void *,int,const void *,int);
extern int p_bcmpi(const char *,int,const char *,int);
#pragma call(reg_param =>(di,si,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern unsigned char *p_bcpy(void *,const void *,unsigned int);
#pragma call(reg_param =>(di,cx,ax),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern unsigned char *p_bfil(void *,unsigned int,int);
#pragma call(reg_param =>(si,cx,ax),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_bloc(const void *,int,int);
extern int p_bloci(const char *,int,int);
#pragma call(reg_param =>(si,cx,di,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_bmatch(const char *,int,const char *,int);
extern int p_bmatchi(const char *,int,const char *,int);
#pragma restore
extern unsigned char *p_brep(void *,int,const void *,int);
extern int p_bsrch(int,int (*)(int,void *),int *,void *);
#pragma save,call(reg_param =>(si,cx,di,bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_bsub(const void *,int,const void *,int);
extern int p_bsubi(const char *,int,const char *,int);
#pragma call(reg_param =>(di,si,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_bswap(void *,void *,int);
#pragma call(reg_param =>(di,si,cx),reg_saved =>(bx,dx,si,di,EPOC_SAVE))
extern void p_ccpy(void *,void *,unsigned int);
#pragma call(reg_param =>(bx,cx,di,si,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_chdir(const char *,char *,int,const char *);
extern int p_chdirasync(const char *,char *,int,const char *,short int *);
#pragma call(reg_param =>(bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_close(void *);
#pragma call(reg_param =>(),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE),reg_return =>(ax,bx))
extern unsigned long int p_date(void);
#pragma restore
extern void p_dummy(void);
extern void p_decrypt(void *,void *,int);
extern int p_defdev(char *,int);
extern int p_defdir(char *,int);
#pragma save,call(reg_param =>(di,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_delenv(const char *);
extern int p_delenviron(const char *,int);
#pragma call(reg_param =>(bx,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_delete(const char *);
extern int p_deleteasync(const char *,short int *);
extern int p_setpthasync(const char *,short int *);
extern int p_testpthasync(const char *,short int *);
#pragma restore
extern void p_dummy(void);
extern void p_encrypt(void *,void *,int);
#pragma save,call(reg_param =>(bx,ax),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_nmday(char *,int);
extern void p_nmmon(char *,int);
extern void p_getampmtext(char *,int);
extern void p_errs(char *,int);
#pragma call(reg_param =>(bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_testpth(const char *);
extern int p_getpth(char *);
extern void p_getsuffixes(char *);
extern void p_exit(int);
extern void p_signal(int);
#pragma call(reg_param =>(bx,cx,di,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_fdate(const char *,unsigned long int);
extern int p_fdateasync(const char *,unsigned long int,short int *);
#pragma call(reg_param =>(di,dx,si,cx),reg_saved =>(cx,dx,si,di,EPOC_SAVE))
extern int p_findenviron(const char *,int,unsigned char *,int *);
#pragma call(reg_param =>(di,si,cx,dx),reg_saved =>(cx,dx,si,di,EPOC_SAVE))
extern int p_fndenv(const char *,char *,char *,int *);
#pragma call(reg_param =>(bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_free(void *);
#pragma restore
extern void p_freemask(void *);
extern unsigned char *p_getcoml(void);
#pragma save,call(reg_param =>(di,si),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_getenv(const char *,char *);
#pragma call(reg_param =>(di,dx,si),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_getenviron(const char *,int,void *);
#pragma call(reg_param =>(di,bx,dx,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_gltob(char *,unsigned long int,int);
#pragma call(reg_param =>(di,bx,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_gtob(char *,unsigned int,int);
#pragma restore
extern void p_hdel(void *,char *);
extern unsigned char *p_hfind(void *,char *);
extern int p_hfins(void *,char *,char **);
extern void p_hfree(void *);
extern int p_hinit(void **,int,unsigned int ,int);
extern int p_hins(void *,char *);
extern int p_hvisit(void *,int (*)(char *));
#pragma save,call(reg_param =>(ax),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_iosignal(void);
extern void p_iowait(void);
extern void p_ioyield(void);
extern int p_isalnum(int);
extern int p_isalpha(int);
extern int p_iscntrl(int);
extern int p_isdigit(int);
extern int p_isgraph(int);
extern int p_islower(int);
extern int p_isprint(int);
extern int p_ispunct(int);
extern int p_isspace(int);
extern int p_isupper(int);
extern int p_isxdigit(int);
#pragma call(reg_param =>(di,bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_itob(char *,int);
#pragma call(reg_param =>(di,bx,si,cx,dx,ax),reg_saved =>(bx,dx,si,di,EPOC_SAVE))
extern char *p_jtob(char *,int,char *,int,int,int); 
#pragma call(reg_param =>(ax),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_leave(int);
#pragma call(reg_param =>(di,bx,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_ltob(char *,long int);
#pragma call(reg_param =>(bx,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_mkdir(const char *);
extern int p_mkdirasync(const char *,short int *);
#pragma call(reg_param =>(di,bx,cx),reg_saved =>(bx,cx,si,di,EPOC_SAVE))
extern int p_open(void **,const char *,unsigned int);
extern int f_open(void **,const char *,unsigned int);
#pragma call(reg_param =>(di,bx,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_opent(void **,const char *,unsigned int);
#pragma call(reg_param =>(ax),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_panic(int);
#pragma restore
extern int p_qsort(int,int (*)(int,int,void *),void (*)(int,int,void *),void *);
#pragma save,call(reg_param =>(bx),reg_saved =>(cx,dx,si,di,EPOC_SAVE),reg_return =>(ax,bx))
extern unsigned long int p_randl(unsigned long int *);
#pragma restore
#pragma save,call(reg_param =>(bx,cx,dx),reg_saved =>(bx,cx,si,di,EPOC_SAVE))
extern int p_read(void *,void *,unsigned int);
extern int f_read(void *,void *,unsigned int);
#pragma call(reg_param =>(bx,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void *p_realloc(void *,unsigned int);
#pragma call(reg_param =>(bx,cx,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_rename(const char *,const char *);
extern int p_renameasync(const char *,const char *,short int *);
#pragma call(reg_param =>(di,si),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern char *p_scat(char *,const char *);
#pragma call(reg_param =>(si,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_scmp(const char *,const char *);
extern int p_scmpi(const char *,const char *);
extern void p_sconf(char *);
#pragma call(reg_param =>(di,si),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern char *p_scpy(char *,const char *);
extern char *p_scpyf(char *,const char *);
#pragma call(reg_param =>(bx,cx,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_seek(void *,int,long int *);
extern int f_seek(void *,int,long int *);
#pragma call(reg_param =>(di,si),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_setenv(const char *,const char *);
#pragma call(reg_param =>(di,dx,si,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_setenviron(const char *,int,const void *,int);
#pragma restore
extern int p_setmask(void **,char *);
#pragma save,call(reg_param =>(bx,di,cx,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_sfstat(const char *,unsigned int,unsigned int);
extern int p_sfstatasync(const char *,unsigned int,unsigned int,short int *);
#pragma call(reg_param =>(si),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_scap(char *);
extern char *p_skipch(const char *);
extern char *p_skipwh(const char *);
#pragma call(reg_param =>(dx,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_sleepa(unsigned long int);
extern int p_sleep(unsigned long int);
extern int p_wkday(unsigned long int);
#pragma call(reg_param =>(di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern unsigned int p_slen(const char *);
#pragma restore
extern void p_slfclose(void *);
extern int p_slfind(void *,char *,int);
extern int p_slfopen(void **,char *,int);
#pragma save,call(reg_param =>(si,ax),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_sloc(const char *,int);
extern int p_sloci(const char *,int);
extern int p_slocr(const char *,int);
extern int p_slocri(const char *,int);
#pragma call(reg_param =>(si,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_smatch(const char *,const char *);
extern int p_smatchi(const char *,const char *);
#pragma restore
extern char *p_srep(char *,int,const char *);
#pragma save,call(reg_param =>(si,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_ssub(const char *,const char *);
extern int p_ssubi(const char *,const char *);
#pragma call(reg_param =>(bx,di,cx),reg_saved =>(bx,cx,dx,di,EPOC_SAVE))
extern int p_stog(char **,unsigned short int *,int);
#pragma call(reg_param =>(dx,di,cx),reg_saved =>(cx,dx,EPOC_SAVE))
extern int p_stogl(char **,unsigned long int *,int);
#pragma call(reg_param =>(bx,di),reg_saved =>(bx,cx,dx,di,EPOC_SAVE))
extern int p_stoi(char **,short int *);
#pragma call(reg_param =>(dx,di),reg_saved =>(cx,dx,EPOC_SAVE))
extern int p_stol(char **,long int *);
#pragma restore
extern int p_strm(void *,int,long int,void *,int);
extern int p_strmf(void *);
extern void p_strmi(void *,int,int (*)(void *,int,void *,int,int),int,void *);
#pragma save,call(reg_param =>(cx,bx),reg_saved =>(bx,cx,si,di,EPOC_SAVE))
extern int p_svecadd(void *,void *);
#pragma call(reg_param =>(bx,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_sveccall(int,int);
extern void p_svecrem(int);
#pragma call(reg_param =>(ax),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_tofold(int);
extern int p_tolower(int);
extern int p_toupper(int);
#pragma restore
extern int p_vradd(void *,void *);
extern int p_vrcnt(void *);
extern int p_vrdel(void *,int);
extern int p_vrfnd(void *,int (*)(void *,void *),void *,short int *);
extern void p_vrfree(void *);
extern void *p_vrinit(unsigned int,unsigned int);
extern int p_vrins(void *,void *,int);
extern int p_vrisq(void *,int (*)(void *,void *),void *,short int *,void *);
extern void *p_vrpnt(void *,int);
extern void p_vrset(void *,int);
extern void p_vrzero(void *);
#pragma save,call(reg_param =>(di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_waitstat(short int *);
#pragma call(reg_param =>(dx,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_weekno(unsigned long int);
#pragma call(reg_param =>(bx,cx,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_write(void *,void *,unsigned int);
extern int f_write(void *,void *,unsigned int);
#pragma call(reg_param =>(bx,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_sgadjust(int,int);
extern int p_sgclose(int);
#pragma call(reg_param =>(bx,di,dx,si,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_sgcopyfr(int,long int,void *,unsigned int);
extern int p_sgcopyto(int,long int,void *,unsigned int);
#pragma call(reg_param =>(bx,cx,ax),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_sgcreate(const char *,int,int);
extern int p_sgdelete(const char *);
#pragma call(reg_param =>(bx,di,si),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_sgfind(int,const char *,char *);
extern unsigned int p_sgfree(void);
extern void p_sglock(int);
extern void p_sgunlock(int);
extern int p_sgopen(const char *);
extern unsigned int p_sgramdisk(void);
extern unsigned int p_sgsize(int);
#pragma restore
#ifdef __cplusplus
}
#endif

