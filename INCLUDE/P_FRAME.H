/*	HEADER - P_FRAME.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_FRAME_H
#include <stdepoc.h>
#ifndef P_CRC_H
#include <p_crc.h>
#endif
#ifndef P_LLMAC_H
#include <p_llmac.h>
#endif
typedef struct
{
/* Transmit stuff */
P_CRC tcrc; /* the CRC for the transmitted data */ 
unsigned char *pbuf; /* where to extract next byte from transmit buffer */ 
unsigned char *pend; /* ptr to end of data in transmit buffer */ 
unsigned char tcntl; /* the control byte to transmit */ 
unsigned char tstat; /* current transmit frame state */ 
/* receive stuff */
unsigned short int rlen; /* current received frame length */ 
unsigned char rstat; /* current receive frame state */ 
unsigned char rtyp; /* current receive frame type */ 
unsigned char rseq; /* current receive frame sequence */ 
unsigned char rfull; /* TRUE if a complete data frame is in buffer */ 
P_CRC rcrc; /* the CRC for the received data */ 
P_FRAME dfrm; /* the internal data frame */ 
short int numfrm; /* number of frames currently in supervisory Q */ 
P_FRAME *prfin; /* entry pt to supervisory frame Q */ 
P_FRAME *prfout; /* removal pt of supervisory frame Q */ 
P_FRAME rfrm[MAXFRM]; /* supervisory frame Q */ 
} P_FRMCB;
