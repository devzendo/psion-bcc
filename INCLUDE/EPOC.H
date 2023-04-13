/*	HEADER - EPOC.H
Copyright (C) Psion PLC 1991
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
*/
#define EPOC_H
#include <stdepoc.h>
#define E_PRIORITY_TIME_SUPERVISOR 0xf8
#define E_PRIORITY_TIME_FSERV 0xf0
#define E_PRIORITY_TIME_CRITICAL 0xb0
#define E_PRIORITY_WSERV_MOUSE 0xa8
#define E_PRIORITY_WSERV 0xa0
#define E_PRIORITY_NOTIFY 0x90
#define E_PRIORITY_FORE 0x80
#define E_PRIORITY_BACK 0x70
#define E_LCD_UNKNOWN (-1)
#define E_LCD_640_400 0
#define E_LCD_640_200_SMALL 1
#define E_LCD_640_200_BIG 2
#define E_LCD_720_348 3
#define E_LCD_160_80 4
#define E_LCD_240_80 5
#define E_PC_HERC E_LCD_720_348
#define E_PC_CGA E_LCD_640_200_BIG
#define E_PC_MDA 6
#define E_PC_EGA_MONO 7
#define E_PC_EGA_COLOUR 8
#define E_PC_VGA_MONO 9
#define E_PC_VGA_COLOUR 10
#define E_LCD_480_160 11
#define E_LCD_240_100 12
#define E_LCD_240_120 13
#define E_LCD_240_160 14
#define E_LCD_640_200 15
#define E_PSU_OLD 0
#define E_PSU_MAXIM 1
#define E_PSU_S3 2
#define E_PSU_S3_A9 3
#define E_IS_A_COLD_START 0
#define E_IS_A_POWERFAIL_START 1
#define E_IS_A_RESET_START 2
#define E_IS_A_KERNEL_FAULT 3
#define E_IS_A_NEW_OS_START 4
#define E_MAX_PROCESSES 24
#define E_MAX_PRIORITY 0xc0
#define E_MIN_PRIORITY 0x40
#define E_MAX_NAME 12
#define E_PIDMASK 0xfff
#define E_MAX_ERROR_TEXT_SIZE 64
#define E_MAX_NOTIFY_TEXT_SIZE 64
#define E_MAX_OPTION_TEXT_SIZE 16
#define E_MAX_ENV_SIZE 16
#define E_MAX_SUFFIXES 31
#define E_MAX_MONTH_NAME 32
#define E_MAX_DAY_NAME 32
#define E_MAX_COMMAND_BUFFER 127
#define E_MAX_GROWBY 0x400
#define E_MAX_PASSWORD 8
#define E_GROWBY_DEFAULT 0x80
#define E_SEGMENT_LOW 0
#define E_SEGMENT_HIGH 1
#define E_SEGMENT_DEVICE 2
#define E_LDD 0xdd01
#define E_PDD 0xdd21
#define E_NORMAL_EXIT 0
#define E_PANIC_EXIT 1
#define E_TASK_PANIC_EXIT 2
#define E_FILE_SYSTEM_NAMESIZE 5
#define E_SOUND_KEYBOARD 0x0001
#define E_SOUND_BUZZER 0x0002
#define E_SOUND_DEVICE 0x0004
#define E_SOUND_LOUD 0x0008
#define E_SOUND_LOUD_BUZZER 0x0010
#define E_SOUND_DISABLE 0x8000
#define	E_SOUND_MAX_VOLUME 0
#define	E_SOUND_MIN_VOLUME 5
#define E_SOUND_MAX_BPM 240
#define E_SOUND_MIN_BPM 2
#define E_MAX_ALARMS 2
#define E_MAX_DTMF_DIAL 24
#define E_MAX_DTMF_DIAL_B 40
#define E_BATTERY_UNKNOWN 0
#define E_BATTERY_ALKALINE 1
#define E_BATTERY_NICAD_600 2
#define E_BATTERY_NICAD_1000 3
#define E_BATTERY_NICAD_500 4
#define E_BATTERY_NICAD_850 5
#define E_TICKS_PER_SECOND 32
#define E_OPL_TEXT_MESSAGE 24
#define E_BACKLIGHT_DISABLE 0x8000
#define E_BACKLIGHT_OFF 0
#define E_BACKLIGHT_ON 1
#define E_BACKLIGHT_TOGGLE 2
#define E_BACKLIGHT_QUERY 3
#define E_FMEDIA_BATTERY_VALID 0x0400
#define E_FMEDIA_BATTERY_GOOD 0x0200
#define E_FRC_COUNTING 0
#define E_FRC_REPEATING 1
#define E_FSSOUNDCHANNEL1 1
#define E_FSSOUNDCHANNEL2 2
#define E_FRELATIVE 1
#define E_FABSOLUTE 2
#define E_FALARM 9
#define E_FDIAL 10
#define E_FSOUND_PLAY 0x10
#define E_FSOUND_RECORD 0x11

