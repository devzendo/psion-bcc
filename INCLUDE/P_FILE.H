/*	HEADER - P_FILE.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_FILE_H
#include <stdepoc.h>
#define P_MAXDEVNAME 4
typedef void (*P_DEVICE)(void);
typedef struct /* IO request packet */
{
short int *pstat;    /* where to write completion status */ 
unsigned char *a1;     /* first parameter */ 
unsigned char *a2;     /* second parameter */   
} P_RQPKT;
/* all I/O control blocks must start with this header */
typedef struct p_icb  /* I/O control block header */ 
{
struct p_icb *picb; /* ptr to current ICB in chain */ 
int (*vec)();    /* strategy entry point */ 
} P_ICB;
/* IO request - as passed to strategy functions */
typedef struct 
{
unsigned int func;     /* function number */ 
P_RQPKT r;     /* request packet */ 
} P_IRQ;
/* Wait Handler defines */
#define P_SIGNAL_UNUSED 0  /* signal not used by waithandler */ 
#define P_SIGNAL_ENABLE 1 /* signal used by handler,I/O's still pending */ 
#define P_SIGNAL_DISABLE 2 /* signal used by handler,no I/O's pending */ 
/* open service mode flags */
#define P_FOPEN 0x0000 /* Open i/o service */ 
#define P_FCREATE 0x0001 /* Create file */ 
#define P_FREPLACE 0x0002 /* Replace file */ 
#define P_FAPPEND 0x0003 /* Append records */ 
#define P_FUNIQUE 0x0004 /* Unique file open */ 
#define P_FSER_MASK 0x000f /* File service mask */ 
#define P_FSTREAM 0x0000 /* Stream access to a binary file */ 
#define P_FSTREAM_TEXT 0x0010 /* Stream access to a text file */ 
#define P_FTEXT 0x0020 /* Record access to a text file */ 
#define P_FDIR 0x0030 /* Record access to a directory file */ 
#define P_FFORMAT 0x0040 /* Format a device */
#define P_FDEVICE 0x0050 /* Record access to device name list */ 
#define P_FNODE 0x0060 /* Record access to node name list */ 
#define P_FMT_MASK 0x00f0 /* File format mask */ 
#define P_FUPDATE 0x0100 /* Read and write access */ 
#define P_FRANDOM 0x0200 /* Random access */ 
#define P_FSHARE 0x0400 /* File can be shared */ 
#define P_FACC_MASK 0x0f00 /* mask for access types */ 
#define P_FLOWDENSITY  0x1000
/* p_io/p_iow function constants */
/* Generic I/O functions */
#define P_FPANIC 0 /* Panic the device */ 
#define P_FREAD 1 /* Read */ 
#define P_FWRITE 2 /* Write */ 
#define P_FCLOSE 3 /* Close */ 
#define P_FCANCEL 4 /* Cancel io */ 
#define P_FATTACH 5 /* attach this pseudo device */ 
#define P_FDETACH 6 /* detach this pseudo device */ 
#define P_FSET 7 /* set channel characteristics */ 
#define P_FSENSE 8 /* sense channel characteristics */ 
#define P_FFLUSH 9 /* Flush buffers */ 
/* Now follows the device specific functions */
/* Timer device driver */
#define P_FRELATIVE P_FREAD /* Relative timer */ 
#define P_FABSOLUTE P_FWRITE /* Absolute timer */ 
/* Files */
#define P_FSEEK 10 /* Seek */ 
#define P_FSETEOF 11 /* Set end of file */ 
/* Data Link I/O + wserv */
#define P_FCONNECT 10 /* Queue a link connect request */ 
#define P_FDISCONNECT 11 /* Disconnect the link */ 
/* wserv functions */
#define P_FWRITE_REPLY 12 /* P_FWRITE + read a reply from the server */ 
/* Serial/llmac */
#define P_FTEST 10 /* return no. of bytes in serial receieve buffer */ 
#define P_FCTRL 11 /* serial port control lines */ 
#define P_FINQ 12 /* inquire of device capabilities */ 
#define P_FRSUPER 13 /* read a supervisory frame (p_llmac) */ 
#define P_FSTOP 14 /* stop LLMAC mode */ 
#define P_FSTART 15 /* start LLMAC mode */ 
/* Serial LDD to Serial PDD I/O defines */
#define P_FENABLE 16 /* Enable transmit interrupts */ 
#define P_FSETINT 17 /* set the serial Interrupt code ptrs */
/* modem functions */
#define P_FMINIT 16 /* modem initialization function */ 
#define P_FMDIAL 17 /* modem dial function */ 
#define P_FMWAITCALL 18 /* wait for an incoming call */ 
#define P_FMSENSE 19 /* Sense Modem characteristics */ 
#define P_FMSET 20 /* Set Modem characteristics */ 
#define P_FMCANCEL 21 /* Cancel outstanding mode request */ 
#define P_FMWRITE 22 /* Write a configuration string to modem with timeout */ 
/* p_seek() mode constants */
#define P_FABS 1 /* Position absolute in the file */ 
#define P_FEND 2 /* Position relative from the end of file */ 
#define P_FCUR 3 /* Position relative to the current pos */ 
#define P_FRSENSE 4 /* Sense the record position */ 
#define P_FRSET 5 /* Set the record position */ 
#define P_FREWIND 6 /* Rewind a text file */ 

