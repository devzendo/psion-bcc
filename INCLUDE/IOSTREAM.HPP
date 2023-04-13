/* Release 3.10 */
/*-------------------------------------------------------------------------*
*                                                                          *
*  IOSTREAM.HPP -  header file for stream input and output.                *
*                                                                          *
*  COPYRIGHT (C) 1990..1992 Clarion Software Corporation                   *
*  All Rights Reserved                                                     *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _IOSTREAM_INC_
#define _IOSTREAM_INC_

#include <mem.h>

#ifdef EOF
#if EOF != -1
#undef EOF
#define EOF (-1)
#endif
#else
#define EOF (-1)
#endif

#define zapeof(c) ((c)&0xFF)

typedef long streampos;
typedef long streamoff;

class streambuf;
class ostream;

class  ios {

public:
  enum io_state {
    goodbit  = 0x00,
    eofbit   = 0x01,
    failbit  = 0x02,
    badbit   = 0x04,
    hardfail = 0x80
  };

  enum open_mode {
    in        = 0x01,
    out       = 0x02,
    ate       = 0x04,
    app       = 0x08,
    trunc     = 0x10,
    nocreate  = 0x20,
    noreplace = 0x40,
    binary    = 0x80
  };

  enum seek_dir {
    beg=0,
    cur=1,
    end=2
  };

  enum {
    skipws        = 0x0001,
    left          = 0x0002,
    right         = 0x0004,
    internal      = 0x0008,
    dec           = 0x0010,
    oct           = 0x0020,
    hex           = 0x0040,
    showbase      = 0x0080,
    showpoint     = 0x0100,
    uppercase     = 0x0200,
    showpos       = 0x0400,
    scientific    = 0x0800,
    fixed         = 0x1000,
    unitbuf       = 0x2000,
    stdio         = 0x4000
  };

  static const long basefield;
  static const long adjustfield;
  static const long floatfield;

  ios(streambuf* _buffer);
  virtual ~ios();

  long flags();
  long flags(long _fl);
  long setf(long _setbits, long _fld);
  long setf(long _fld);
  long unsetf(long _fld);

  int width();
  int width(int _w);

  char fill();
  char fill(char _f);

  int precision();
  int precision(int _p);

  ostream* tie();
  ostream* tie(ostream* _ost);

  int rdstate();
  int eof();
  int fail();
  int bad();
  int good();
  void clear(int = 0);
       operator void* ();
  int  operator! ();
  streambuf* rdbuf();

  static long bitalloc();
  static int  xalloc();
  long&  iword(int);
  void*& pword(int);

  static void sync_with_stdio();

  int skip(int);

protected:

  enum {
    translate = 0x080,
    skipping  = 0x100,
    tied      = 0x200
  };

  streambuf *_bp;
  ostream*  x_tie;
  int       state;
  int       ispecial;
  int       ospecial;
  long      x_flags;
  int       x_precision;
  int       x_width;
  int       x_fill;
  int       isfx_special;
  int       osfx_special;
  int       delbuf;
  int       assign_private;

       ios();
  void init(streambuf* _buffer);
  void setstate(int);
  static void (*stdioflush)();

private:

  union ios_user_union {
    long x;
    void *p;
  };

  static long nextbit;
  static int usercount;
  union  ios_user_union *userwords;
  int    nwords;
  void   uresize(int);

         ios(ios&);                        // not implemented
  void   operator= (ios&);                 // not implemented
};

#ifdef _SMALL_INLINE
inline streambuf*  ios::rdbuf() { return _bp;}
inline ostream*    ios::tie()   { return x_tie;}
inline char        ios::fill()  { return x_fill; }
inline int         ios::precision()  { return x_precision; }
inline int         ios::rdstate()  { return state; }
inline int         ios::eof()   { return (state&eofbit); }
inline int         ios::fail()  { return (state&(failbit|badbit|hardfail)); }
inline int         ios::bad()   { return (state&(badbit|hardfail)); }
inline int         ios::good()  { return (state == 0); }
inline long        ios::flags() { return x_flags; }
inline int         ios::width() { return x_width; }
inline int         ios::width(int _w) { int _temp = x_width;
                                        x_width = _w;
                                        return _temp; }
inline char        ios::fill(char _w) { char _temp = x_fill;
                                        x_fill = _w;
                                        return _temp; }
inline int         ios::precision(int _w) { int _temp = x_precision;
                                        x_precision = _w;
                                        return _temp; }

inline             ios::operator void* () {return (fail()|eof()) ? 0 : this; }
inline             ios::operator! () {return (fail()|eof()); }
#endif


class streambuf {

public:

      streambuf();
      streambuf(char * _buf, int _size);
  virtual ~streambuf();

  virtual streambuf* setbuf(char * _buf, int _size);
  virtual streambuf* setbuf(char * _buf, int , int);

  int  sgetc();
  int  snextc();
  int  sbumpc();
  void stossc();
  int  sgetn(char *_s, int _num);
  virtual int  do_sgetn(char *_s, int _num);
  virtual int underflow();
  int  sputbackc(char _c);
  virtual int pbackfail(int);
  int  in_avail();

  int  sputc(int _c);
  virtual int  do_sputn(const char *_s, int _num);
  int  sputn(const char *_s, int _num);
  virtual int overflow(int _c = EOF);
  int  out_waiting();

  virtual streampos seekoff(streamoff, ios::seek_dir, int = (ios::in | ios::out));
  virtual streampos seekpos(streamoff, int = (ios::in | ios::out));
  virtual int sync();
  int dbp();

protected:

  char  *base();
  char  *ebuf();
  int    blen();
  char  *pbase();
  char  *pptr();
  char  *epptr();
  char  *eback();
  char  *gptr();
  char  *egptr();
  void  setp(char *, char *);
  void  setg(char *, char *, char *);
  void  pbump(int);
  void  gbump(int);
  void  setb(char *, char *, int = 0);
  void  unbuffered(int);
  int   unbuffered();
  int   allocate();
  virtual int   doallocate();

private:
  short _alloc;
  short _unbuf;
  char  *_base;
  char  *_ebuf;
  char  *_pbase;
  char  *_pptr;
  char  *_epptr;
  char  *_eback;
  char  *_gptr;
  char  *_egptr;

       streambuf(streambuf&);
  void  operator= (streambuf&);

  int   do_snextc();
};
#ifdef _SMALL_INLINE
inline char * streambuf::base()  { return _base; }
inline char * streambuf::pbase() { return _pbase; }
inline char * streambuf::pptr()  { return _pptr; }
inline char * streambuf::epptr() { return _epptr; }
inline char * streambuf::gptr()  { return _gptr; }
inline char * streambuf::egptr() { return _egptr; }
inline char * streambuf::eback() { return _eback; }
inline char * streambuf::ebuf()  { return _ebuf; }

inline int    streambuf::unbuffered() { return _unbuf; }
inline int    streambuf::blen() { return (int) (_ebuf - _base); }

inline void   streambuf::pbump(int _n) {  _pptr += _n; }
inline void   streambuf::gbump(int _n) {  _gptr += _n; }
inline void   streambuf::unbuffered(int _ub) { _unbuf = (_ub != 0); }
inline int    streambuf::in_avail() { return (_egptr > _gptr) ?
                                              (int)(_egptr - _gptr): 0; }
inline int    streambuf::out_waiting() { return _pptr ?
                                              (int)(_pptr - _pbase): 0; }
inline int    streambuf::allocate() { return((_base || _unbuf) ? 0 : doallocate()); }

inline int    streambuf::sgetc() { return ((_gptr >= _egptr) ? underflow() :
                                                            (unsigned char) *_gptr); }

inline int    streambuf::snextc() { return ((++_gptr >= _egptr) ?
                                                     do_snextc() :
                                                     (unsigned char) *_gptr); }

inline int    streambuf::sbumpc() { return ((_gptr >= _egptr)
                                        && (underflow() == EOF) ?
                                             EOF :
                                             (unsigned char) *_gptr++); }
inline void   streambuf::stossc() { if (_gptr >= _egptr)
                                      underflow();
                                    else
                                      ++_gptr; }

inline int    streambuf::sputbackc(char _c) { return (_gptr > _eback) ?
                                               *--_gptr = _c :
                                               pbackfail(_c) ; }

inline int    streambuf::sputc(int _c) { return (_pptr >= _epptr) ?
                                                overflow(_c) :
                                                (*_pptr++=_c, _c); }

#ifdef _BIG_INLINE
inline int    streambuf::sputn(const char *_s, int _n) {
                                         if(_n <= (_epptr - _pptr)) {
                                           memcpy(_pptr, _s, _n);
                                           pbump(_n);
                                           return _n;
                                         }
                                         return do_sputn(_s, _n); }

inline int    streambuf::sgetn(char *_s, int _n) {
                                         if(_n <= (_egptr - _gptr)) {
                                           memcpy(_s, _gptr, _n);
                                           gbump(_n);
                                           return _n;
                                         }
                                         return do_sgetn(_s, _n); }

#endif
#endif
class istream : virtual public ios {

public:

       istream(streambuf*);
       istream(streambuf*, int _sk, ostream* _t=NULL);
       istream(int _sz, char *, int _sk=1);
       istream(int _fd, int _sk=1, ostream* _t=NULL);
  virtual ~istream();

  int  ipfx(int = 0);
  int  ipfx0();
  int  ipfx1();
  void isfx() {}

  istream& seekg(streampos);
  istream& seekg(streamoff, ios::seek_dir);
  streampos tellg();

  int  sync();

  istream& get(  signed char*, int, char = '\n');
  istream& get(unsigned char*, int, char = '\n');
  istream& get(         char*, int, char = '\n');
  istream& read(  signed char*, int);
  istream& read(unsigned char*, int);
  istream& read(         char*, int);
  istream& getline(  signed char*, int, char = '\n');
  istream& getline(unsigned char*, int, char = '\n');
  istream& getline(         char*, int, char = '\n');

  istream& get(streambuf&, char = '\n');
  istream& get(  signed char&);
  istream& get(unsigned char&);
  istream& get(         char&);
  int      get();

  int      peek();
  int      gcount();
  istream& putback(char);
  istream& ignore(int = 1, int = EOF);

  istream& operator>> (istream& (*_f)(istream&));
  istream& operator>> (ios& (*_f)(ios&));
  istream& operator>> (  signed char*);
  istream& operator>> (unsigned char*);
  istream& operator>> (         char*);
  istream& operator>> (  signed char&);
  istream& operator>> (unsigned char&);
  istream& operator>> (         char&);
  istream& operator>> (short&);
  istream& operator>> (int&);
  istream& operator>> (long&);
  istream& operator>> (unsigned short&);
  istream& operator>> (unsigned int&);
  istream& operator>> (unsigned long&);
  istream& operator>> (float&);
  istream& operator>> (double&);
  istream& operator>> (long double&);

  istream& operator>> (streambuf*);

protected:

       istream();
  int  do_ipfx(int);
  void eatwhite();

private:

  int  _gcount;
  int  do_get();
};

#ifdef _SMALL_INLINE
inline int istream::gcount() { return _gcount; }

inline int istream::ipfx(int _need) { if( _need ? (ispecial&~skipping) :
                                                  ispecial)
                                        return do_ipfx(_need);
                                      return 1; }

inline int istream::ipfx0() { return ispecial ? do_ipfx(0) : 1; }

inline int istream::ipfx1() { return (ispecial&~skipping) ? do_ipfx(1) : 1; }

inline istream& istream::operator>>(unsigned char& _c) {
                            if(ipfx0()) {
                              if(_bp->in_avail())
                                _c = _bp->sbumpc();
                              else
                                _c = do_get();
                            }
                            return *this; }

inline istream& istream::operator>>(signed char& _c) {
                            if(ipfx0()) {
                              if(_bp->in_avail())
                                _c = _bp->sbumpc();
                              else
                                _c = do_get();
                            }
                            return *this; }

inline istream& istream::operator>>(       char& _c) {
                            if(ipfx0()) {
                              if(_bp->in_avail())
                                _c = _bp->sbumpc();
                              else
                                _c = do_get();
                            }
                            return *this; }

inline istream& istream::operator>>(unsigned char* _s) {
                            return *this>>(signed char *) _s; }

inline istream& istream::operator>>(         char* _s) {
                            return *this>>(signed char *) _s; }

inline istream& istream::get(unsigned char* _s, int _l, char _t) {
                            return get((signed char *)_s, _l, _t); }

inline istream& istream::get(         char* _s, int _l, char _t) {
                            return get((signed char *)_s, _l, _t); }

#ifdef _BIG_INLINE_
inline istream& istream::get(unsigned char& _c) {
                            if( ipfx1() ) {
                              if( _bp->in_avail() ) {
                                _gcount = 1;
                                _c = _bp->sbumpc();
                              }
                              else
                                _c = do_get();
                            }
                            return *this; }

inline istream& istream::get(signed char& _c) {
                            if( ipfx1() ) {
                              if( _bp->in_avail()) {
                                _gcount = 1;
                                _c = _bp->sbumpc();
                              }
                              else
                                _c = do_get();
                            }
                            return *this; }


inline istream& istream::get(     char& _c) {
                            if( ipfx1() ) {
                              if( _bp->in_avail()) {
                                _gcount = 1;
                                _c = _bp->sbumpc();
                              }
                              else
                                _c = do_get();
                            }
                            return *this; }

inline int 	istream::get() {
                            if( ipfx1() ) {
                              int _c = _bp->sbumpc();
                              if( _c == EOF )
                                setstate(eofbit);
                              else _gcount = 1;
                              return _c;
                            }
                            return EOF; }

#endif

inline istream& istream::read(unsigned char* _s, int _l) {
                            return read((signed char *)_s, _l); }

inline istream& istream::read(         char* _s, int _l) {
                            return read((signed char *)_s, _l); }

inline istream& istream::getline(unsigned char* _s, int _l, char _t) {
                            return getline((signed char *)_s, _l, _t); }

inline istream& istream::getline(         char* _s, int _l, char _t) {
                            return getline((signed char *)_s, _l, _t); }

inline int      istream::sync() { return _bp->sync(); }

inline istream& istream::operator>> (istream& (*_f)(istream&)) {
                            return (*_f)(*this); }

inline int istream::peek() { return ipfx1() ? _bp->sgetc() : EOF; }

#endif

class ostream : virtual public ios {

public:


      ostream(streambuf *);
      ~ostream();

      ostream(int _fd);
      ostream(int _sz, char *);

  int  opfx();
  void osfx();
  ostream& flush();

  ostream& seekp(streampos);
  ostream& seekp(streamoff, ios::seek_dir);
  streampos tellp();

  ostream& put(char);
  ostream& write(const          char*, int);
  ostream& write(const   signed char*, int);
  ostream& write(const unsigned char*, int);

  ostream& operator<<(  signed char);
  ostream& operator<<(unsigned char);
  ostream& operator<<(         char);
  ostream& operator<<(  signed short);
  ostream& operator<<(unsigned short);
  ostream& operator<<(  signed int);
  ostream& operator<<(unsigned int);
  ostream& operator<<(  signed long);
  ostream& operator<<(unsigned long);
  ostream& operator<<(float);
  ostream& operator<<(double);
  ostream& operator<<(long double);
  ostream& operator<<(const          char *);
  ostream& operator<<(const   signed char *);
  ostream& operator<<(const unsigned char *);
  ostream& operator<<(void *);

  ostream& operator<<(streambuf*);
  ostream& operator<<(ostream& (*_f)(ostream&));
  ostream& operator<<(ios& (*_f)(ios&));

protected:

       ostream();
  int  do_opfx();
  int do_osfx();

private:

  void  outlong(unsigned long, int);
  void  outstr(const char *);
};

#ifdef _SMALL_INLINE
inline int  ostream::opfx() { return ospecial ? do_opfx() : 1; }

inline void ostream::osfx() { if((x_flags&(stdio|unitbuf)) || (ospecial)) do_osfx(); }

inline ostream& ostream::operator<<(unsigned char _c) {
                             return *this <<(signed char ) _c; }

inline ostream& ostream::operator<<(         char _c) {
                             return *this <<(signed char ) _c; }

inline ostream& ostream::operator<<(short _i) { return *this<<(long)_i; }

inline ostream& ostream::operator<<(unsigned short _i) {
                             return *this<<(unsigned long)_i; }

inline ostream& ostream::operator<<(int _i) { return *this<<(long)_i; }

inline ostream& ostream::operator<<(unsigned int _i) {
                             return *this<<(unsigned long)_i; }

inline ostream& ostream::operator<<(float _f) {
                             return *this<<(long double)_f; }

inline ostream& ostream::operator<<(double _f) {
                             return *this<<(long double)_f; }

inline ostream& ostream::operator<<(ostream& (*_f)(ostream&)) {
                             return (*_f)(*this); }

inline ostream& ostream::write(const signed char *_s, int _n) {
                             return write((const char *)_s, _n); }

inline ostream& ostream::write(const unsigned char *_s, int _n) {
                             return write((const char *)_s, _n); }

inline ostream& ostream::put(char _c) {
                             if(_bp->sputc(_c) == EOF)
                               setstate(badbit);
                             return *this; }

inline ostream& ostream::operator<<(const signed char *_s) {
                             return *this<<(const char *) _s; }

inline ostream& ostream::operator<<(const unsigned char *_s) {
                             return *this<<(const char *) _s; }
#endif

class iostream : public istream , public ostream {

public:

      iostream(streambuf*);
  virtual ~iostream();

protected:
      iostream();

};


class istream_withassign : public istream {

public:

      istream_withassign();
  virtual  ~istream_withassign();

  istream_withassign&  operator= (istream&);
  istream_withassign&  operator= (streambuf*);

private:

  unsigned assign_const;
};

class ostream_withassign : public ostream {

public:

      ostream_withassign();
  virtual  ~ostream_withassign();

  ostream_withassign&  operator= (ostream&);
  ostream_withassign&  operator= (streambuf*);

private:

  unsigned assign_const;
};

class iostream_withassign : public iostream {

public:

      iostream_withassign();
  virtual  ~iostream_withassign();

  iostream_withassign&  operator= (ios&);
  iostream_withassign&  operator= (streambuf*);

private:

  unsigned assign_const;
};

extern istream_withassign cin;
extern ostream_withassign cout;
extern ostream_withassign cerr;
extern ostream_withassign clog;

ostream&  endl(ostream&);
ostream&  ends(ostream&);
ostream&  flush(ostream&);
istream&  ws(istream&);
ios&      dec(ios&);
ios&      hex(ios&);
ios&      oct(ios&);
#endif

