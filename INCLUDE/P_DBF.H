/*	HEADER - P_DBF.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_DBF_H
#include <stdepoc.h>
#define DbfMaxRecords 0xfffe    /* 0-fffd,1-fffe for OPL with ffff at eof */ 
#define DbfRecordTypeMask 0xf000    /* Top nibble of header word */ 
#define DbfRecordLengthMask 0x0fff   /* Bottom 12 bits of header word */ 
#define DbfFieldTypeWord 0
#define DbfFieldTypeLong 1
#define DbfFieldTypeDouble 2
#define DbfFieldTypeString 3
#define DbfFindAllStrings -1		/* for nStrings parameter to DbfFindRead */ 
#define DbfFindBackwards 0x0000
#define DbfFindForwards 0x0100
#define DbfFindLast 0x0200
#define DbfFindFirst 0x0300
#define DbfFindCaseIndependent 0x0000
#define DbfFindCaseDependent 0x1000
#define DbfCopyFromHandle 0
#define DbfCopyToHandle 1
#define DbfStateCopyAbort -2    /* for DbfCopyFile only */ 
#define DbfStateOpenNoIndex -2   /* for DbfOpen only */ 
#define DbfStateDisabled -1
#define DbfStateStart 0
#define DbfStateScanBuffer 1
#define DbfStateGetBuffer 2
#define DbfStateFinished 3
#define DbfHeaderNameSize 16
#define DbfHeaderLength 22   /* Length of header without F.I.R */ 
#define DbfMaxFirLength 32   /* 32 bytes */ 
#define DbfMinBufferSize 512  /* Minimum buffer size */ 
#define DbfMaxBufferSize 16384 /* Maximum buffer size */ 
#define DbfMaxRecordLength 4094 /* Maximum record length,not inc. header */ 
#define DbfRecordTypeFir 2   /* Record type for Field Information Record */ 
#define DbfRecordTypeDesc 3  /* Record type for 'descriptive' record */ 
#define DbfRecordTypeAll 15  /* Record type to match all records (except erased) */ 
typedef struct
{
unsigned char fileType[DbfHeaderNameSize];   /* Name of the file type */ 
unsigned short int createVersion;  /* software version used to create file */ 
unsigned short int dataStart;    /* Offset in file for start of data */   
unsigned short int needVersion;   /* minimum software version needed to handle this file */ 
unsigned short int firHeader;
unsigned char fir[DbfMaxFirLength];
} DbfHeader;
typedef struct
{
unsigned short int header;      /* Record header word */ 
unsigned char data[2];     /* Data follows... */ 
} DbfRecord;
typedef struct
{
void **pFcb; /* the address of the fcb */
char *fName; /* the file name */
unsigned int mode; /* the mode */
DbfHeader *pHead; /* the address of the header */
} DbfOpenArgs;
#ifdef __cplusplus
extern "C" {
#endif
#pragma	save, call(reg_param=>(bx,dx),reg_saved=>(cx,si,di,EPOC_SAVE))
extern int DbfFileSize(void *pHandle,unsigned long int *pos);
#pragma	call(reg_param=>(di,bx,si,dx,cx,ax),reg_saved=>(bx,cx,dx,si,di,EPOC_SAVE))
extern int DbfQuickOpen(int *pState,DbfOpenArgs *pArgs,unsigned char *buffer,unsigned int length,unsigned int type);
extern int DbfCopyFile(unsigned int *state,void *sHandle,const char *targetName,unsigned int targetMode,unsigned int type,int dir);
extern int DbfEraseRead(int *state,void *pHandle,unsigned short int *pOffset);
extern int DbfCompress(unsigned int *state,void *pHandle);
#pragma	call(reg_param=>(di,bx,si,cx,dx,ax),reg_saved=>(bx,cx,dx,si,di,EPOC_SAVE))
extern int DbfFindRead(unsigned int *state,void *pHandle,const void *buffer,unsigned int length,unsigned int findMode,unsigned int nStrings,unsigned short int *pOffset);
#pragma call(reg_param=>(di,bx,cx),reg_saved=>(bx,cx,dx,si,di,EPOC_SAVE))
extern int DbfUpdate(int *state,void *pHandle,unsigned int length);
#pragma call(reg_param=>(bx,cx,si),reg_saved=>(bx,cx,dx,si,di,EPOC_SAVE))
extern int DbfAbsRead(void *pHandle,unsigned int record,unsigned short int *pOffset);
extern int DbfAppend(void *pHandle,unsigned int length);
extern int DbfFlush(void *pHandle);
extern int DbfClose(void *pHandle);
extern unsigned int DbfDescRecordRead(void *pHandle);
extern int DbfDescRecordWrite(void *pHandle,unsigned int length);
#pragma call(reg_param=>(bx,cx,si,di),reg_saved=>(bx,cx,si,di,EPOC_SAVE))
extern int DbfAbsReadSense(void *pHandle,unsigned int record,unsigned short int *pOffset,unsigned long int *pPos);
#pragma call(reg_param=>(bx,si),reg_saved=>(cx,dx,di,EPOC_SAVE))
extern int DbfNextRead(void *pHandle,unsigned short int *pOffset);
extern int DbfBackRead(void *pHandle,unsigned short int *pOffset);
extern int DbfFirstRead(void *pHandle,unsigned short int *pOffset);
extern int DbfLastRead(void *pHandle,unsigned short int *pOffset);
#pragma call(reg_param=>(ax,bx,si,cx),reg_saved=>(bx,cx,dx,si,di,EPOC_SAVE))
extern int DbfExtHeaderRead(unsigned int x,void *pHandle,void *buffer,unsigned int len);
extern int DbfExtHeaderWrite(unsigned int x,void *pHandle,const void *buffer,unsigned int len);
#pragma call(reg_param=>(bx,si),reg_saved=>(bx,cx,dx,si,di,EPOC_SAVE),inline=>on)
static unsigned int DbfVersion(void)={0xb4,0x0a,0xcd,0xd8};
static void DbfTrash(void *pHandle)={0xb4,0x03,0xcd,0xd8};
static unsigned int DbfSense(void *pHandle)={0xb4,0x15,0xcd,0xd8};
static unsigned int DbfCount(void *pHandle)={0xb4,0x16,0xcd,0xd8};
static int DbfCopyDown(void *pHandle,unsigned int offset)={0xb4,0x04,0xcd,0xd8};
#pragma restore
extern int cdecl DbfFindReadField(unsigned int *state,void *pHandle,const void *buffer,unsigned int length,unsigned int findMode,unsigned int nStrings,unsigned short int *pOffset,unsigned int startStr);
extern int cdecl DbfOpen(int *state,void **pHandle,const char *name,unsigned int mode,
        DbfHeader *header,unsigned char *buffer,unsigned int length,unsigned int type);
#ifdef __cplusplus
}
#endif


