/* Release 3.10 */
/*-------------------------------------------------------------------------*
*                                                                          *
*  STREAM.HPP -  header file for AT&T v1.2 stream input and output.        *
*                                                                          *
*  COPYRIGHT (C) 1990..1992 Clarion Software Corporation                   *
*  All Rights Reserved                                                     *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef __STREAM_INC_
#define __STREAM_INC_

#include <stdio.h>

#pragma save
#pragma name(prefix=>"__o__")

struct whitespace {
  char x;
};

extern struct whitespace WS;

class istream;
class ostream;

class streambuf {

friend istream;
friend ostream;

protected:

  FILE *file;
  char *base;
  char *pptr;
  char *gptr;
  char *eptr;
  int   didalloc;

  virtual int overflow(int = EOF );
  virtual int underflow();

  int  allocate();
  streambuf * setbuf(char *, int , unsigned = 0);

  virtual void terminate();

public:
      streambuf() { file=0; didalloc=0; base=pptr=gptr=eptr=NULL; }
      streambuf(char *buf, int len) { file=0; didalloc=0; setbuf(buf, len); }
  virtual ~streambuf();

  virtual int snextc();
  virtual int sputc(int);
  virtual void sputbackc(char);

};

enum open_mode {
  input,
  output,
  append
};

class filebuf : public streambuf {

private:

  int fd;
  int isopen;

protected:

  void terminate();

public:

      filebuf() { isopen=0; fd=0; }
      filebuf(FILE *);
      filebuf(int);
      filebuf(int, char *, int);
      ~filebuf() { close(); }

  filebuf* open(char *, int);
  int close();
  int snextc() { return ::fgetc(file); }
  int sputc(int _c) { return ::fputc(_c, file); }
  void sputbackc(char _c) { (void) :: ungetc(_c, file); }
};

char *dec(long, int = 0);
char *hex(long, int = 0);
char *oct(long, int = 0);
char *chr(int, int = 0);
char *str(const char *, int = 0);
char *form(char *, ...);

enum stream_state {
  _good=0,
  _eof=1,
  _fail=2,
  _bad=4
};

class ostream {

friend istream;

private:

  streambuf* stream;
  char mystream;
  char state;

public:

      ostream(streambuf *);
      ostream(int);
      ostream(int, char *);
      ~ostream() { (void) flush(); if(mystream) delete stream; }

  operator void*() { return (state == _good) ? this : NULL; }
  int operator !() { return (state != _good); }

  ostream& operator <<(int);
  ostream& operator <<(long);
  ostream& operator <<(unsigned int _U) { return *this << ((long) _U); }
  ostream& operator <<(unsigned long);
  ostream& operator <<(const char *);
  ostream& operator <<(double);
  ostream& operator <<(long double);

  ostream& put(char _c) { if(stream->sputc(_c) == EOF)
                            state = _fail;
                           return *this; }

  ostream& flush();

  int rdstate() { return state; }
  void clear(int _s = _good) { state = _s; }
  int  bad() { return (state & _bad); }
  int  fail() { return (state & _fail); }
  int  eof() { return (state & _eof); }
  int  good() { return (state == _good); }

};

class istream {

friend void eatwhite(istream& _s) {_s >> WS; }

private:
  ostream* tied_to;
  streambuf* stream;
  char skipping;
  char mystream;
  int state;

  long getlong(int);
  long double getreal();

public:
      istream(streambuf*, int = 1, ostream* = NULL);
      istream(int, char*, int = 1);
      istream(int, int = 1, ostream* = NULL);
      ~istream() { if(mystream) delete stream; }

  operator void*() { return (state == _good) ? this : NULL; }
  int operator !() { return (state != _good); }

  istream& operator >> (signed char& _c) { unsigned char _x;
                                          *this >> _x;
                                          if(state == _good)
                                            _c=(signed char) _x;
                                          return *this; }

  istream& operator >> (       char& _c) { unsigned char _x;
                                          *this >> _x;
                                          if(state == _good)
                                            _c=(char) _x;
                                          return *this; }

  istream& operator >> (short& _s){ short _x= (short) getlong(0);
                                    if(state == _good)
                                      _s=_x;
                                    return *this; }

  istream& operator >> (int& _i) { int _x= (int) getlong(0);
                                  if(state == _good)
                                    _i=_x;
                                  return *this; }

  istream& operator >> (long& _l){ long _x= getlong(0);
                                   if(state == _good)
                                     _l=_x;
                                   return *this; }


  istream& operator >> (unsigned char& _c);

  istream& operator >> (unsigned short& _s){ unsigned short _x= (unsigned short) getlong(0);
                                             if(state == _good)
                                               _s=_x;
                                             return *this; }

  istream& operator >> (unsigned int& _i){ unsigned int _x= (unsigned int) getlong(0);
                                           if(state == _good)
                                              _i=_x;
                                           return *this; }

  istream& operator >> (unsigned long& _l){ unsigned long _x= (unsigned long) getlong(0);
                                          if(state == _good)
                                            _l=_x;
                                          return *this; }

  istream& operator >>(float&);
  istream& operator >>(double&);
  istream& operator >>(long double&);
  istream& operator >>(char *);
  istream& operator >>(whitespace&);
  istream& get(char&);
  istream& get(char*, int, int = '\n');

  int skip(int _s) { short _t = skipping; skipping = _s; return _t;  }
  ostream * tie( ostream *_to ) { ostream *_t = tied_to; tied_to = _to; return _t; }
  void putback(char _c) { stream->sputbackc(_c); };
  int rdstate() { return state; }
  void clear(int _s = _good) { state = _s; }
  int  bad() { return (state & _bad); }
  int  fail() { return (state & _fail); }
  int  eof() { return (state & _eof); }
  int  good() { return (state == _good); }

};

extern istream cin;
extern ostream cout;
extern ostream cerr;

#pragma restore

#endif
