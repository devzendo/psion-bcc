/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  math.h -  floating point definitions and prototypes.                    *
*                                                                          *
*  COPYRIGHT (C) 1989, 1990 Jensen and Partners. All Rights Reserved.      *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _MATH_INC_
#define _MATH_INC_

#ifndef _ERRNOM_INC_
#define _ERRNOM_INC_

extern int   _doserrno;          /* global DOS error variable */
extern int   errno;              /* global error variable */
#endif

#define EDOM	(-2)		/* Math argument */
#define ERANGE	(-7)		/* Result too large */


#define DOMAIN       1     /* parameter not in valid domain */
#define SING         2     /* function is incalculable at this place */
#define OVERFLOW     3     /* result exceeds representable range */
#define UNDERFLOW    4     /* result too close to zero to be represented */
#define TLOSS        5     /* total loss of precision (eg. Sine (2**65)) */
#define PLOSS        6     /* partial precision loss */

#define HUGE_VAL	HUGE
#define LHUGE_VAL	LHUGE

extern double HUGE;
extern double LHUGE;

#ifdef __cplusplus
extern "C" {
#endif
extern int 	 abs(int _x);
extern double	 acos(double _x);
extern double	 asin(double _x);
extern double	 atan(double _x);
extern double	 atan2(double _y, double _x);
extern double	 atof(const char *_s);
extern double	 ceil(double _x);
extern double	 cos(double _x);
extern double	 cosh(double _x);
extern double	 exp(double _x);
extern double	 fabs(double _x);
extern double	 floor(double _x);
extern double	 fmod(double _x, double _y);
extern double	 frexp(double _x, int *_exp);
extern long	 labs(long _x);
extern double	 ldexp(double _x, int _exp);
extern double	 log(double _x);
extern double	 log10(double _x);
extern double	 modf(double _x, double *_ipart);
extern double   poly(double _x, int _degree, double _coeffs[]);
extern double	 pow(double _x, double _y);
extern double	 sin(double _x);
extern double	 sinh(double _x);
extern double	 sqrt(double _x);
extern double	 strtod(const char *_s, char **_eptr);
extern double	 tan(double _x);
extern double	 tanh(double _x);

extern long double	 acosl(long double _x);
extern long double	 asinl(long double _x);
extern long double	 atanl(long double _x);
extern long double	 atan2l(long double _y, long double _x);
extern long double	 atofl(const char *_s);
extern long double	 ceill(long double _x);
extern long double	 cosl(long double _x);
extern long double	 coshl(long double _x);
extern long double	 expl(long double _x);
extern long double	 fabsl(long double _x);
extern long double	 floorl(long double _x);
extern long double	 fmodl(long double _x, long double _y);
extern long double	 frexpl(long double _x, int *_exp);
extern long double	 ldexpl(long double _x, int _exp);
extern long double	 logl(long double _x);
extern long double	 log10l(long double _x);
extern long double	 modfl(long double _x, long double *_ipart);
extern long double      polyl(long double _x, int _degree, long double _coeffs[]);
extern long double	 powl(long double _x, long double _y);
extern long double	 sinl(long double _x);
extern long double	 sinhl(long double _x);
extern long double	 sqrtl(long double _x);
extern long double	 strtodl(const char *_s, char **_eptr);
extern long double	 tanl(long double _x);
extern long double	 tanhl(long double _x);
#ifdef __cplusplus
}
#endif

struct exception {
   int  type;
   char *name;
   double arg1,
          arg2,
   retval;
};

extern  int (* matherr)(struct exception *_x);
#ifdef __cplusplus
extern "C" {
#endif
extern double         hypot(double _x, double _y);
extern long double    hypotl(long double _x, long double _y);
extern double         pow10(int _p);
extern void           _fpreset(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
struct _complex {	    /* as used by cabs function */
    double  x,
            y;
};

struct _complexl {	    /* as used by cabsl function */
    long double  x,
                 y;
};
#else
struct complex {	    /* as used by cabs function */
    double  x,
            y;
};

struct complexl {	    /* as used by cabsl function */
    long double  x,
                 y;
};
#endif

#define cabs(z)     (hypot ((z).x, (z).y))
#define cabsl(z)    (hypotl((z).x, (z).y))

/* Constants rounded for 18 decimals. */
#define MA_E		 2.71828182845904524
#define MA_LOG2E	 1.44269504088896341
#define MA_LOG10E	 0.434294481903251828
#define MA_LN2		 0.693147180559945309
#define MA_LN10 	 2.30258509299404568
#define MA_PI		 3.14159265358979324
#define MA_PI_2 	 1.57079632679489662
#define MA_PI_4 	 0.785398163397448310
#define MA_1_PI 	 0.318309886183790672
#define MA_2_PI 	 0.636619772367581343
#define MA_1_SQRTPI	 0.564189583547756287
#define MA_2_SQRTPI	 1.12837916709551257
#define MA_SQRT2	 1.41421356237309505
#define MA_SQRT_2	 0.707106781186547524
#endif
