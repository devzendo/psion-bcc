/*
P_ZMODEM.H - Header file for Zmodem protocol

Written by John, August 1995
*/

#define P_ZMODEM_H

/* ZDLE sequences */
#define ZCRCE       'h'	    /* CRC next, frame ends, header packet follows */
#define ZCRCG       'i'	    /* CRC next, frame continues nonstop */
#define ZCRCQ       'j'	    /* CRC next, frame continues, ZACK expected */
#define ZCRCW       'k'	    /* CRC next, ZACK expected, end of frame */
#define ZRUB0       'l'	    /* Translate to rubout 0177 */
#define ZRUB1       'm'	    /* Translate to rubout 0377 */

/* Zmodem frame byte defines */
#define ZPAD        0x2A
#define ZDLE        0x18
#define ZBIN        0x41
#define ZHEX        0x42
#define ZBIN_32     0x43
#define CAN         0x18    /* Makes the ZDLE choice the worst possible */

/* P_FCONNECT service connection modes */
#define P_ZMDM_RECV 0   /* want link as acceptor/receiver of files */
#define P_ZMDM_SEND 1   /* want link as initiator/sendor of files */

#define P_ZMDM_NLOG 32 /* Max number of debug events,states we record */
/* Event types */ 
#define P_ZMDM_LOG_PANIC    0xC0    /* panic number */
#define P_ZMDM_LOG_COMP     0x40    /* user completion */
#define P_ZMDM_LOG_REQ      0x80    /* user request */

/* State and event log record */
typedef struct
    {
    UBYTE state;
    UBYTE event;
    } P_ZMLOG;

#define P_ZM_MAX_BUF            1030

/* Frame types that we received */
#define P_ZM_FRAME_TYPE_RQ_INIT   0
#define P_ZM_FRAME_TYPE_R_INIT    1
#define P_ZM_FRAME_TYPE_S_INIT    2
#define P_ZM_FRAME_TYPE_ACK       3
#define P_ZM_FRAME_TYPE_FILE      4
#define P_ZM_FRAME_TYPE_SKIP      5
#define P_ZM_FRAME_TYPE_NAK       6
#define P_ZM_FRAME_TYPE_ABORT     7
#define P_ZM_FRAME_TYPE_FINISH    8
#define P_ZM_FRAME_TYPE_R_POS     9
#define P_ZM_FRAME_TYPE_DATA      10
#define P_ZM_FRAME_TYPE_EOF       11
#define P_ZM_FRAME_TYPE_FILE_ERR  12
#define P_ZM_FRAME_TYPE_CRC       13
#define P_ZM_FRAME_TYPE_CHALLENGE 14
#define P_ZM_FRAME_TYPE_COMPLETE  15
#define PSEUDO_IMPLEMENTATION_SPECIFIC_FRAME    16
#define P_ZM_FRAME_TYPE_FREE_SIZE 17
#define P_ZM_FRAME_TYPE_COMMAND   18
#define P_ZM_FRAME_TYPE_STD_ERR   19
