/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  float.h -  Implementation specific macros for floating point.           *
*                                                                          *
*  COPYRIGHT (C) 1989, 1990 Jensen and Partners. All Rights Reserved.      *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _FLOAT_INC_
#define _FLOAT_INC_

#define DBL_DIG         15                      /* number of decimal digits of precision */
#define DBL_MANT_DIG    53                      /* number of bits in mantissa */
#define DBL_MAX_10_EXP  308                     /* maximum decimal exponent */
#define DBL_MAX_EXP     1024                    /* maximum binary exponent */
#define DBL_MIN_10_EXP  -307                    /* minimum decimal exponent */
#define DBL_MIN_EXP     -1021                   /* minimum binary exponent */
#define DBL_RADIX       2                       /* exponent radix */
#define DBL_ROUNDS      1                       /* addition rounding */
#define DBL_EPSILON     2.2204460492503131e-016 /* 1.0+DBL_EPSILON != 1.0 */
#define DBL_MAX         1.7976931348623151e+308 /* maximum value */
#define DBL_MIN         2.2250738585072014e-308 /* minimum positive value */

#define FLT_DIG         6                       /* number of decimal digits of precision */
#define FLT_GUARD       0
#define FLT_MANT_DIG    24                      /* number of bits in mantissa */
#define FLT_MAX_10_EXP  38                      /* maximum decimal exponent */
#define FLT_MAX_EXP     128                     /* maximum binary exponent */
#define FLT_MIN_10_EXP  -37                     /* minimum decimal exponent */
#define FLT_MIN_EXP     -125                    /* minimum binary exponent */
#define FLT_NORMALIZE   0
#define FLT_RADIX       2                       /* exponent radix */
#define FLT_ROUNDS      1                       /* addition rounding chops */
#define FLT_EPSILON     1.192092896e-07         /* smallest such that 1.0+FLT_EPSILON != 1.0 */
#define FLT_MAX         3.402823466e+38         /* maximum value */
#define FLT_MIN         1.175494351e-38         /* minimum positive value */

#define LDBL_DIG        19                      /* number of decimal digits of precision */
#define LDBL_EPSILON    5.4210108624275221706e-20     /* smallest such that 1.0+LDBL_EPSILON != 1.0 */
#define LDBL_MANT_DIG   64                      /* number of bits in mantissa */
#define LDBL_MAX        1.189731495357231765e+4932L   /* maximum value */
#define LDBL_MAX_10_EXP 4932                    /* maximum decimal exponent */
#define LDBL_MAX_EXP    16384                   /* maximum binary exponent */
#define LDBL_MIN        3.3621031431120935063e-4932L  /* minimum positive value */
#define LDBL_MIN_10_EXP (-4931)                 /* minimum deimal exponent */
#define LDBL_MIN_EXP    (-16381)                /* minimum binary exponent */
#define LDBL_RADIX      2                       /* exponent radix */
#define LDBL_ROUNDS     DBL_ROUNDS              /* addition rounding */

/*  X087 math control information */

/* Control Word Mask and bit definitions */

#define     MCW_EM          0x003f      /* interrupt Exception Masks */
#define     EM_INVALID      0x0001      /* invalid */
#define     EM_DENORMAL     0x0002      /* denormal */
#define     EM_ZERODIVIDE   0x0004      /* zero divide */
#define     EM_OVERFLOW     0x0008      /* overflow */
#define     EM_UNDERFLOW    0x0010      /* underflow */
#define     EM_INEXACT      0x0020      /* inexact */

#define     MCW_IC          0x1000      /* Infinity Control */
#define     IC_AFFINE       0x1000      /* affine */
#define     IC_PROJECTIVE   0x0000      /* projective */

#define     MCW_RC          0x0c00      /* Rounding Control */
#define     RC_CHOP         0x0c00      /* chop */
#define     RC_UP           0x0800      /* up */
#define     RC_DOWN         0x0400      /* down */
#define     RC_NEAR         0x0000      /* near */

#define     MCW_PC          0x0300      /* Precision Control */
#define     PC_24           0x0000      /* 24 bits */
#define     PC_53           0x0200      /* 53 bits */
#define     PC_64           0x0300      /* 64 bits */

/* Initial Control Word value */

#define CW_DEFAULT ( IC_AFFINE + RC_NEAR + PC_64 + EM_DENORMAL + EM_UNDERFLOW + EM_INEXACT )

/* user Status Word bit definitions */

#define SW_INVALID          0x0001      /* invalid */
#define SW_DENORMAL         0x0002      /* denormal */
#define SW_ZERODIVIDE       0x0004      /* zero divide */
#define SW_OVERFLOW         0x0008      /* overflow */
#define SW_UNDERFLOW        0x0010      /* underflow */
#define SW_INEXACT	    0x0020	/* precision inexact	*/

/*  Floating point error signals */

#define FPE_INVALID         0x81
#define FPE_DENORMAL        0x82
#define FPE_ZERODIVIDE      0x83
#define FPE_OVERFLOW        0x84
#define FPE_UNDERFLOW       0x85
#define FPE_INEXACT         0x86

/* X087 control function prototypes */

#ifdef __cplusplus
extern "C" {
#endif
extern unsigned int  _clear87(void);
extern unsigned int  _control87(unsigned int _new, unsigned int _mask);
extern void  _fpreset(void);
extern unsigned int  _status87(void);
#ifdef __cplusplus
}
#endif
#endif
