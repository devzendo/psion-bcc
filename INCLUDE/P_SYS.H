/*	HEADER - P_SYS.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_SYS_H
#include <stdepoc.h>
#define P_ENVMAX 256 /* Max size of an environment string */ 
#define P_CMDMAX 258 /* Max buffer size for the input command line */ 
#define P_MAXSYSIO 258 /* Max buffer size for p_gets() and p_puts() */ 
/* For returning strings from p_getflg */
typedef struct
    {
    unsigned short int argc; /* no. of argumets returned */ 
    unsigned short int argm; /* capacity of address table */ 
    char **argp; /* address of address table */ 
    } P_GETFLG;
#ifdef __cplusplus
extern "C" {
#endif
extern void cdecl p_printf(const char *,...);
extern void cdecl p_print(const char *,...);
extern void p_getdat(char *);
extern int p_getch(void);
extern int p_getl(const char *,char *,int);
extern int p_gets(char *);
extern void p_putch(int);
extern void p_puts(const char *);
extern void t_panic(const char *);
#ifdef __cplusplus
}
#endif

