/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  locale.h -  locale definitions and prototypes.                          *
*                                                                          *
*  COPYRIGHT (C) 1989, 1990 Jensen and Partners. All Rights Reserved.      *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _LOCALE_INC_
#define _LOCALE_INC_

#ifndef NULL
#define NULL   0
#endif

#define LC_ALL      0
#define LC_COLLATE  1
#define LC_CTYPE    2
#define LC_NUMERIC  3
#define LC_TIME     4
#define LC_MONETARY 5

struct lconv {
     char *decimal_point;
     char *thousands_sep;
     char *grouping;
     char *int_curr_symbol;
     char *currency_symbol;
     char *mon_decimal_point;
     char *mon_thousands_sep;
     char *mon_grouping;
     char *positive_sign;
     char *negative_sign;
     char int_frac_digits;
     char frac_digits;
     char p_cs_precedes;
     char p_sep_by_space;
     char n_cs_precedes;
     char n_sep_by_space;
     char p_sign_posn;
     char n_sign_posn;
};

#ifdef __cplusplus
extern "C" {
#endif
extern struct lconv * localeconv(void);
extern char *         setlocale(int _category, const char *_locale);
#ifdef __cplusplus
}
#endif
#endif
