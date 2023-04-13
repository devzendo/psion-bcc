/*	HEADER - P_CRYPT.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_CRYPT_H
#include <stdepoc.h>
#define P_MAX_PASS_LEN 16 /* maximum password length */ 
typedef struct
{
unsigned char len; /* length of mask */ 
unsigned char pos; /* current position in mask */ 
unsigned char msk[P_MAX_PASS_LEN]; /* the mask */ 
} P_MASK;
