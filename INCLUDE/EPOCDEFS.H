/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  string.h -  Definitions for string and memory functions.                *
*                                                                          *
*  COPYRIGHT (C) 1991 Psion PLC. All Rights Reserved.                      *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef EPOCDEFS_H
#define EPOCDEFS_H

#ifndef _TIME_DEF
#define _TIME_DEF
typedef long time_t;
#endif

typedef int INT,HANDLE;
typedef unsigned int UINT;
typedef signed char BYTE;
typedef unsigned char UBYTE;
typedef short int WORD;
typedef unsigned short int UWORD;
typedef long int LONG;
typedef unsigned long int ULONG;
typedef double DOUBLE;
typedef float FLOAT;
typedef char TEXT;

typedef struct _mblock
    {
    unsigned int mlen;
    struct _mblock *mnext;
    } _MBLOCK;

#define P_FOPEN 0x0000
#define P_FCREATE 0x0001
#define P_FREPLACE 0x0002
#define P_FAPPEND 0x0003
#define P_FUNIQUE 0x0004
#define P_FSER_MASK 0x000f
#define P_FSTREAM 0x0000
#define P_FSTREAM_TEXT 0x0010
#define P_FTEXT 0x0020
#define P_FDIR 0x0030
#define P_FFORMAT 0x0040
#define P_FDEVICE 0x0050
#define P_FNODE 0x0060
#define P_FMT_MASK 0x00f0
#define P_FUPDATE 0x0100
#define P_FRANDOM 0x0200
#define P_FSHARE 0x0400
#define P_FACC_MASK 0x0f00
#define P_FLOWDENSITY   0x1000

#define P_FPANIC 0
#define P_FREAD 1
#define P_FWRITE 2
#define P_FCLOSE 3
#define P_FCANCEL 4
#define P_FATTACH 5
#define P_FDETACH 6
#define P_FSET 7
#define P_FSENSE 8
#define P_FFLUSH 9
#define P_FRELATIVE P_FREAD
#define P_FABSOLUTE P_FWRITE
#define P_FSEEK 10
#define P_FSETEOF 11
#define P_FWRITE_REPLY 12
#define P_FTEST 10
#define P_FCTRL 11
#define P_FINQ 12
#define P_FRSUPER 13
#define P_FSTOP 14
#define P_FSTART 15
#define P_FENABLE 16
#define P_FSETINT 17
#define P_FABS 1
#define P_FEND 2
#define P_FCUR 3
#define P_FRSENSE 4
#define P_FRSET 5
#define P_FREWIND 6

#define NoErr 0
#define FailErr (-1)
#define ArgumentErr (-2)
#define OsErr (-3)
#define NotSupportedErr (-4)
#define UnderflowErr (-5)
#define OverflowErr (-6)
#define RangeErr (-7)
#define DivideByZeroErr (-8)
#define InUseErr (-9)
#define NoMemoryErr (-10)
#define NoSegmentsErr (-11)
#define NoSemaphoreErr (-12)
#define NoProcessErr (-13)
#define AlreadyOpenErr (-14)
#define NotOpenErr (-15)
#define ImageErr (-16)
#define NoReceiverErr (-17)
#define NoDevicesErr (-18)
#define NoFileSystemErr (-19)
#define FailedToStartErr (-20)
#define ExistsErr (-32)
#define NotExistsErr (-33)
#define WriteErr (-34)
#define ReadErr (-35)
#define EofErr (-36)
#define FullErr (-37)
#define NameErr (-38)
#define AccessErr (-39)
#define LockedErr (-40)
#define DeviceErr (-41)
#define DirErr (-42)
#define RecordErr (-43)
#define ReadOnlyErr (-44)
#define IoInvalidErr (-45)
#define PendingErr (-46)
#define VolumeErr (-47)
#define CancelErr (-48)
#define IoAllocErr (-10)
#define DisconnectErr (-50)
#define ConnectErr (-51)
#define ReTransmitErr (-52)
#define LineErr (-53)
#define InActivityErr (-54)
#define ParityErr (-55)
#define FrameErr (-56)
#define OverrunErr (-57)
#define ModemConnectErr (-58)
#define ModemBusyErr (-59)
#define ModemNoAnswerErr (-60)
#define ModemBlacklistErr (-61)
#define NotReadyErr (-62)
#define UnknownErr (-63)
#define DirFullErr (-64)
#define WriteProtectErr (-65)
#define CorruptMediaErr (-66)
#define AbortErr (-67)
#define EraseErr (-68)
#define InvalidFileErr (-69)

#define P_CD_ROOT 0
#define P_CD_PARENT 1
#define P_CD_SUBDIR 2

#define P_FAWRITE 0x01
#define P_FAHIDDEN 0x02
#define P_FASYSTEM 0x04
#define P_FAVOLUME 0x08
#define P_FADIR 0x10
#define P_FAMOD 0x20
#define P_FAREAD 0x100
#define P_FAEXEC 0x200
#define P_FASTREAM 0x400
#define P_FATEXT 0x800

typedef struct
    {
    UWORD version;
    UWORD status;
    ULONG size;
    ULONG modst;
    UBYTE spare[4];
    } P_INFO;

