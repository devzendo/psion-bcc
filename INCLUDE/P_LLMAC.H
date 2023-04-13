/*	HEADER - P_LLMAC.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_LLMAC_H
#include <stdepoc.h>
#define P_MAXILEN 300 /* maximum length of information field */ 
#define MAXFRM 4 /* maximum number of frames in supervisory Q */ 
#define SERNOCHAR (-1) /* no character to transmit */ 
/* Frame type codes */
#define LA_LPDU     0    /* The Link Acknowledge PDU */ 
#define LD_LPDU     1    /* The Link disconnect PDU */ 
#define LR_LPDU     2    /* The Link Request PDU*/ 
#define LT_LPDU     3    /* The Link Data PDU */ 
#define P_FRM_BROKEN  4    /* A broken frame */ 
typedef struct
{
unsigned char type; /* frame type or P_FRM_BROKEN for a broken frame */ 
unsigned char seq; /* frame sequence */ 
short int len; /* length of information field */ 
unsigned char *pbuf; /* data buffer (INFO) */ 
} P_FRAME;
/* LLMAC layer characteristics */
typedef struct
{
unsigned short int ilen; /* maximum information field length */ 
unsigned short int speed; /* nominal speed in characters per second */ 
unsigned short int rtint; /* suggested retransmission interval */ 
} P_LLMAC;
