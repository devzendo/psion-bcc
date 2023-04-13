/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  assert.h -  assert macro.                                               *
*                                                                          *
*  COPYRIGHT (C) 1989 Jensen and Partners. All Rights Reserved             *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifdef NDEBUG
#define assert(ignore)  ((void) 0)
#else
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif
extern void    abort(void);
#ifdef __cplusplus
}
#endif

#define assert(p)	((p) ? ((void) 0) : (( (void) fprintf(stderr,\
                         "Assertion failed: %s, file %s, line %d\n",\
                          #p, __FILE__, __LINE__)), (abort())))
#endif
