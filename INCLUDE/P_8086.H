/*	HEADER - P_8086.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_8086_H
#include <stdepoc.h>
#define AX x.ax
#define BX x.bx
#define CX x.cx
#define DX x.dx
#define SI x.si
#define DI x.di
#define ES x.es
#define DS x.ds
#define AL h.al
#define AH h.ah
#define BL h.bl
#define BH h.bh
#define CL h.cl
#define CH h.ch
#define DL h.dl
#define DH h.dh
#define CF 0x0001
#define PF 0x0004
#define AF 0x0010
#define ZF 0x0040
#define SF 0x0080
#define TF 0x0100
#define IF 0x0200
#define DF 0x0400
#define OF 0x0800
typedef struct
{
short int ax,bx,cx,dx,si,di,es,ds;
} XREG;
typedef struct
{
char al,ah,bl,bh,cl,ch,dl,dh;
} HREG;
typedef union
{
XREG x;
HREG h;
} REGS;
