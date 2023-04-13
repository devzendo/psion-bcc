/*	HEADER - P_CRC.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_CRC_H
#include <stdepoc.h>

typedef struct
    {
    unsigned char lo; /* CRC low byte*/
    unsigned char hi; /* CRC high byte*/
    } CRC;

/* CRC as hi lo bytes or a word */
typedef union
    {
    unsigned short int uw;
    CRC hilo;
    } P_CRC;

#pragma save,call(reg_param =>(di,si,cx),reg_saved =>(bx,cx,si,di,EPOC_SAVE))
#ifdef __cplusplus
extern "C" {
#endif
extern void p_crc(unsigned short int *,const unsigned char *,unsigned int);
#pragma restore
#ifdef __cplusplus
}
#endif