#define E_KEY_DELETE_LEFT 0x0008
#define E_KEY_TAB 0x0009
#define E_KEY_RETURN 0x000d
#define E_KEY_ESCAPE 0x001b
#define E_KEY_DELETE_RIGHT 0x007f
#define E_KEY_UP 0x0100
#define E_KEY_DOWN 0x0101
#define E_KEY_RIGHT 0x0102
#define E_KEY_LEFT 0x0103
#define E_KEY_PAGE_UP 0x0104
#define E_KEY_PAGE_DOWN 0x0105
#define E_KEY_HOME 0x0106
#define E_KEY_END 0x0107
#define E_KEY_INSERT 0x0108
#define E_KEY_VOICE 0x0109
#define E_KEY_PSION_DOWN 0x010a
#define E_KEY_PSION_UP 0x010b
#define E_KEY_CAPS 0x10c
#define E_KEY_PSION 0x200
#define E_KEY_BACKLIGHT 0x120
#define E_KEY_INFO 0x121
#define E_KEY_MENU 0x122
#define E_KEY_HELP 0x123
#define E_KEY_DIAMOND 0x124

#define E_KEY_APP1 0x131
#define E_KEY_APP2 0x132
#define E_KEY_APP3 0x133
#define E_KEY_APP4 0x134
#define E_KEY_APP5 0x135
#define E_KEY_APP6 0x136
#define E_KEY_APP7 0x137
#define E_KEY_APP8 0x138

#define E_KEY_LCD 0x2000
#define E_KEY_LCD_MINUS 0x2001
#define E_KEY_ON 0x2002
#define E_KEY_OFF 0x2003

#define E_STATE_KEY_VALID 0x0001
#define E_STATE_SHIFT 0x0002
#define E_STATE_CONTROL 0x0004
#define E_STATE_PSION 0x0008
#define E_STATE_CAPS_LOCKED 0x0010
#define E_STATE_NUM_LOCKED 0x0020
#define E_STATE_MOUSE_VALID 0x0040
#define E_STATE_MOUSE_DOWN 0x0080
#define E_STATE_MOUSE_MOVED 0x0100
#define E_STATE_MOUSE_CHANGED 0x0200
#define E_STATE_MOUSE_GONE 0x0400
#define E_STATE_KEY_REPEATED 0x0800
#define E_STATE_FN 0x0080

/* Additional I/O functions */
#define P_FTIMER_RELATIVE 1
#define P_FTIMER_ABSOLUTE 2
#define P_FSOUND_CHANNEL1 1
#define P_FSOUND_CHANNEL2 2
#define P_FSOUND_PLAY P_FTEST
#define P_FSOUND_RECORD P_FCTRL

typedef struct
    {
    unsigned char beatsPerMinute;
    unsigned char volume;
    } E_SOUND;

typedef struct
    {
    unsigned short int code;
    unsigned short int state;
    unsigned short int tick;
    unsigned short int mouseX;
    unsigned short int mouseY;
    } E_KEYS;

typedef struct
    {
    unsigned char toneLengthTicks;
    unsigned char delayLengthTicks;
    unsigned short int pauseLengthTicks;
    } E_DIAL;

typedef struct message
    {
    struct message *next;
    unsigned char *status;
    unsigned int type;
    int pid;
    } E_MESSAGE;

typedef struct
    {
    unsigned short int codeParagraphs;
    unsigned short int initialIp;
    unsigned short int stackParagraphs;
    unsigned short int dataParagraphs;
    unsigned short int heapParagraphs;
    unsigned char *commandLine;
    unsigned short int checkSum;
    unsigned short int minHeap;
    unsigned char priority;
    unsigned char ramOrRom;
    unsigned char name[E_MAX_NAME];
    } E_CPB;

