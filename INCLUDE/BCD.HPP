/* Release 3.10 */
/*-------------------------------------------------------------------------*
*                                                                          *
*  BCD.HPP -  header file for BCD math.                                    *
*                                                                          *
*  COPYRIGHT (C) 1990..1992 Clarion Software Corporation                   *
*  All Rights Reserved                                                     *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef __BCD_INC_
#define __BCD_INC_

#include <math.h>
#include <iostream.hpp>

#define _BcdMaxDecimals 100

typedef enum { ExpZero, ExpNan };

class bcd {

friend long double real(bcd&);

friend bcd abs(bcd&);
friend bcd acos(bcd&);
friend bcd asin(bcd&);
friend bcd atan(bcd&);
friend bcd cos(bcd&);
friend bcd cosh(bcd&);
friend bcd exp(bcd&);
friend bcd log(bcd&);
friend bcd log10(bcd&);
friend bcd pow(bcd& base, bcd& expon);
friend bcd sin(bcd&);
friend bcd sinh(bcd&);
friend bcd sqrt(bcd&);
friend bcd tan(bcd&);
friend bcd tanh(bcd&);

friend bcd operator+(bcd&, bcd&);
friend bcd operator+(long double, bcd&);
friend bcd operator+(bcd&, long double);
friend bcd operator-(bcd&, bcd&);
friend bcd operator-(long double, bcd&);
friend bcd operator-(bcd&, long double);
friend bcd operator*(bcd&, bcd&);
friend bcd operator*(long double, bcd&);
friend bcd operator*(bcd&, long double);
friend bcd operator/(bcd&, bcd&);
friend bcd operator/(long double, bcd&);
friend bcd operator/(bcd&, long double);
friend int operator==(bcd&, bcd&);
friend int operator!=(bcd&, bcd&);
friend int operator>=(bcd&, bcd&);
friend int operator<=(bcd&, bcd&);
friend int operator>(bcd&, bcd&);
friend int operator<(bcd&, bcd&);
friend ostream& operator<<(ostream&, bcd&);
friend istream& operator>>(istream&, bcd&);

public:

     bcd(int x=0);
     bcd(unsigned x);
     bcd(long x);
     bcd(unsigned long x);
     bcd(double x, int decimals = _BcdMaxDecimals);
     bcd(long double x, int decimals = _BcdMaxDecimals);

     bcd& operator+=(bcd&);
     bcd& operator+=(long double);
     bcd& operator-=(bcd&);
     bcd& operator-=(long double);
     bcd& operator*=(bcd&);
     bcd& operator*=(long double);
     bcd& operator/=(bcd&);
     bcd& operator/=(long double);
     bcd  operator+();
     bcd  operator-();

  long double dec_to_real();
  void real_to_dec(long double num, int decimals = _BcdMaxDecimals);

private:

  void int_to_dec(unsigned long);
  void bcd_copy_from(unsigned char *dest);
  void bcd_copy_to(unsigned char *source);

  unsigned char bcd_array[10];
  unsigned char exp;
};


inline bcd::bcd(long double x, int decimals) {

  real_to_dec(x, decimals);
}

inline bcd::bcd(double x, int decimals) {

  real_to_dec((long double) x, decimals);
}


inline long double real(bcd& z) {

  return z.dec_to_real();
}

inline bcd& bcd::operator+=(bcd& b) {

  real_to_dec(real(*this)+real(b));
  return *this;
}

inline bcd& bcd::operator+=(long double b) {

  real_to_dec(real(*this)+b);
  return *this;
}

inline bcd& bcd::operator-=(bcd& b) {

  real_to_dec(real(*this)-real(b));
  return *this;
}

inline bcd& bcd::operator-=(long double b) {

  real_to_dec(real(*this)-b);
  return *this;
}

inline bcd& bcd::operator*=(bcd& b) {

  real_to_dec(real(*this)*real(b));
  return *this;
}

inline bcd& bcd::operator*=(long double b) {

  real_to_dec(real(*this)*b);
  return *this;
}

inline bcd& bcd::operator/=(bcd& b) {

  real_to_dec(real(*this)/real(b));
  return *this;
}

inline bcd& bcd::operator/=(long double b) {

  real_to_dec(real(*this)/b);
  return *this;
}

inline bcd operator+(bcd& a, bcd& b) {

  return bcd(real(a)+real(b));
}

inline bcd operator+(long double a, bcd& b) {

  return bcd(a+real(b));
}

inline bcd operator+(bcd& a, long double b) {

  return bcd(real(a)+b);
}

inline bcd operator-(bcd& a, bcd& b) {

  return bcd(real(a)-real(b));
}

inline bcd operator-(long double a, bcd& b) {

  return bcd(a-real(b));
}

inline bcd operator-(bcd& a, long double b) {

  return bcd(real(a)-b);
}

inline bcd operator*(bcd& a, bcd& b) {

  return bcd(real(a)*real(b));
}

inline bcd operator*(long double a, bcd& b) {

  return bcd(a*real(b));
}

inline bcd operator*(bcd& a, long double b) {

  return bcd(real(a)*b);
}

inline bcd operator/(bcd& a, bcd& b) {

  return bcd(real(a)/real(b));
}

inline bcd operator/(long double a, bcd& b) {

  return bcd(a/real(b));
}

inline bcd operator/(bcd& a, long double b) {

  return bcd(real(a)/b);
}

inline int operator==(bcd& a, bcd& b) {

  return real(a) == real(b);
}

inline int operator!=(bcd& a, bcd& b) {

  return real(a) != real(b);
}

inline int operator>=(bcd& a, bcd& b) {

  return real(a) >= real(b);
}

inline int operator<=(bcd& a, bcd& b) {

  return real(a) <= real(b);
}

inline int operator<(bcd& a, bcd& b) {

  return real(a) < real(b);
}

inline int operator>(bcd& a, bcd& b) {

  return real(a) > real(b);
}

inline bcd bcd::operator+() {

  return *this;
}

inline bcd abs(bcd& a) {

  return bcd(fabsl(real(a)));
}

inline bcd acos(bcd& a) {

  return bcd(acosl(real(a)));
}

inline bcd asin(bcd& a) {

  return bcd(asinl(real(a)));
}

inline bcd atan(bcd& a) {

  return bcd(atanl(real(a)));
}

inline bcd cos(bcd& a) {

  return bcd(cosl(real(a)));
}

inline bcd cosh(bcd& a) {

  return bcd(coshl(real(a)));
}

inline bcd exp(bcd& a) {

  return bcd(expl(real(a)));
}

inline bcd log(bcd& a) {

  return bcd(logl(real(a)));
}

inline bcd log10(bcd& a) {

  return bcd(log10l(real(a)));
}

inline bcd sin(bcd& a) {

  return bcd(sinl(real(a)));
}

inline bcd sinhl(bcd& a) {

  return bcd(sinhl(real(a)));
}

inline bcd sqrt(bcd& a) {

  return bcd(sqrtl(real(a)));
}

inline bcd tan(bcd& a) {

  return bcd(tanl(real(a)));
}

inline bcd tanh(bcd& a) {

  return bcd(tanhl(real(a)));
}

inline bcd pow(bcd& a, bcd& b) {

  return bcd(powl(real(a), real(b)));
}

inline bcd pow10(int n, bcd& a) {

  return bcd( pow10(n) * real(a) );
}


#endif

