/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  string.h -  Definitions for string and memory functions.                *
*                                                                          *
*  COPYRIGHT (C) 1989, 1990 Jensen and Partners. All Rights Reserved.      *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _STRING_INC_
#define _STRING_INC_

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
extern int     memcmp(const void *_s1, const void *_s2, size_t _n);
extern void *  memcpy(void *_dest, const void *_source, size_t _n);
extern void *  memset(void *_s, int _c, size_t _n);
extern char *  strcat(char *_dest, const char *_source);
extern int     strcmp(const char *_s1, const char *_s2);
extern char *  strcpy(char *_dest, const char *_source);
extern size_t  strlen(const char *_s);
extern char *  strset(char *_s, int _ch);
extern void *  memccpy(void *_dest, const void *_source, int _c, size_t _n);
extern void *  memchr(const void *_s, int _c, size_t _n);
extern int     memicmp(const void *_s1, const void *_s2, size_t _n);
extern void *  memmove(void *_dest, const void *_source, size_t _n);
extern void    movmem(void *_src, void *_dest, unsigned length);
extern void    setmem(void *_dest, unsigned length, char val);
extern void *  memwcpy(void *_dest, const void *_source, size_t _n);
extern void *  memwmove(void *_dest, const void *_source, size_t _n);
extern void *  memwset(void *_s, int _c, size_t _n);
extern char *  stpcpy(char *_dest, const char *_source);
extern char *  strchr(const char *_s, int _c);
extern int     strcoll(const char *_s1, const char *_s2);
extern size_t  strxfrm(char *_s1, const char *_s2, size_t _n);
extern size_t  strcspn(const char *_s1, const char *_s2);
extern char *  strdup(const char *_s);
extern char *  strerror(int _errnum);
extern int     stricmp(const char *_s1, const char *_s2);
extern char *  strlwr(char *_s);
extern char *  strncat(char *_dest, const char *_source, size_t _n);
extern int     strncmp(const char *_s1, const char *_s2, size_t _n);
extern char *  strncpy(char *_dest, const char *_source, size_t _n);
extern int     strnicmp(const char *_s1, const char *_s2, size_t _n);
extern char *  strnset(char *_s, int _ch, size_t _n);
extern char *  strpbrk(const char *_s1, const char *_s2);
extern char *  strrchr(const char *_s, int _c);
extern char *  strrev(char *_s);
extern size_t  strspn(const char *_s1, const char *_s2);
extern char *  strstr(const char *_s1, const char *_s2);
extern char *  strtok(char *_s1, const char *_s2);
extern char *  strupr(char *_s);
extern char *  _strerror (const char *_s);
#ifdef __cplusplus
}
#endif

/* compatibility with other compilers */
#define strcmpi(s1,s2)		stricmp(s1,s2)
#define strncmpi(s1,s2,n)	strnicmp(s1,s2,n)

#endif
