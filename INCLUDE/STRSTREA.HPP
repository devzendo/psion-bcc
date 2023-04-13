/* Release 3.10 */
/*-------------------------------------------------------------------------*
*                                                                          *
*  STRSTREA.HPP -  header file for string stream input and output.         *
*                                                                          *
*  COPYRIGHT (C) 1990..1992 Clarion Software Corporation                   *
*  All Rights Reserved                                                     *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _STRSTREAM_INC_
#define _STRSTREAM_INC_

#include <iostream.hpp>

class strstreambuf : public streambuf {

public:
        strstreambuf();
        strstreambuf(int _n);
        strstreambuf(void * (*a)(long), void (*f)(void*));
        strstreambuf(char *_s, int ,   char *_start=NULL);
        ~strstreambuf();

  void freeze(int = 1);
  char *str();
  virtual int doallocate();
  virtual int overflow(int);
  virtual int underflow();
  virtual streambuf *setbuf(char *, int);
  virtual streampos seekoff(streamoff, ios::seek_dir, int);

private:

  enum   {
    dynamic = 1,
    frozen = 2,
    unlimited = 4 };

  void * (*allocf)(long);
  void   (*freef)(void *);
  void   init(char *, int, char *);
  short  flags;
  int    next_alloc;
};

class strstreambase : public virtual ios {

public:

  strstreambuf* rdbuf();

protected:

      strstreambase(char *, int, char *);
      strstreambase();
      ~strstreambase();

private:

  strstreambuf buf;

};

inline strstreambuf* strstreambase::rdbuf() { return &this->buf; }

class istrstream : public strstreambase, public istream {

public:

      istrstream(char *);
      istrstream(char *, int);
      ~istrstream();
};

class ostrstream : public strstreambase, public ostream {

public:

      ostrstream();
      ostrstream(char *, int, int);
      ~ostrstream();

  char *str();
  int  pcount();

};

inline char *ostrstream::str() { return strstreambase::rdbuf()->str(); }
inline int   ostrstream::pcount() { return strstreambase::rdbuf()->out_waiting(); }

class strstream : public strstreambase, public iostream {

public:

      strstream();
      strstream(char *, int _sz, int _m);
      ~strstream();

  char *str();

};

inline char *strstream::str() { return strstreambase::rdbuf()->str(); }

#endif

