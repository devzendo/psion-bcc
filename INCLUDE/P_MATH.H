/*	HEADER - P_MATH.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_MATH_H
#include <stdepoc.h>
#define ABS(x) ((x)<0 ? -(x) : (x))
#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define P_FLT_MAXEXP 1023 /* maximum magnitude of float exponent */ 
#define P_FLT_MANT 53 /* number of bits in mantissa (binary precission) */ 
#define P_FLT_PREC 15 /* approximate precision in decimal digits */ 
/* Cracked form of double float */
typedef struct
{
short int sign; /* P_FLT_ZERO,P_FLT_POS or P_FLT_NEG */ 
short int exp; /* signed binary exponent */ 
unsigned long int mant[2]; /* mantissa (least significant integer first) */ 
} P_CRKFLT;
/* values for sign above */
#define P_FLT_ZERO 0 /* value is zero */ 
#define P_FLT_POS 1 /* value is positive */ 
#define P_FLT_NEG 2 /* value is negative */ 
/* format specification for p_dtob() */
typedef struct
{
unsigned char type; /* conversion type */ 
unsigned char width; /* width of representation in characters */ 
unsigned char ndec; /* number of decimal places */ 
char point; /* decimal point character */ 
char triad; /* triad separator character */ 
unsigned char trilen; /* threshold for triad character use */ 
} P_DTOB;
/* values for type in the above */
#define P_DTOB_FIXED 0 /* fixed number of decimap points */ 
#define P_DTOB_EXPONENT 1 /* exponent notation */ 
#define P_DTOB_GENERAL 2 /* general format */ 
/* Struct for p_poly() */
typedef struct
{
unsigned short int num; /* number of coefficients */ 
double c[1]; /* coefficient table */ 
} P_POLY;
/* DOUBLE constants */
#define SQHF .70710678118654752440 /* Square root of a half */ 
#define RLN2 1.4426950408889634 /* Reciprocal of ln 2 */ 
#define RLN10 0.4342944819032518 /* Reciprocal of ln 10 */ 
#define RLG2 0.3010299956639812 /* Reciprocal of log 2 */ 
#define PI  3.1415926535897932 /* Pi */ 
#define RPI  0.3183098861837907 /* Reciprocal of Pi */ 
#define PIB2 1.5707963267948966 /* pi/2 */ 
#define DRPI 0.6366197723675813 /* 2/pi */ 
#define SQT3 1.7320508075688773 /* Square root of three */ 
#define MSQ3 0.2679491924311227 /* 2 minus square root of three */ 
#define RADTODEG 57.29577951308232 /* 1 radian in degrees (180/pi) */ 
#define DEGTORAD 0.017453292519943296 /* 1 degree in radians */ 
#ifdef __cplusplus
extern "C" {
#endif
#pragma save,call(reg_param =>(si,di,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_stod(char **,double *,int);
#pragma call(reg_param =>(di,si,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_dtob(char *,const double *,P_DTOB *);
extern int p_acos(double *,const double *);
extern int p_asin(double *,const double *);
extern int p_atan(double *,const double *);
extern int p_cos(double *,const double *);
extern int p_exp(double *,const double *);
extern int p_ln(double *,const double *);
extern int p_log(double *,const double *);
extern int p_mod(double *,const double *,const double *);
extern int p_pow(double *,const double *,const double *);
extern int p_sin(double *,const double *);
extern int p_sqrt(double *,const double *);
extern int p_tan(double *,const double *);
extern int p_int(double *,const double *);
extern int p_inti(short int *,const double *);
extern int p_fadd(double *,const double *);
extern int p_fsub(double *,const double *);
extern int p_fmul(double *,const double *);
extern int p_fdiv(double *,const double *);
extern int p_fcmp(double *,const double *);
extern void p_frand(double *,double *);
extern int p_fld(double *,const double *);
extern void p_itof(double *,const short int *);
extern int p_fneg(double *);
#pragma call(reg_param =>(di,si,dx),reg_saved =>(cx,dx,si,di,EPOC_SAVE))
extern int p_intl(long int *,const double *);
extern void p_longtof(double *,const long int *);
#pragma call(reg_param =>(di,si,dx),reg_saved =>(si,EPOC_SAVE))
extern double p_rand(unsigned long int *);
#pragma restore
#ifdef __cplusplus
}
#endif

