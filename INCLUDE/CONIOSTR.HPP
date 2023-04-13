/* Release 3.10 */
/*-------------------------------------------------------------------------*
*                                                                          *
*  CONIOSTR.HPP -  header file for console stream input and output.        *
*                                                                          *
*  COPYRIGHT (C) 1990..1992 Clarion Software Corporation                   *
*  All Rights Reserved                                                     *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _CONIOSTR_INC_
#define _CONIOSTR_INC_

#include <iostream.hpp>


class conbuf : public streambuf {

public:

  virtual int underflow();
  virtual int pbackfail(int);
  virtual int overflow(int _c = EOF);
  virtual int sync();

private:

  unsigned flush_magic;

};

extern istream conin;
extern ostream conout;

#endif