#define E_PROC_FREE 0xff
#define E_PROC_CURRENT 0x01
#define E_PROC_READY 0x02
#define E_PROC_DELTA 0x03
#define E_PROC_SUSPENDED 0x04
#define E_PROC_SEMAPHORE 0x05
typedef struct e_proc
    {
    struct e_proc *next;
    struct e_proc *prev;
    short int queKey;
    short int queData;
    unsigned char deltaType;
    unsigned char addressTrap;
    unsigned char status;
    unsigned char sstatus;
    unsigned char priority;
    unsigned char priorityH;
    unsigned char ramOrRom;
    unsigned char isTask;
    unsigned char name[E_MAX_NAME+1];
    unsigned char active;
    unsigned short int semaphore;
    unsigned char *semHead;
    unsigned char *memBasePtr;
    unsigned short int memGrowBy;
    unsigned char *mCtrlPtr;
    unsigned short int minHeap;
    int fServer;
    int dataSeg;
    int codeSeg;
    unsigned char *saveSP;
    unsigned char *saveBP;
    unsigned char notify;
    unsigned char sndSem;
    unsigned short int magic;
    unsigned short int checkSum;
    unsigned short int terminate;
    unsigned short int bankState;
    } E_PROC;
typedef struct
    {
    unsigned short int mainBatteryReading;
    unsigned short int lithiumBatteryReading;
    short int mainsPresent;
    } E_SUPPLY;
typedef struct
    {
    unsigned short int mainBatteryWarning;
    unsigned short int lithiumBatteryWarning;
    unsigned short int mainBatteryMax;
    unsigned short int lithiumBatteryMax;
    } E_SUPPLY_WARNINGS;
#define E_MBAT_ZERO 0
#define E_MBAT_VERY_LOW 1
#define E_MBAT_LOW 2
#define E_MBAT_GOOD 3
#define E_SUPPLY_SOUND_WARNING 0x0001
#define E_SUPPLY_FLASH_WARNING 0x0002
#define E_SUPPLY_SYSTEM_TIME_CHANGED 0x0004
typedef struct
    {
    unsigned char mainBatteryLevel;
    unsigned char mainBatteryStatus;
    unsigned char backupBatteryLevel;
    unsigned char dcLevel;
    unsigned short int warningFlags;
    unsigned long int insertionDate;
    unsigned long int ticksInUseBattery;
    unsigned long int ticksInUseDc;
    unsigned long int maTicks;
    } E_SUPPLY_INFO;
#define ImgVersion 0x200f
#define DevVersion 0x200f
#define SignatureSize 16
#define ImageSignature "ImageFileType**"
#define LDDSignature "LDDFileType****"
#define PDDSignature "PDDFileType****"
#define LIBSignature "LIBFileType****"
#define HeaderSize 0x40
#define MagicLandSize 0x40
#define MaxAddFiles 4
typedef struct
    {
    unsigned short int offset;
    unsigned short int length;
    } ADDFILE;
typedef struct
    {
    unsigned char name[E_MAX_NAME+2]; /* Dyl name zero terminated */ 
    unsigned long int offset; /* Offset in File */ 
    } DYLENTRY;
typedef struct
    {
    unsigned char Signature[SignatureSize];
    unsigned short int ImageVersion;
    unsigned short int HeaderSizeBytes;
    unsigned short int CodeParas;
    unsigned short int InitialIP;
    unsigned short int StackParas;
    unsigned short int DataParas;
    unsigned short int HeapParas;
    unsigned short int InitializedData;
    unsigned short int CodeCheckSum;
    unsigned short int DataCheckSum;
    unsigned short int CodeVersion;
    unsigned short int Priority;
    ADDFILE Add[MaxAddFiles];
    unsigned short int DylCount;
    unsigned long int DylTableOffset;
    unsigned short int Spare;
    } ImgHeader;
typedef struct
    {
    unsigned char Signature[SignatureSize];
    unsigned short int DeviceVersion;
    unsigned short int HeaderSizeBytes;
    unsigned short int CodeParas;
    unsigned short int CodeCheckSum;
    unsigned short int CodeVersion;
    } DevHeader;
#define ALawSignature "ALawSoundFile**"
typedef struct
    {
    char Signature[SignatureSize];
    unsigned short int Version;
    unsigned long int Samples;
    unsigned short int SilenceInTicks;
    unsigned short int Repeats;
    unsigned short int Spare[3];
    } SndFile;
