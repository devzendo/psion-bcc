/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  alloc.h -  header file for memory allocation functions.                 *
*                                                                          *
*  COPYRIGHT (C) 1989 Jensen and Partners. All Rights Reserved             *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _ALLOC_INC_
#define _ALLOC_INC_

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

#ifndef NULL
#define NULL   0
#endif

struct _heapinfo  {
    int *  _pentry;
    size_t _size;
    int    _useflag;
    void * _secret;
};

#ifndef __STDC__
struct _nheapinfo  {
    int *  _pentry;
    size_t _size;
    int    _useflag;
    void * _secret;
};
#endif

#define _HEAPOK 	     0
#define _HEAPEMPTY 	    -1
#define _HEAPBADBEGIN       -2
#define _HEAPBADNODE        -3
#define _HEAPOVERFLOW       -4
#define _HEAPEND	    -5
#define _HEAPBADPTR         -6

#ifdef __cplusplus
extern "C" {
#endif
extern void *         calloc(size_t _num, size_t _size);
extern void	       free(void *_block);
extern void *         malloc(size_t _size);
extern void *         realloc(void *_block, size_t _size);
extern size_t         stackavail(void);
#ifdef __cplusplus
}
#endif

#ifndef __STDC__
#ifdef __cplusplus
extern "C" {
#endif
extern int            _msize(void *_buffer);
extern size_t         _memmax(void);
extern size_t         _memavl(void);
extern int            _heapchk(void);
extern int            _heapset(int _fill);
extern int            _heapwalk(struct _heapinfo *_entry);
extern unsigned       _freect(size_t _size);
extern unsigned       coreleft(void);
extern void *         _ncalloc(size_t num, size_t _size);
extern void           _nfree(void *_block);
extern void *         _nmalloc(size_t _size);
extern void *         _nrealloc(void *_block, size_t _size);
extern int            _nheapchk(void);
extern int            _nheapset(int _fill);
extern int            _nheapwalk(struct _nheapinfo *_nearentry);
extern int            _nmsize(void *_buffer);
extern unsigned       nearcoreleft(void);
#ifdef __cplusplus
}
#endif
#endif

#endif
