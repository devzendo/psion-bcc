/*	HEADER - P_ASSERT.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_ASSERT_H
#include <stdepoc.h>
#ifdef ASSERTIONS
#ifdef __cplusplus
extern "C" {
#endif
extern void p_assert(char *pAssert,char *pFile,int lineNo);
#ifdef __cplusplus
}
#endif
#define __ASSERT(p) ((p) ? ((void)0) : p_assert(#p,__FILE__,__LINE__))
#else
#define __ASSERT(ignore) ((void)0)
#endif