#ifdef __cplusplus
extern "C" {
#endif
typedef void (*_CALL)(void);
#pragma save,call(reg_param =>(bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_attachfile(char *);
extern int p_detachfile(char *);
#pragma call(reg_param =>(cx,ax),reg_saved =>(bx,dx,si,di,EPOC_SAVE))
extern int p_dayinm(int,int);
#pragma call(reg_param =>(bx,dx),reg_saved =>(bx,dx,si,di,EPOC_SAVE))
extern int p_devdel(const char *,int);
#pragma call(reg_param =>(bx,di,dx,si),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_devfnd(int,const char *,int,char *);
#pragma call(reg_param =>(bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_devqu(const char *);
#pragma restore
extern int cdecl p_exec(const char *);
extern int cdecl p_execasync(const char *,short int *,int *);
extern int cdecl p_execc(const char *,void *,int);
extern int cdecl p_execcasync(const char *,void *,int,short int *,int *);
#pragma save,call(reg_param =>(),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_totalK(void);
extern int p_getauto(void);
extern int p_getautomains(void);
extern int p_getsnd(void);
extern int p_getbat(void);
extern int p_detectsoaktestfixture(void);
extern int p_relogpacks(void);
extern int p_getlanguage(void);
extern int p_getlcd(void);
extern int p_getlcdcontrast(void);
extern int p_getpsu(void);
extern int p_getpid(void);
extern unsigned int p_getbacklight(void);
extern unsigned int p_getram(void);
extern int p_getres(void);
extern int p_getshiftstate(void);
extern int p_getnotify(void);
extern int p_getalarmid(void);
extern void p_allowoff(void);
extern unsigned int p_returntickcount(void);
extern unsigned int p_returnexpansionportinfo(void);
#pragma call(reg_param =>(bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_setbacklight(unsigned int);
extern void p_setconfig(unsigned int);
extern unsigned int p_setirpowerlevel(unsigned int);
extern unsigned int p_setcapslockmode(int);
#pragma call(reg_param =>(di,si,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_getosd(void *,void *,unsigned int);
#pragma call(reg_param =>(bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_getpri(int);
extern int p_getowner(int);
extern void p_getscancodes(unsigned short int *);
#pragma call(reg_param =>(bx,cx,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_getpthbyid(int,char *);
extern int p_getpthbyidasync(int,char *,short int *);
extern int p_locdevice(int,unsigned short int *);
extern int p_locdeviceasync(int,unsigned short int *,short int *);
#pragma call(reg_param =>(bx,cx,di,si,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_locreadpdd(int,long int *,void *,unsigned int);
extern int p_locreadpddasync(int,long int *,void *,unsigned int,short int *);
#pragma call(reg_param =>(ax),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_setautomains(int);
extern void p_setnotify(int);
extern int p_backlight(int);
extern int p_setonevent(int);
extern int p_setbat(int);
extern void p_hwexit(void);
extern void p_lcdcontrastdelta(int);
extern void p_marka(void);
extern void p_mcancel(void);
extern void p_unmarka(void);
extern void p_notifyunhook(void);
extern void p_alarmunhook(void);
extern void p_osdummy(void);
extern unsigned int p_version(void);
extern unsigned int p_romversion(void);
#pragma call(reg_param =>(ax,bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_gettext(int,char *);
#pragma call(reg_param =>(bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_hgran(int);
#pragma call(reg_param =>(bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_iogetkm(E_KEYS *);
extern void p_iogetkmasync(E_KEYS *);
extern int p_iosignalbypid(int);
#pragma call(reg_param =>(bx,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_loadldd(const char *);
extern int p_loadlddasync(const char *,short int *);
extern int p_loadpdd(const char *);
extern int p_loadpddasync(const char *,short int *);
#pragma call(reg_param =>(bx,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_logon(int,int);
extern int p_logoff(int,int);
extern int p_logoffx(int,int);
#pragma call(reg_param =>(bx,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_logona(int,short int *);
extern int p_logoffa(int);
#pragma call(reg_param =>(bx,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_mfree(void *,int);
#pragma call(reg_param =>(bx,ax),reg_saved =>(cx,dx,si,di,EPOC_SAVE))
extern int p_minit(int,int);
#pragma call(reg_param =>(di,bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_mreceive(short int *,void *);
#pragma call(reg_param =>(bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_mreceivew(void *);
#pragma call(reg_param =>(bx,cx,si,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_msend(int,unsigned int,void *);
extern int p_msendreceivew(int,unsigned int,void *);
extern int p_msendreceivea(int,unsigned int,void *,short int *);
#pragma call(reg_param =>(bx,cx,dx,di,si),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_notify(const char *,const char *,const char *,const char *,const char *);
#pragma call(reg_param =>(ax,bx,dx,di,si),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_notifyerr(int,const char *,const char *,const char *,const char *);
#pragma call(reg_param =>(bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_notifyhook(int);
extern int p_alarmhook(int);
#pragma call(reg_param =>(bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_onterminate(int);
#pragma call(reg_param =>(cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_off(unsigned int);
#pragma call(reg_param =>(bx,di,si,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_pcpyto(int,void *,void *,unsigned int);
#pragma call(reg_param =>(bx,si,di,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_pcpyfr(int,void *,void *,unsigned int);
extern int p_piscpyfr(int,void *,char *,unsigned int);
#pragma call(reg_param =>(bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_pcreate(E_CPB *);
extern int p_locchg(int mask);
#pragma call(reg_param =>(bx,di,si),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_pfind(int,const char *,char *);
#pragma call(reg_param =>(bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_pidfind(const char *);
#pragma call(reg_param =>(bx,ax),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_pkill(int,int);
#pragma call(reg_param =>(bx,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_pterminate(int,int);
#pragma call(reg_param =>(bx,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_prename(int,const char *);
#pragma call(reg_param =>(bx,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_pname(int,char *);
#pragma call(reg_param =>(bx,ax),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_ppanic(int,int);
#pragma call(reg_param =>(bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_presume(int);
extern int p_psuspend(int);
#pragma call(reg_param =>(bx,cx,si,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_ptask(char *,int,_CALL,void *);
#pragma call(reg_param =>(dx,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_sdate(unsigned long int);
#pragma call(reg_param =>(bx,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_setauto(int);
extern void p_setsnd(int);
extern int p_setdefaultpath(const char *);
#pragma call(reg_param =>(bx,ax),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_setpri(int,int);
#pragma call(reg_param =>(bx,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_signaln(int,int);
extern void p_signalnr(int);
#pragma call(reg_param =>(dx,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_sleept(long int);
#pragma call(reg_param =>(bx,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_supply(E_SUPPLY *);
extern void p_supplyinfo(E_SUPPLY_INFO *);
extern void p_wsupply(E_SUPPLY_WARNINGS *);
#pragma call(reg_param =>(bx,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_wait(int);
extern int p_watchall(unsigned int);
#pragma call(reg_param =>(si,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_setpass(char *,char *);
#pragma call(reg_param =>(si),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_testpass(char *);
#pragma call(reg_param =>(si,ax),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_controlpass(char *,int);
#pragma call(reg_param =>(),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int p_querypass(void);
extern void p_tickle(void);
extern void p_nexthalfsecond(void);
#pragma call(reg_param =>(),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE),inline =>on)
static int p_iostatkm(void) = {0xcd,0xda};
static int p_nexthalfsecondstatus(void) = {0xcd,0xdd};
#pragma call(reg_param =>(ax),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE),inline =>on)
static unsigned int p_setrombank(unsigned int) = {0xcd,0xdf};
static unsigned int p_getrombank(void) = {0xcd,0xe0};
#pragma restore
#pragma save,call(reg_param =>(bx,cx,dx,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_playsounda(const char *,unsigned int,unsigned int,short int *);
extern int p_playsoundw(const char *,unsigned int,unsigned int);
extern void p_playsoundcancel(void);
#pragma call(reg_param =>(bx,cx,dx,di,si),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_playsoundao(const char *,unsigned int,unsigned int,short int *,unsigned int);
extern int p_playsoundwo(const char *,unsigned int,unsigned int,unsigned int);
#pragma call(reg_param =>(bx,cx,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_recordsounda(const char *,unsigned int,short int *);
extern int p_recordsoundw(const char *,unsigned int);
extern void p_recordsoundcancel(void);
#pragma call(reg_param =>(bx,ax),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void p_nmdaya(char *,int);
extern void p_nmmona(char *,int);
#pragma restore
#ifdef __cplusplus
}
#endif

