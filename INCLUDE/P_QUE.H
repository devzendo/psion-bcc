/*	HEADER - P_QUE.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_QUE_H
#include <stdepoc.h>
#define P_ISEMPTYQ(q) ((q)==(q)->next)
#define P_INITQ(q) (q)->next=(q)->prev=(q)
#define P_DECLAREQ(q) P_QUE q = {&q,&q}
typedef struct p_que
{
struct p_que *next; /* Next entry */ 
struct p_que *prev; /* Previous entry */ 
} P_QUE;
typedef struct
{
P_QUE q; /* Que entry control */
long int key; /* Delta key value */
} P_DELTA;
#ifdef __cplusplus
extern "C" {
#endif
#pragma save,call(reg_param =>(si,di),reg_saved =>(ax,cx,dx,si,di,EPOC_SAVE))
extern void p_enque(P_QUE *,P_QUE *);
extern void p_deque(P_QUE *);
#pragma restore
P_DELTA *p_enqued(P_QUE *,P_DELTA *,long int);
P_DELTA *p_dequed(P_QUE *,P_DELTA *);
#ifdef __cplusplus
}
#endif
