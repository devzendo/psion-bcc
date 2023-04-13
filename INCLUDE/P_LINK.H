/*	HEADER - P_LINK.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_LINK_H
#include <stdepoc.h>
#ifndef P_FILE_H
#include <p_file.h>
#endif
#ifndef P_FRAME_H
#include <p_frame.h>
#endif
/* P_FCONNECT service connection modes */
#define P_LINK_ACCP 0 /* want link as acceptor */ 
#define P_LINK_INIT 1 /* want link as initiator */ 
/* Link layer states */
#define P_LINK_IDLE 0 /* no connection - idle */ 
#define P_LINK_IDLE_LR 1 /* no connection - awaiting LR */ 
#define P_LINK_DATA_IDLE 2 /* connected - idle */ 
#define P_LINK_DATA_LA 3 /* connected - awaiting LA */ 
#define P_LINK_IDLE_LA 4 /* not connected - awaiting LA (or LT) to LR */ 
/* State and event log record */
typedef struct
{
unsigned char state;
unsigned char event;
} P_LLLOG;
#define P_LINK_NLOG 32 /* Max number of debug events,states we record */ 
#define P_LINK_LOG_MASK 0xC0
#define P_LINK_LOG_PANIC 0xC0 /* panic number */ 
#define P_LINK_LOG_MAC 0x00 /* MAC request or timer */ 
#define P_LINK_LOG_REQ 0x80 /* User request */ 
#define P_LINK_LOG_COMP 0x40 /* User completion */ 
typedef struct
{
P_LLMAC mac; /* LLMAC characteristics */ 
unsigned short int br_cnt; /* count of broken frames */ 
unsigned short int rx_cnt; /* re-transmission count */ 
} P_LLDATA;
