/* Release 3.10 */
/*-------------------------------------------------------------------------*
*                                                                          *
*  COMPLEX.HPP -  header file for complex math.                            *
*                                                                          *
*  COPYRIGHT (C) 1990..1992 Clarion Software Corporation                   *
*  All Rights Reserved                                                     *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef __COMPLEX_INC_
#define __COMPLEX_INC_

#include <iostream.hpp>
#include <math.h>

class complex {

friend double real(const complex&);
friend double imag(const complex&);
friend complex conj(const complex&);
friend double norm(const complex&);
friend double arg(const complex&);
friend complex polar(double _mag, double _angle = 0.0);

friend double abs(const complex&);
friend complex acos(const complex&);
friend complex asin(const complex&);
friend complex atan(const complex&);
friend complex cos(const complex&);
friend complex cosh(const complex&);
friend complex exp(const complex&);
friend complex log(const complex&);
friend complex log10(const complex&);
friend complex pow(const complex& _base, double _exp);
friend complex pow(double _base, const complex& _exp);
friend complex pow(const complex& _base, const complex& _exp);
friend complex sin(const complex&);
friend complex sinh(const complex&);
friend complex sqrt(const complex&);
friend complex tan(const complex&);
friend complex tanh(const complex&);

friend complex operator+(const complex&, const complex&);
friend complex operator+(double, const complex&);
friend complex operator+(const complex&, double);
friend complex operator-(const complex&, const complex&);
friend complex operator-(double, const complex&);
friend complex operator-(const complex&, double);
friend complex operator*(const complex&, const complex&);
friend complex operator*(double, const complex&);
friend complex operator*(const complex&, double);
friend complex operator/(const complex&, const complex&);
friend complex operator/(double, const complex&);
friend complex operator/(const complex&, double);
friend int operator==(const complex&, const complex&);
friend int operator!=(const complex&, const complex&);



public:

      complex(double _re_val, double _im_val=0);
      complex();

  const complex& operator+=(const complex&) ;
  const complex& operator+=(double) ;
  const complex& operator-=(const complex&) ;
  const complex& operator-=(double) ;
  const complex& operator*=(const complex&) ;
  const complex& operator*=(double) ;
  const complex& operator/=(const complex&) ;
  const complex& operator/=(double) ;
  complex operator+() const;
  complex operator-() const;

private:

  double re;
  double im;

};

inline complex::complex(double _re_val, double _im_val) {

  re = _re_val;
  im = _im_val;
}

inline complex::complex() {

  re = 0.0;
  im = 0.0;
}

inline complex complex::operator+() const {

  return *this;
}

inline complex complex::operator-() const {

  return complex(-re, -im);
}

inline const complex& complex::operator+=(const complex& _z) {

  re += _z.re;
  im += _z.im;
  return *this;
}

inline const complex& complex::operator+=(double _r) {

  re += _r;
  return *this;
}

inline const complex& complex::operator-=(const complex& _z) {

  re -= _z.re;
  im -= _z.im;
  return *this;
}

inline const complex& complex::operator-=(double _r) {

  re -= _r;
  return *this;
}

inline const complex& complex::operator*=(double _r) {

  re *= _r;
  im *= _r;
  return *this;
}

inline const complex& complex::operator/=(double _r) {

  re /= _r;
  im /= _r;
  return *this;
}


inline double real(const complex& _z) {

  return _z.re;
}

inline double imag(const complex& _z) {

  return _z.im;
}

inline complex conj(const complex& _z) {

  return complex(_z.re, -_z.im);
}

inline complex polar(double _mag, double _ang) {

  return complex(_mag*cos(_ang), _mag*sin(_ang));
}


inline complex operator+(const complex& _z1, const complex& _z2) {

  return complex(_z1.re + _z2.re, _z1.im + _z2.im);
}

inline complex operator+(double _r, const complex& _z) {

  return complex(_r + _z.re, _z.im);
}

inline complex operator+(const complex& _z, double _r) {

  return complex(_r + _z.re, _z.im);
}

inline complex operator-(const complex& _z1, const complex& _z2) {

  return complex(_z1.re - _z2.re, _z1.im - _z2.im);
}

inline complex operator-(double _r, const complex& _z) {

  return complex(_r - _z.re, -_z.im);
}

inline complex operator-(const complex& _z, double _r) {

  return complex(_r - _z.re, _z.im);
}

inline complex operator*(double _r, const complex& _z) {

  return complex(_r * _z.re, _r * _z.im);
}

inline complex operator*(const complex& _z, double _r) {

  return complex(_r * _z.re, _r * _z.im);
}

inline complex operator/(const complex& _z, double _r) {

  return complex(_z.re/_r, _z.im/_r);
}

inline int operator==(const complex& _z1, const complex& _z2) {

  return (_z1.re == _z2.re) && (_z1.im == _z2.im);
}

inline int operator!=(const complex& _z1, const complex& _z2) {

  return (_z1.re != _z2.re) || (_z1.im != _z2.im);
}

ostream& operator<<(ostream&, const complex&);
istream& operator>>(istream&, complex&);

#endif

