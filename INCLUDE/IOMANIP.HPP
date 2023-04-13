/* Release 3.10 */
/*-------------------------------------------------------------------------*
*                                                                          *
*  IOMANIP.HPP -  header file for pasting I/O manipulators.                *
*                                                                          *
*  COPYRIGHT (C) 1990..1992 Clarion Software Corporation                   *
*  All Rights Reserved                                                     *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef __IOMANIP_INC_
#define __IOMANIP_INC_

#include <iostream.hpp>
#include <generic.hpp>

#define SMANIP(type)    _PASTE2(smanip_, type)
#define SAPP(type)      _PASTE2(sapply_, type)
#define IMANIP(type)    _PASTE2(imanip_, type)
#define OMANIP(type)    _PASTE2(omanip_, type)
#define IOMANIP(type)   _PASTE2(iomanip_, type)
#define IAPP(type)      _PASTE2(iapply_, type)
#define OAPP(type)      _PASTE2(oapply_, type)
#define IOAPP(type)     _PASTE2(ioapply_, type)

#define IOMANIPdeclare(type)             \
class SMANIP(type) {                     \
	ios& (*_fn)(ios&, type);         \
	type _ag;                        \
public:                                  \
      SMANIP(type)(ios& (*_f)(ios&, type), type _a) : _fn(_f), _ag(_a) { } \
  friend istream& operator>>(istream& _s, const SMANIP(type)& _f) {              \
                                   (*_f._fn)(_s, _f._ag); return _s; }     \
  friend ostream& operator<<(ostream& _s, const SMANIP(type)& _f) {              \
                            (*_f._fn)(_s, _f._ag); return _s; }            \
};                                                                         \
class SAPP(type) {         \
  ios& (*_fn)(ios&, type); \
public:                    \
  SAPP(type)(ios& (*_f)(ios&, type)) : _fn(_f) { }                          \
  SMANIP(type)  operator()(type _z) { return SMANIP(type)(_fn, _z); } \
};                                                                          \
class IMANIP(type) {               \
  istream& (*_fn)(istream&, type); \
  type _ag;                        \
public:                            \
  IMANIP(type)(istream& (*_f)(istream&, type), type _z ) :      \
               _fn(_f), _ag(_z) { }                             \
  friend istream& operator>>(istream& _s, const IMANIP(type)& _f) {	\
		return(*_f._fn)(_s, _f._ag); }                  \
};                                                              \
class IAPP(type) {                 \
  istream& (*_fn)(istream&, type); \
public:	                           \
  IAPP(type)(istream& (*_f)(istream&, type)) : _fn(_f) { }      \
  IMANIP(type) operator()(type _z) {                            \
                          return IMANIP(type)(_fn, _z); }       \
};                                                              \
class OMANIP(type) {                \
  ostream& (*_fn)(ostream&, type);  \
  type _ag;                         \
public:                             \
  OMANIP(type)(ostream& (*_f)(ostream&, type), type _z ) :    \
                          _fn(_f), _ag(_z) { }                \
  friend ostream& operator<<(ostream& _s, const OMANIP(type)& _f) { \
                               return(*_f._fn)(_s, _f._ag); } \
};                                                            \
class OAPP(type) {                 \
  ostream& (*_fn)(ostream&, type); \
public:                            \
  OAPP(type)(ostream& (*_f)(ostream&, type)) : _fn(_f) { }           \
  OMANIP(type) operator()(type _z) { return OMANIP(type)(_fn, _z); } \
};                                                                   \
class IOMANIP(type) {                \
  iostream& (*_fn)(iostream&, type); \
  type _ag;                          \
public:	                             \
  IOMANIP(type)(iostream& (*_f)(iostream&, type), type _z ) :   \
                            _fn(_f), _ag(_z) { }                \
  friend istream& operator>>(iostream& _s, const IOMANIP(type)& _f) {	\
                                 return(*_f._fn)(_s, _f._ag); }	\
  friend ostream& operator<<(iostream& _s, const IOMANIP(type)& _f) {	\
                                 return(*_f._fn)(_s, _f._ag); }	\
};                                                              \
class IOAPP(type) {                                             \
  iostream&  (*_fn)(iostream&, type);                     \
public:								\
  IOAPP(type)(iostream& (*_f)(iostream&, type)) : _fn(_f) { }   \
  IOMANIP(type) operator()(type _z) { return IOMANIP(type)(_fn, _z); } \
}


//CEP 6/7/91
#pragma save,warn(wpnu=>off)
IOMANIPdeclare(int);
IOMANIPdeclare(long);
#pragma restore

smanip_int  setbase(int _b);

smanip_long resetiosflags(long _b);

smanip_long setiosflags(long _b);

smanip_int  setfill(int _f);

smanip_int  setprecision(int _n);

smanip_int  setw(int _n);

#endif