#define P_VOLUMENAME    32
#define P_FMEDIA_UNKNOWN 0
#define P_FMEDIA_FLOPPY 1
#define P_FMEDIA_HARDDISK 2
#define P_FMEDIA_FLASH 3
#define P_FMEDIA_RAM 4
#define P_FMEDIA_ROM 5
#define P_FMEDIA_WRITEPROTECTED 6
#define P_FMEDIA_COMPRESSIBLE 0x8000
#define P_FMEDIA_DYNAMIC 0x4000
#define P_FMEDIA_INTERNAL 0x2000
#define P_FMEDIA_DUAL_DENSITY 0x1000
#define P_FMEDIA_FORMATTABLE 0x800

typedef struct {
    UWORD version;
    UWORD mediatype;
    UWORD removable;
    ULONG size;
    ULONG free;
    UBYTE name[P_VOLUMENAME];
    WORD batterystate;
    UBYTE spare[16];
    } P_DINFO;

#define P_FSYSTYPE_FLAT 0
#define P_FSYSTYPE_HIER 1
typedef struct {
    UWORD version;
    UWORD type;
    UWORD formattable;
    UBYTE spare[26];
    } P_NINFO;

#define P_PWILD_ANY 0x01
#define P_PWILD_NAME 0x02
#define P_PWILD_EXT 0x04
#define P_FSYSNAMESIZE 5

typedef struct {
    UBYTE system;
    UBYTE device;
    UBYTE path;
    UBYTE name;
    UBYTE ext;
    UBYTE flags;
    } P_FPARSE;

#define P_FBLKSHIFT 9
#define P_FBLKSIZE 0x200
#define P_FMAXRSIZE 0x100
#define P_FMAXSSIZE 0x4000
#define P_FSIZRPOS sizeof(LONG)
#define P_MAXDEV 128
#define P_MAXPATH 128
#define P_MAXNAME 128
#define P_MAXEXTN 128
#define P_FNAMESIZE 128

typedef struct
    {
    ULONG day;
    ULONG sec;
    } P_DAYSEC;

typedef struct
    {
    UBYTE year;
    UBYTE month;
    UBYTE day;
    UBYTE hour;
    UBYTE minute;
    UBYTE second;
    UWORD yrday;
    } P_DATE;

#define P_SCR_ATTRB 0
#define P_SCR_SCROLL 1
#define P_SCR_CLR 2
#define P_SCR_POSA 3
#define P_SCR_POSR 4
#define P_SCR_WSET 5
#define P_SCR_SLOCK 6
#define P_SCR_WLOCK 7
#define P_SCR_NEL 8
#define P_SCR_CURSOR 9
#define P_SCR_ESCAPE 10

typedef struct
    {
    short int x; /* Horizontal coordinate */ 
    short int y; /* Vertical coordinate */ 
    } P_POINT;
typedef struct
    {
    P_POINT tl; /* Top left point */ 
    P_POINT br; /* Bottom right point */ 
    } P_RECT;
typedef struct
    {
    P_RECT r; /* Rectangle */ 
    P_POINT p; /* Point */ 
    } P_RECTP;
typedef struct
    {
    P_POINT tl; /* Top left point */ 
    unsigned short int width; /* Width */ 
    unsigned short int height; /* Height */ 
    } P_EXTENT;

#define _E_SEARCH 0x10
#define _E_EXEC 0x20

extern char _pname[P_FNAMESIZE];
extern P_FPARSE _pinfo;
extern void *winHandle;

#ifdef __cplusplus
extern "C" {
#endif
extern int _allocInfo(_MBLOCK **,_MBLOCK **);
extern _MBLOCK *_heapTop(void);
extern int _iopen(char **_handle,char *_name,int _mode);
extern int _iow2(char *handle,int _func);
extern int _iow3(char *handle,int _func,void *);
extern int _iow4(char *handle,int _func,void *,void *);
extern int _parse(const char *_in,char *_rel,char *_out,P_FPARSE *_info);
extern void _convTimeToDos(ULONG t,int *date,int *time);
extern void _FsChanToName(void *handle,char *name);
extern int _FsChanToMode(void *handle);
extern int _isloc(const char *path);
extern void _systemTimeToDaySeconds(time_t secs,P_DAYSEC *pDs);
extern time_t _daySecondsToSystemTime(P_DAYSEC *pDs);
extern void _daySecondsToDate(P_DAYSEC *pDs,P_DATE *pDate);
extern int _dateToDaySeconds(P_DATE *pDate,P_DAYSEC *pDs);
extern int _fileInfo(const char *path,P_INFO *pI);
extern int _fileSetModTime(const char *path,time_t time);
extern void _getPath(char *path);
extern void _setPath(char *path);
extern time_t _date(void);
extern void _sleepTenths(unsigned long tenths);
extern int _execc(const char *path,char **argv,int mode);
extern int __execc(char *path,char *command);
extern int _logon(int handle,WORD *stat);
extern void _waitStat(WORD *stat);
extern int _resume(int pid);
extern char *_getErrorText(int error,char *buffer);
#pragma save,call(inline=>on)
static void _dummy(void) = {0xCD,0xD4};
#pragma restore
#ifdef __cplusplus
}
#endif
#endif

