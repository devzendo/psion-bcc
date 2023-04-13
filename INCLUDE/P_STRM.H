/*	HEADER - P_STRM.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_STRM_H
#include <stdepoc.h>
#define STRM_READ 0
#define STRM_WRITE 1
typedef struct
{
unsigned int bsiz; /* block size in bytes */ 
unsigned int dirty; /* TRUE if active block is dirty */ 
unsigned int blk; /* block number currently in buf */ 
unsigned int ffblk; /* first free block */ 
int (*iovec)(void *,int,void *,int,int); /* block io function */ 
void *pcb; /* parameter to block io function */ 
unsigned char buf[2]; /* buffer */ 
} STRMCB;
#define STRMCBL (sizeof(STRMCB)-2)