/* IRDA Defines */
#define P_FIRDISCONNECT   4 /* Disconnect from remote machine */
#define P_FIRAWAITCONNECT 5 /* Wait for a connection from a remote machine */
#define P_FIRDISCOVER     6 /* Discover remote machines */
#define P_FIRSELECT       7 /* Select a remote machine */
#define P_FIRMAKECONNECT  8 /* Make a connection to a remote machine */

/* file errors */
#define ExistsErr    (-32)
#define NotExistsErr  (-33)
#define WriteErr    (-34)
#define ReadErr     (-35)
#define EofErr     (-36)
#define FullErr     (-37)
#define NameErr     (-38)
#define AccessErr    (-39)
#define LockedErr    (-40)
#define DeviceErr    (-41)
#define DirErr     (-42)
#define RecordErr    (-43)
#define ReadOnlyErr   (-44)
#define IoInvalidErr  (-45)
#define PendingErr   (-46)
#define VolumeErr    (-47)
#define CancelErr    (-48)
#define IoAllocErr   (-10)    /* E_GEN_NOMEMORY */ 
#define DisconnectErr  (-50)
#define ConnectErr   (-51)
#define ReTransmitErr  (-52)
#define LineErr     (-53)
#define InActivityErr  (-54)
#define ParityErr    (-55)
#define FrameErr    (-56)
#define OverrunErr   (-57)
#define ModemConnectErr (-58)
#define ModemBusyErr  (-59)
#define ModemNoAnswerErr (-60)
#define ModemBlacklistErr (-61)
#define NotReadyErr   (-62)
#define UnknownErr   (-63)
#define DirFullErr   (-64)
#define WriteProtectErr (-65)
#define CorruptMediaErr (-66)
#define AbortErr    (-67)
#define EraseErr    (-68)
#define InvalidFileErr (-69)
#define E_FILE_EXIST ExistsErr     /* File already exists */ 
#define E_FILE_NXIST NotExistsErr    /* File does not exist */ 
#define E_FILE_WRITE WriteErr      /* Write to file failed */ 
#define E_FILE_READ ReadErr       /* Read from file failed */ 
#define E_FILE_EOF EofErr        /* Read past end of file */ 
#define E_FILE_FULL FullErr       /* Disk/serial read buffer full */ 
#define E_FILE_NAME NameErr       /* Invalid file name */ 
#define E_FILE_ACCESS AccessErr     /* Access denied */ 
#define E_FILE_LOCKED LockedErr     /* Record or file locked */ 
#define E_FILE_DEVICE DeviceErr     /* Device does not exist */ 
#define E_FILE_DIR DirErr        /* Directory does not exist */ 
#define E_FILE_RECORD RecordErr     /* Record too large */ 
#define E_FILE_RDONLY ReadOnlyErr    /* File has read only access */ 
#define E_FILE_INV IoInvalidErr     /* Invalid I/O operation */ 
#define E_FILE_PENDING PendingErr    /* I/O pending (not yet completed) */ 
#define E_FILE_VOLUME VolumeErr     /* Invalid volume */ 
#define E_FILE_CANCEL CancelErr     /* Async operation was cancelled */ 
#define E_FILE_ALLOC IoAllocErr     /* No memory for control block */ 
#define E_FILE_DISC DisconnectErr    /* link is disconnected */ 
#define E_FILE_CONNECT ConnectErr    /* link already connected */ 
#define E_FILE_RETRAN ReTransmitErr   /* Retransmission threshold exceeded */ 
#define E_FILE_LINE LineErr       /* Physical link failure */ 
#define E_FILE_INACT InActivityErr   /* Inactivity timer expired */ 
#define E_FILE_PARITY ParityErr     /* Serial parity error */ 
#define E_FILE_FRAME FrameErr      /* Serial framing error */ 
#define E_FILE_OVERRUN OverrunErr    /* Serial overrun error */ 
#define E_MDM_CONFAIL ModemConnectErr  /* modem can't connect to remote modem */ 
#define E_MDM_BUSY ModemBusyErr     /* remote number busy */ 
#define E_MDM_NOANS ModemNoAnswerErr  /* there was no answer */ 
#define E_MDM_BLACKLIST ModemBlacklistErr /* number blacklisted by the modem*/ 
#define E_FILE_NOTREADY NotReadyErr   /* Drive not ready error */ 
#define E_FILE_UNKNOWN UnknownErr    /* Unknown media in drive */ 
#define E_FILE_DIRFULL DirFullErr    /* Root dir full error */ 
#define E_FILE_PROTECT WriteProtectErr /* Device write protect */ 
#define E_FILE_CORRUPT CorruptMediaErr /* Media is corrupt */ 
#define E_FILE_ABORT AbortErr /* User aborted operation error */ 
#define E_FILE_ERASE EraseErr /* Failed to Erase Flash pack */ 
#define E_FILE_INVALID InvalidFileErr /* Invalid file for DBF system */ 
/* defines for changing directories */
#define P_CD_ROOT 0   /* goto root directory */ 
#define P_CD_PARENT 1  /* goto parent directory */ 
#define P_CD_SUBDIR 2  /* goto subdirectory */ 
/* masks for status flag of P_INFO */
#define P_FAWRITE 0x01 /* can the file be written to? */ 
#define P_FAHIDDEN 0x02 /* set if file is hidden */ 
#define P_FASYSTEM 0x04 /* set if file is a system file */ 
#define P_FAVOLUME 0x08 /* set if the name is a volume name */ 
#define P_FADIR  0x10 /* set if file is a directory file */ 
#define P_FAMOD  0x20 /* has the file been modified? */ 
#define P_FAREAD  0x100 /* can the file be read? */ 
#define P_FAEXEC  0x200 /* is the file executable? */ 
#define P_FASTREAM 0x400 /* is the file a byte stream file? */ 
#define P_FATEXT  0x800 /* is it a text file? */ 
/* File system File information - p_finfo() */
typedef struct {
unsigned short int version; /* for future expansion */ 
unsigned short int status; /* status bits */ 
unsigned long int size; /* size of the file */ 
unsigned long int modst; /* system time of last modification */ 
unsigned char spare[4]; /* spare bytes for future expansion */ 
} P_INFO;
#define P_VOLUMENAME  32
#define P_FMEDIA_UNKNOWN 0
#define P_FMEDIA_FLOPPY 1
#define P_FMEDIA_HARDDISK 2
#define P_FMEDIA_FLASH 3
#define P_FMEDIA_RAM 4
#define P_FMEDIA_ROM 5
#define P_FMEDIA_WRITEPROTECTED 6
#define P_FMEDIA_COMPRESSIBLE 0x8000 /* Worth compressing deleted records */ 
#define P_FMEDIA_DYNAMIC 0x4000 /* Media size is dynamic */ 
#define P_FMEDIA_INTERNAL 0x2000 /* Media is internal */ 
#define P_FMEDIA_DUAL_DENSITY 0x1000
#define P_FMEDIA_FORMATTABLE 0x800
/* File System Device information - p_dinfo() */
typedef struct {
unsigned short int version; /* for future expansion */ 
unsigned short int mediatype; /* what type of device is this */ 
unsigned short int removable; /* is device removable or not */ 
unsigned long int size; /* size of the device */ 
unsigned long int free; /* amount of device still free */ 
char name[P_VOLUMENAME]; /* the volume name of the device */ 
short int batterystate; /* Device battery status */ 
unsigned char spare[16]; /* spare bytes for future expansion */ 
} P_DINFO;
#define P_FSYSTYPE_FLAT 0
#define P_FSYSTYPE_HIER 1
/* File System Node information - p_ninfo() */
typedef struct {
unsigned short int version; /* for future expansion */ 
unsigned short int type; /* file system type (flat/hierarchical...) */ 
unsigned short int formattable; /* TRUE if node supports format cmds else FALSE */ 
unsigned char spare[26]; /* spare bytes for future expansion */ 
} P_NINFO;
/* Flag defines for p_fparse */
#define P_PWILD_ANY 0x01 /* contains one or more wildcards */ 
#define P_PWILD_NAME 0x02 /* the name field contains wildcards */ 
#define P_PWILD_EXT 0x04 /* the extension contains wildcards */ 
/* Full file system parse - p_fparse() */
#define P_FSYSNAMESIZE 5
typedef struct {
unsigned char system; /* file system name length */ 
unsigned char device; /* device name length */ 
unsigned char path; /* path name length */ 
unsigned char name; /* name length */ 
unsigned char ext; /* extension length */ 
unsigned char flags; /* information on the presence of wildcards */ 
} P_FPARSE;
#define P_FBLKSHIFT 9 /* Block shift factor */ 
#define P_FBLKSIZE 0x200 /* Block size */ 
#define P_FMAXRSIZE 0x100 /* Maximum text record size */ 
#define P_FMAXSSIZE 0x4000 /* Maximum stream read/write length */ 
#define P_FSIZRPOS sizeof(long int) /* array size for storing r/w position */ 
#define P_MAXDEV 128 /* Maximum device name size */ 
#define P_MAXPATH 128 /* Maximum path size */ 
#define P_MAXNAME 128 /* Maximum name size */ 
#define P_MAXEXTN 128 /* Maximum extension size */ 
#define P_FNAMESIZE 128 /* Maximum file name size */ 
/* BINARY FILE SIGNATURE FOR APPLICATION FILES */
typedef struct
{
char app_id[3]; /* application id */ 
unsigned char chk_sum; /* application id checksum */ 
unsigned char file_vn; /* file version number */ 
unsigned char app_vn; /* application version number */ 
} P_FSIG;
#ifdef __cplusplus
extern "C" {
#endif
extern void cdecl p_inst(P_DEVICE *,...);
#pragma save,call(reg_param =>(bx,cx,di,si,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_fparse(const char *,const char *,char *,P_FPARSE *);
extern int f_fparse(const char *,const char *,char *,P_FPARSE *);
extern int p_fparseasync(const char *,const char *,char *,P_FPARSE *,short int *);
extern int p_finfo(const char *,P_INFO *);
extern int p_finfoasync(const char *,P_INFO *,short int *);
extern int p_ninfo(const char *,P_NINFO *);
extern int p_ninfoasync(const char *,P_NINFO *,short int *);
extern int p_dinfo(const char *,P_DINFO *);
extern int p_dinfoasync(const char *,P_DINFO *,short int *);
#pragma restore
#ifdef __cplusplus
}
#endif

