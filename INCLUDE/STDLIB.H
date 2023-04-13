/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  stdlib.h - definitions for common variables, types and functions.       *
*                                                                          *
*  COPYRIGHT (C) 1989, 1990 Jensen and Partners. All Rights Reserved.      *
*                                                                          *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _STDLIB_INC_
#define _STDLIB_INC_

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

#ifndef _WCHAR_T
#define _WCHAR_T
typedef unsigned char wchar_t;
#endif

#ifndef NULL
#define NULL   0
#endif

#define MB_CUR_MAX 1

#ifndef _LDIV_T
#define _LDIV_T
typedef struct {
   long    quot;
   long    rem;
} ldiv_t;
#endif

#ifndef _DIV_T
#define _DIV_T
typedef struct {
   int    quot;
   int    rem;
} div_t;
#endif

#ifndef _ERRNOL_INC_
#define _ERRNOL_INC_
extern int   _doserrno;          /* global DOS error variable */
extern int   errno;              /* global error variable */
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern void	      abort(void);
extern int           abs(int _num);
extern int           atexit(void (*_func)(void));
extern double        atof(const char *_nptr);
extern long double   atofl(const char *_nptr);
extern int           atoi(const char *_nptr);
extern long          atol(const char *_nptr);
extern unsigned long atoul(const char *_nptr);
extern void *        bsearch(const void *_key, const void *_base,
		      size_t _nmemb, size_t _size,
		      int ( *_compare)(const void *_e1, const void *_e2));
extern void *        calloc(size_t _num, size_t _size);
extern void          delay(int _tm);
extern div_t         div(int _numer, int _denom);
extern char *        ecvt(double _value, int _digits, int *_dec, int *_sign);
extern void	      _exit(int _status);
extern void	      exit(int _code);
extern char *        fcvt(double _value, int _digits, int *_dec, int *_sign);
extern void          free(void *_block);
extern char *        gcvt(double _value, int _ndec, char *_buf);
extern char *        gcvtl(long double _value, int _ndec, char *_buf);
extern char *        getenv(const char *_name);
extern char *        itoa(int _value, char *_string, int _radix);
extern long	      labs(long _j);
extern ldiv_t        ldiv(long _numer, long _denom);
extern char *        lfind(const char *_key, const char *_base,
		    unsigned *_num, unsigned _width,
		    int ( *_compare)(const void *_e1, const void *_e2));
extern unsigned long _lrotl(unsigned long _val, int _count);
extern unsigned long _lrotr(unsigned long _val, int _count);
extern char *        lsearch(const char *_key, char *_base,
		      unsigned *_num, unsigned _width,
		      int ( *_compare)(const void *_e1, const void *_e2));
extern char *        ltoa(long _value, char *_s, int _radix);
extern void          _makepath(char *_path, const char *_drive, const char *_dir,
	                const char *_name, const char *_ext);
extern void *        malloc(size_t _size);
extern int           mblen(const char *_s, size_t _n);
extern size_t        mbstowcs(wchar_t *_pwcs, const char *_s, size_t _n);
extern int           mbtowc(wchar_t *_pwc, const char *_s, size_t _n);
extern void       (* onexit(void ( *_func)(void)))();
extern int           putenv(const char *_name);
extern void	      qsort(void *_base, size_t _nmemb, size_t _size,
		    int (*_compare)(const void *_e1, const void *_e2));
extern int	      rand(void);
extern void          randomize(void);
extern void *        realloc(void *_block, size_t _size);
extern unsigned      _rotl(unsigned _value, int _count);
extern unsigned      _rotr(unsigned _value, int _count);

extern void          _searchenv(const char *_name, const char *_env, char *_path);
extern void          _splitpath(const char *_path, char *_drive, char *_dir,
                        char *_name, char *_ext);
extern void	      srand(unsigned _seed);
extern double	      strtod(const char *_s, char **_endptr);
extern long	      strtol(const char *_s, char **_endptr, int _base);
extern unsigned long strtoul(const char *_s, char **_endptr, int _base);
extern void          swab(const char *_from, char *_to, int _num);
extern int	      system(const char *_string);
extern char *        ultoa(unsigned long _value, char *_s, int _radix);
extern int           wctomb(char *_s, wchar_t _wchar);
extern size_t        wcstombs(char *_s, const wchar_t *_pwcs, size_t _n);
#ifdef __cplusplus
}
#endif


/* Variables */

extern	unsigned int	 _fmode;
extern	char	       * sys_errlist[38];
extern	int		 sys_nerr;

#define EXIT_SUCCESS	0
#define EXIT_FAILURE	0xFF

#ifndef max
#define max(a,b)	(((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a,b)	(((a) < (b)) ? (a) : (b))
#endif

#define random(num)	(rand() % (num))
#define RAND_MAX 32767


#define _MAX_PATH  144      /* maximum length of full pathname */
#define _MAX_DRIVE   4      /* maximum length of drive component */
#define _MAX_DIR   130      /* maximum length of path component */
#define _MAX_FNAME   9      /* maximum length of file name component */
#define _MAX_EXT     5      /* maximum length of extension component */

#endif
