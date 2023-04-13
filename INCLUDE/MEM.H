/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  mem.h -  memory manipulation definitions and function prototypes.       *
*                                                                          *
*  COPYRIGHT (C) 1989 Jensen and Partners. All Rights Reserved             *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _MEM_INC_
#define _MEM_INC_

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

#ifndef NULL
#define NULL   0
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern int	    memcmp(const void *_s1, const void *_s2, size_t _num);
extern void *      memcpy(void *_dest, const void *_source, size_t _num);
extern void *      memset(void *_s, int _c, size_t _num);
extern void *      memccpy(void *_dest, const void *_source, int _c, size_t _num);
extern void *      memchr(const void *_s, int _c, size_t _num);
extern int	    memicmp(const void *_s1, const void *_s2, size_t _num);
extern void *      memmove(void *_dest, const void *_source, size_t _num);
extern void	    movmem(void *src, void *_dest, unsigned _length);
extern void	    setmem(void *_dest, unsigned _length, char _value);
extern void *      memwmove(void *_dest, const void *_source, size_t _num);
extern void *      memwset(void *_s, int _c, size_t _num);
extern void *      memwcpy(void *_dest, const void *_source, size_t _num);
#ifdef __cplusplus
}
#endif
#endif
