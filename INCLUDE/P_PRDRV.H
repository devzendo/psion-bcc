/*	HEADER - P_PRDRV.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_PRDRV_H
#include <stdepoc.h>
typedef struct
    {
    unsigned char topmarg;   /* Number of lines in page's top margin */ 
    unsigned char bodylen;   /* Total number of lines to print on the page */
    unsigned char lftmarg;   /* Spaces in page's left margin */ 
    unsigned char bodywid;   /* Total number of characters to print on each line */ 
    } P_LAYOUT_DATA;
typedef struct
    {
    unsigned char escapon;   /* Escape processing enabled/disbaled */ 
    unsigned char escchar;   /* Escape character */ 
    } P_ESCAPE_DATA; 
#define P_PRNFLG_ESCAPE 1 /* Set if escape processing is enabled */ 
#define P_PRNFLG_LAYOUT 2 /* Set if layout processing is enabled */ 
#define P_PRNTYP_PAR 0   /* Parallel port type */ 
#define P_PRNTYP_SER 1   /* Serial port type */
#define P_PRNTYP_FIL 2   /* File port type */ 
typedef struct
    {
    unsigned char port_type;  /* P_PRNTYP_XXX */ 
    unsigned char nstack;    /* number of devices in stack */ 
    unsigned char flags;    /* P_PRNFLG_XXX bits */ 
    unsigned char escchar;   /* Escape character */ 
    P_LAYOUT_DATA ld;  /* Page layout */ 
    } P_PRN_INTF;
typedef struct
    {
    P_PRN_INTF *pintf; /* Interfacing information */
    char *label; /* user label */
    char *pname; /* port name */
    unsigned char *psetbuf; /* port setup data */
    char *driver; /* name of .prd file or NULL for no driver */
    } P_PRN_CRK;
#ifdef __cplusplus
extern "C" {
#endif
extern int p_prnset(int,void *,int);
extern int p_prnget(int,void *);
extern int p_prncur(int);
extern int p_prnbld(void *,P_PRN_CRK *);
extern void p_prncrk(void *,P_PRN_CRK *);
#ifdef __cplusplus
}
#endif

