/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  ctype.h -  header file for ctype macro definitions.                     *
*                                                                          *
*  COPYRIGHT (C) 1989, 1990 Jensen and Partners. All Rights Reserved.      *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _CTYPE_INC_
#define _CTYPE_INC_

#define _IS_SP      1			/* is space */
#define _IS_DIG     2			/* is digit indicator */
#define _IS_UPP     4			/* is upper case */
#define _IS_LOW     8			/* is lower case */
#define _IS_HEX    16			/* [A-F or [a-f] */
#define _IS_CTL    32			/* Control */
#define _IS_PUN    64			/* punctuation */

extern	char  _ctype[257];	        /* Character type array */

#ifdef __cplusplus
extern "C" {
#endif
extern int  isalnum(int _c);
extern int  isalpha(int _c);
extern int  isascii(int _c);	
extern int  iscntrl(int _c);
extern int  isdigit(int _c);
extern int  isgraph(int _c);
extern int  islower(int _c);
extern int  isprint(int _c);
extern int  ispunct(int _c);
extern int  isspace(int _c);
extern int  isupper(int _c);
extern int  isxdigit(int _c);

extern int  _toupper(int _c);
extern int  _tolower(int _c);
extern int  toascii(int _c);	
extern int  tolower(int _ch);        /* function prototypes */
extern int  toupper(int _ch);
#ifdef __cplusplus
}
#endif

#ifndef __STDC__

#ifdef _CT_FTM
#define toupper(c)  ((islower(c)) ? _toupper(c) : (c) )
#define tolower(c)  ((isupper(c)) ? _tolower(c) : (c) )
#endif

#ifndef  _CT_MTF                /* defines conversion macros */

#define isalnum(c)      (_ctype[(c)+1] & (_IS_DIG | _IS_UPP | _IS_LOW))
#define isalpha(c)      (_ctype[(c)+1] & (_IS_UPP | _IS_LOW))
#define isascii(c)	((unsigned)((c)) < 0x80)
#define iscntrl(c)      (_ctype[(c)+1] & _IS_CTL)
#define isdigit(c)      (_ctype[(c)+1] & _IS_DIG)
#define isgraph(c)	((c) >= 0x21 && (c) <= 0x7e)
#define islower(c)      (_ctype[(c)+1] & _IS_LOW)
#define isprint(c)	((c) >= 0x20 && (c) <= 0x7e)
#define ispunct(c)      (_ctype[(c)+1] & _IS_PUN)
#define isspace(c)      (_ctype[(c)+1] & _IS_SP)
#define isupper(c)      (_ctype[(c)+1] & _IS_UPP)
#define isxdigit(c)     (_ctype[(c)+1] & (_IS_DIG | _IS_HEX))

#define iscsymf(c)      (isalpha(c) || ((c) == '_'))
#define iscsym(c)       (isalnum(c) || ((c) == '_'))

#define _toupper(c)	((c) + 'A' - 'a')
#define _tolower(c)	((c) + 'a' - 'A')
#define toascii(c)	((c) & 0x7f)

#endif
#endif
#endif
