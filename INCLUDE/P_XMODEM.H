/*	HEADER - P_XMODEM.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_XMODEM_H
#include <stdepoc.h>
/* P_FCONNECT service connection modes */
#define P_XMDM_ACCP 0 /* want link as acceptor */ 
#define P_XMDM_INIT 1 /* want link as initiator */ 
/* Xmodem/Ymodem link connection types */
#define P_XMDM_CRCORCHECKSUM  0
#define P_XMDM_CRCMODE     1
#define P_XMDM_CHECKSUMMODE   2
#define P_YMODEM_MODE      3
#define P_YMODEM_G_MODE     4
#define P_XMDM_ONE_K      0x8000
/* Xmodem/Ymodem supported flags */
#define P_FXMDM_SENSE      0xff    /* I/O function number */ 
#define P_XSUP_XMODEM      0x01    /* original Xmodem checksum */ 
#define P_XSUP_XMODEM_CRC    0x02    /* Xmodem with CRC */ 
#define P_XSUP_ONE_K_OPTION   0x04    /* 1k frames */ 
#define P_XSUP_YMODEM      0x08    /* Ymodem */ 
#define P_XSUP_YMODEM_G     0x10    /* Ymodem-G */ 
/* Connection states. */
#define P_XMDM_IDLE   0  /* idle state (no connection) */ 
#define P_XMDM_CONNECT_RECEIVE 1  /* receive connection state */ 
#define P_XMDM_CONNECT_TRANSMIT  2  /* transmit connection state */ 
#define P_XMDM_DATA_RECEIVE  3  /* recieve data state */ 
#define P_XMDM_DATA_TRANSMIT 4  /* transmit data state */ 
#define P_XMDM_NLOG 32 /* Max number of debug events,states we record */ 
#define P_XMDM_LOG_PANIC 0xC0 /* panic number */ 
#define P_XMDM_LOG_COMP 0x40 /* user completion */ 
#define P_XMDM_LOG_REQ 0x80 /* user request */ 
/* State and event log record */
typedef struct
    {
    unsigned char state;
    unsigned char event;
    } P_XMLOG;
