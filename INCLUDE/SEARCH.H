/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  search.h -  search and sort function prototypes.			   *
*                                                                          *
*  COPYRIGHT (C) 1989, 1990 Jensen and Partners. All Rights Reserved.      *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _SEARCH_INC_
#define _SEARCH_INC_

#ifndef NULL
#define NULL   0
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern void   * bsearch(const void *_key, const void *_base,
		       size_t _num, size_t _width,
		       int ( *_compare)(const void *_e1, const void *_e2));
extern void	 qsort(void *_base, size_t _num, size_t _width,
              int (  *_compare)(const void *_e1, const void *_e2));
extern char   * lfind(const char *_key, const char *_base,
	       unsigned *_num, unsigned _width,
	       int ( *_compare)(const void *_e1, const void *_e2));
extern char   * lsearch(const char *_key, char *_base,
		 unsigned *_num, unsigned _width,
		 int ( *_compare)(const void *_e1, const void *_e2));

#ifdef __cplusplus
}
#endif
#endif
