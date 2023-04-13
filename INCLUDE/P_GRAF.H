/*	HEADER - P_GRAF.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_GRAF_H
#include <stdepoc.h>
typedef struct
{
short int x; /* Horizontal coordinate */ 
short int y; /* Vertical coordinate */ 
} P_POINT;
typedef struct
{
P_POINT tl; /* Top left point */ 
P_POINT br; /* Bottom right point */ 
} P_RECT;
typedef struct
{
P_RECT r; /* Rectangle */ 
P_POINT p; /* Point */ 
} P_RECTP;
typedef struct
{
P_POINT tl; /* Top left point */ 
unsigned short int width; /* Width */ 
unsigned short int height; /* Height */ 
} P_EXTENT;
typedef struct
{
unsigned short int *addr; /* address of 2-dimensional bit array */ 
P_RECT area;  /* area bounding the picture within bit array */ 
unsigned short int bytewid; /* number of bytes in a row */ 
} P_BITMAP;
#ifdef __cplusplus
extern "C" {
#endif
#pragma save,call(reg_param =>(si,di),reg_saved =>(bx,cx,si,di,EPOC_SAVE))
extern void p_absrec(const P_RECT *,P_RECT *);
#pragma call(reg_param =>(bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_emprec(const P_RECT *);
#pragma call(reg_param =>(bx,ax,di),reg_saved =>(ax,bx,cx,dx,si,di,EPOC_SAVE))
extern void p_insrec(P_RECT *,int,int);
#pragma call(reg_param =>(si,bx,di),reg_saved =>(EPOC_SAVE))
extern int p_intrec(const P_RECT *,const P_RECT *,P_RECT *);
#pragma call(reg_param =>(bx,ax,dx),reg_saved =>(ax,bx,cx,dx,si,di,EPOC_SAVE))
extern void p_offrec(P_RECT *,int,int);
#pragma call(reg_param =>(di,bx),reg_saved =>(bx,cx,si,di,EPOC_SAVE))
extern int p_pinrec(const P_POINT *,const P_RECT *);
#pragma call(reg_param =>(si,bx,di),reg_saved =>(bx,EPOC_SAVE))
extern void p_unirec(const P_RECT *,const P_RECT *,P_RECT *);
#pragma restore
#ifdef __cplusplus
}
#endif

