/* Release 3.10 */
/*-------------------------------------------------------------------------*
*                                                                          *
*  FSTREAM.HPP -  header file for file stream input and output.            *
*                                                                          *
*  COPYRIGHT (C) 1990..1992 Clarion Software Corporation                   *
*  All Rights Reserved                                                     *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef __FSTREAM_INC_
#define __FSTREAM_INC_

#include <iostream.hpp>

class  filebuf : public streambuf {

public:
  static const int openprot;

      filebuf();
      filebuf(int);
      filebuf(int _f, char*, int);
      ~filebuf();

  int  is_open();	
  int  fd();	

  filebuf*  open(const char*, int, int = filebuf::openprot);

  filebuf*  close();
  filebuf*  attach(int);	
  virtual int overflow(int = EOF);
  virtual int underflow();
  virtual int sync();
  virtual streampos seekoff(streamoff, ios::seek_dir, int);
  virtual streambuf* setbuf(char*, int);

protected:

  int  last_op();
  int  xfd;
  int  mode;	
  short opened;	
  streampos last_seek;
  char*  in_start;
  char   lahead[2];	
};

inline int filebuf::is_open() { return opened; }
inline int filebuf::fd()      { return xfd; }

class fstreambase : virtual public ios {

public:

       fstreambase();
       fstreambase(const char*, int, int = filebuf::openprot);
       fstreambase(int);
       fstreambase(int _f, char*, int);
       ~fstreambase();

  void  open(const char*, int, int = filebuf::openprot);
  void  attach(int);
  void  close();
  void  setbuf(char*, int);
  filebuf* rdbuf();

private:

  filebuf buf;

};

inline filebuf* fstreambase::rdbuf() { return &buf; }


class ifstream : public fstreambase, public istream {

public:
      ifstream();
      ifstream(const char*, int = ios::in, int = filebuf::openprot);
      ifstream(int);
      ifstream(int _f, char*, int);
      ~ifstream();

  filebuf* rdbuf();
  void  open(const char*, int = ios::in, int = filebuf::openprot);

};

inline filebuf* ifstream::rdbuf() { return fstreambase::rdbuf(); }
inline void  ifstream::open(const char* name, int m, int prot) {
                            fstreambase::open(name, m | ios::in, prot); }


class ofstream : public fstreambase, public ostream {

public:
      ofstream();
      ofstream(const char*, int = ios::out, int = filebuf::openprot);
      ofstream(int);
      ofstream(int _f, char*, int);
      ~ofstream();

  filebuf* rdbuf();
  void  open(const char*, int = ios::out, int = filebuf::openprot);

};

inline filebuf* ofstream::rdbuf() { return fstreambase::rdbuf(); }
inline void  ofstream::open(const char* name, int m, int prot) {
                            fstreambase::open(name, m | ios::out, prot); }


class fstream : public fstreambase, public iostream {

public:
      fstream();
      fstream(const char*, int, int = filebuf::openprot);
      fstream(int);
      fstream(int _f, char*, int);
      ~fstream();

  filebuf* rdbuf();
  void open(const char *, int, int = filebuf::openprot);

};

inline filebuf* fstream::rdbuf() { return fstreambase::rdbuf(); }
inline void fstream::open(const char* name, int m, int prot) {
                          fstreambase::open(name, m, prot); }

#endif