/*	HEADER - P_MODEM.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_MODEM_H
#include <stdepoc.h>
/* what options are selected */
#define P_MDM_TONE 0x01 /* as opposed to PULSE dialling (default) */ 
#define P_MDM_BELL 0x02 /* as opposed to CCITT (default) */ 
#define P_MDM_NO_MODULATION 0x04 /* as opposed to CCITT or BELL */ 
#define P_MDM_CONSTANT_SPEED 0x08 /* modem has constant speed interface */ 
/* Error correction types */
#define P_MDM_ERRCORRECT_NONE  0  /* NO error correction */ 
#define P_MDM_ERRCORRECT    1  /* some form of error correction (ARQ)*/ 
#define P_MDM_ERRCORRECT_MNP  2  /* MNP error correction being used */ 
#define P_MDM_ERRCORRECT_V42  3  /* V42 error correction being used */ 
typedef struct
    {
    unsigned short int supported;  /* what baud rates are supported by modem */ 
    unsigned short int options;   /* flags which options are selected */ 
    unsigned short int baudrate;   /* baud rate currently running at/to run at */ 
    unsigned char chand;    /* connected handshaking */ 
    unsigned char ichand;    /* incoming call handshaking */ 
    } P_MDMCHR;
