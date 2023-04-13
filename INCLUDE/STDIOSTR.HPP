/* Release 3.10 */
/*-------------------------------------------------------------------------*
*                                                                          *
*  STDIOSTR.HPP -  header file for stdio stream input and output.          *
*                                                                          *
*  COPYRIGHT (C) 1990..1992 Clarion Software Corporation                   *
*  All Rights Reserved                                                     *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _STDIOSTR_INC_
#define _STDIOSTR_INC_


#include <iostream.hpp>
#include <stdio.h>

class stdiobuf : public streambuf {

public:
      stdiobuf(FILE *);
      ~stdiobuf();

  FILE *stdiofile();
  virtual int overflow(int = EOF);
  virtual int pbackfail(int);
  virtual int sync();
  virtual streampos seekoff(streamoff, ios::seek_dir, int);
  virtual int underflow();

private:

  FILE *sio;
  long last_seek;
  int  gs;
  char lahead[2];
  int last_op();
};

inline FILE* stdiobuf::stdiofile() { return sio; }

class stdiostream : public ios {

public:

      stdiostream(FILE *);
      ~stdiostream();

  stdiobuf* rdbuf();

private:

  stdiobuf  buf;

};

inline stdiobuf* stdiostream::rdbuf() { return &buf; }

#endif

