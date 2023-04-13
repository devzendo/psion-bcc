/*	HEADER - HWIF.H
Copyright (C) Psion PLC 1992
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.20F 08/11/92 DWW New version for Developers Conference
2.00F 01/12/93 DWW Version 2 C SDK
*/
#define HWIF_H
#ifndef P_GRAF_H
#include <p_graf.h>
#endif
#ifndef WLIB_H
#include <wlib.h>
#endif
#ifdef STDEPOC_H
#  ifndef P_CONS_H
#  include <p_cons.h>
#  endif
#else
#  ifndef EPOCCONS_H
#  include <epoccons.h>
#  endif
#endif

typedef struct
    {
    char *title;
    unsigned short int nlines;
    } H_MENU_DATA;
#define H_DIALOG_TEXT    0
#define H_DIALOG_CHOICE   1
#define H_DIALOG_NUMBER   2
#define H_DIALOG_FLOAT   3
#define H_DIALOG_TIME    4
#define H_DIALOG_DATE    5
#define H_DIALOG_EDIT    6
#define H_DIALOG_SEDIT   7
#define H_DIALOG_XINPUT   8
#define H_DIALOG_FSEL    9
#define H_DIALOG_BUTTONS  10
typedef struct
    {
    char *str;
    unsigned short int type;
    } H_DI_TEXT;
#define H_DTEXT_ALIGN_LEFT   0
#define H_DTEXT_ALIGN_RIGHT   1
#define H_DTEXT_ALIGN_CENTRE  2
#define H_DTEXT_BOLD      0x100
#define H_DTEXT_UNDERLINE    0x200
#define H_DTEXT_SELECTABLE   0x400
typedef struct
    {
    union
        {
        unsigned short int *sel;
        unsigned short int count;
        } u;
    void *menu;
    } H_DI_CHOICE;
typedef struct
    {
    long int *value;
    long int low;
    long int high;
    } H_DI_NUMBER;
typedef struct
    {
    double *value;
    double low;
    double high;
    } H_DI_FLOAT;
typedef struct
    {
    unsigned long int *value;
    unsigned long int low;
    unsigned long int high;
    unsigned short int type;
    } H_DI_TIME;
#define H_DTIME_SHOW_SECONDS  1
#define H_DTIME_DURATION    2
typedef struct
    {
    unsigned long int *value;
    unsigned long int low;
    unsigned long int high;
    } H_DI_DATE;
#define H_LAST_DAY   93501l
#define H_FIRST_SYS_DAY 25567l
#define H_LAST_SYS_DAY 75276l
typedef struct
    {
    char *str;
    unsigned short int len;
    } H_DI_EDIT;
typedef struct
    {
    char *str;
    unsigned short int len;
    unsigned short int width;
    } H_DI_SEDIT;
typedef struct
    {
    char *str;
    } H_DI_XINPUT;
typedef struct
    {
    char *fname;
    unsigned short int flags;
    } H_DI_FSEL;
typedef struct
    {
    char *str;
    short int accel;
    } H_CARD;
typedef struct
    {
    char *str;
    } H_CHOICE;
typedef struct
    {
    char *str;
    unsigned short int keycode;
    } H_BUTTON;
#define W_EVENT_KEY (CONS_SPECIAL_EVENT*256)
#define H_FILE_ALLOW_DIRS 0x02
#define H_FILE_JUST_DIRS 0x04
#define H_FILE_FORCE_NXIST 0x08
#define H_FILE_NO_AUTOQUERY 0x10
#define H_FILE_ACCEPT_NULL 0x20
#define H_FILE_SET_DEFEXT 0x40
#define H_FILE_CAN_WILDCARD 0x80
#define H_FILE_RESTRICT_LIST H_FILE_FORCE_NXIST
#define H_FILE_PICK_SELECTOR 0
#define H_FILE_NEW_EDITOR 0x01
#define H_PRINT_PAGE 0x01
#define H_PRINT_LINE 0x02
#define H_PRINT_RIGHT 0x04
#define H_PRINT_TEXT 0x10
#define H_PRINT_KEEP 0x8000
#define H_PRINT_STY_UNDERLINE 0x01
#define H_PRINT_STY_BOLD 0x02
#define H_PRINT_STY_ITALIC 0x04
#define H_PRINT_STY_SUPER 0x08
#define H_PRINT_STY_SUB 0x10
typedef struct
    {
    short int flags;
    short int typf;
    short int fheight;
    short int style;
    short int down;
    short int indent;
    short int height;
    short int right;
    char *buf;
    unsigned short int blen;
    } H_PRINT;
#define H_TIME_SET_SDATE 0
#define H_TIME_SET_DATE 1
#define H_TIME_SET_DAYSEC 2
#define H_TIME_SET_NOW 3
#define H_TIME_SENSE_BOTH 3
#define H_TIME_SENSE_DATE 4
#define H_TIME_SENSE_TIME 5
#define H_TIME_FORMAT_NO_DAY 0x0004
#define H_TIME_FORMAT_NO_MONTH 0x0008
#define H_TIME_FORMAT_NO_YEAR 0x0010
#define H_TIME_FORMAT_MONTH_NAME 0x0020
#define H_TIME_FORMAT_SUFFIX 0x0040
#define H_TIME_FORMAT_DAY_NAME 0x0080
#define H_TIME_FORMAT_NO_CENTURY 0x0100
#define H_TIME_FORMAT_NO_SECONDS 0x0200
#define H_ALARM_TIMED 2
#define H_ALARM_UNTIMED 1
typedef struct
    {
    unsigned short int maxchars;
    unsigned short int vulen;
    unsigned short int vislines;
    P_POINT pos;
    unsigned short int win;
    unsigned short int font;
    unsigned short int style;
    unsigned short int lead_tot;
    unsigned short int lead_top;
    } H_EDIT_BOX;
typedef struct
    {
    unsigned short int pos;
    short int line;
    short int x;
    } H_SCRLAY_PLX;
#define H_EDIT_BOX_CLIPBOARD 0x0040
#define H_EDIT_BOX_LEFT_CURSOR 0x0200
#define H_EDIT_BOX_FONT 0x1000
#define H_EDIT_BOX_LEADING 0x2000
#define H_EDIT_BOX_VISLINES 0x4000
#define HEB_FIND_BACKWARDS 0x01
#define HEB_FIND_CASESENS 0x02
#define H_DTEDIT_DDMMYYYY       0x0000
#define H_DTEDIT_HHMMSS         0x1100
#define H_DTEDIT_HHMM           0x0100
#define H_DTEDIT_HHMMSS_D       0x1300
#define H_DTEDIT_HHMM_D         0x0300
#define H_DTEDIT_SET_VALUE      0x0001
#define H_DTEDIT_SET_LOW        0x0002
#define H_DTEDIT_SET_HIGH       0x0004
typedef struct
    {
    unsigned short int flags;
    long int value;
    long int low;
    long int high;
    P_POINT pos;
    unsigned short int win;
    unsigned short int width;
    unsigned short int emph;
    } H_DTEDIT;
typedef struct
    {
    unsigned short int flags;
    long int value;
    long int low;
    long int high;
    } H_SE_DTEDIT;
#ifdef __cplusplus
extern "C" {
#endif
extern int hIFInit(void *);
extern int hMenuOpen(void);
extern int hMenuAdd(char *,void *);
extern int hMenuRun(void);
extern void hMenuClose(void);
extern int hDlgOpen(char *);
extern int hDlgAdd(unsigned short int,char *,void *);
extern int hDlgRun(void);
extern void hDlgClose(void);
extern int hDlgPosition(int x,int y);
extern void *hCardOpen(void);
extern int hCardAdd(void *,int,int,char *);
extern void hCardClose(void *);
extern void *hChoiceOpen(void);
extern int hChoiceAdd(void *,int,char *);
extern void hChoiceClose(void *);
extern void *hButtonOpen(void);
extern int hButtonAdd(void *,int,int,char *);
extern void hButtonClose(void *);
extern void hEnsurePath(char *fname);
extern void hSetUpStatusNames(char *pb);
extern int hCrackCommandLine(void);
extern int hIsDbfCompressible(void *dH);
extern int hDTMFString(char *zts);
extern unsigned int hLastSystemKey(unsigned int *pmodifiers);
extern void uCommonInit(void);
extern void uEnableGrey(void);
extern void uGetKey(WMSG_KEY *pkey);
extern void uGetKeyA(short int *pstat,WMSG_KEY *pkey);
extern void uCancelGetKeyA(void);
extern int uKeyPressOutstanding(void);
extern void uEscape(unsigned short int flag);
extern unsigned int uFindMainWid(void);
extern void uForceToFront(void);
extern void uErrorString(char *message);
extern int uErrorValue(int ret);
extern void *uCheckHandle(void *handle);
extern void uZTStoBCS(char *bcs,char *zts);
extern int uOpenDialog(char *title);
extern int uAddDialogItem(int type,char *prompt,void *data);
extern int uRunDialog(void);
extern int cdecl uAddButtonList(char *but,int code,...);
extern int uBeginDCL(H_DI_CHOICE *pch);
extern int uGrowDCL(H_DI_CHOICE *pch,char *choice);
extern int uAddDCL(char *prompt,unsigned short int *nsel,H_DI_CHOICE *pch);
extern int cdecl uAddChoiceList(char *prompt,unsigned short int *nsel,char *choice,...);
extern int cdecl uDialogMenu(char *title,char *pb,...);
extern void cdecl uDisplayText(char *pb,...);
extern int uPresentMenus(void);
extern void uAddGreyUline(unsigned char,unsigned short int *plines);
extern void uSetDialogUline(int pos,int on);
extern int uLocateCommand(int accel);
extern void hPrintSetupDialog(void);
extern void hPrint(int printline(H_PRINT *));
extern void hPrinterSetupDialog(void);
extern void hPrintSetSI(unsigned int subsqind);
extern int hPrintSensePageWidth(void);
extern int hPrintSenseBufWidth(char *buf,int blen);
extern void hHelpSubSystem(int startid,int indexid);
extern void *hTTOpen(void);
extern int hTTSetTime(void *handle,int type,void *data);
extern int hTTSenseString(void *handle,int type,char *buf);
extern void hTTSetFormat(void *handle,int values);
extern void hTTSetAbbreviations(void *handle,int dayabb,int monabb);
extern void hTTClose(void *handle);
extern int hEBHandleKey(void *ebH,int keycode,int modifier);
extern int hEBCompleteFormat(void *ebH);
extern char *hEBSenseText(void *ebH);
extern int hEBSetText(void *ebH,char *pb,int blen);
extern void hEBEmphasise(void *ebH,int flag);
extern int hEBSetSelect(void *ebH,int aoff,int coff);
extern int hEBSenseSelect(void *ebH,unsigned short int *top);
extern int hEBSetClipText(void *ebH,char *pb,int blen);
extern char *hEBSenseClipText(void *ebH);
extern int hEBEvaluate(void *ebH);
extern int hEBSetMargin(void *ebH,unsigned int right);
extern unsigned int hEBSenseMargin(void *ebH);
extern int hEBChangeWidth(void *ebH,int width);
extern void hEBSetCWidth(void *ebH,int cwidth);
extern int hEBInsert(void *ebH,char *pb,int blen);
extern int hEBReplace(void *ebH,char *replace,int backwards);
extern int hEBCopy(void *ebH);
extern int hEBPaste(void *ebH);
extern int hEBFind(void *ebH,char *str,int flags);
extern int hEBSenseChanged(void *ebH);
extern void hEBClearChanged(void *ebH);
extern int hEBShowSymbols(void *ebH,int flag);
extern void *hEBOpen(int flags,H_EDIT_BOX *heb);
extern void hEBClose(void *ebH);
extern void *hEBSenseDoc(void *ebH);
extern int hEDCapacity(void *doc,unsigned int maxlen);
extern int hEDInsert(void *doc,unsigned int pos,void *buf,unsigned int len);
extern int hEBDocChanged(void *ebH);
extern int hEBPosToXL(void *ebH,H_SCRLAY_PLX *plx);
extern void hDeclareAppRcb(void *rcb);
extern void *hInitAppRcb(void);
extern int hSetSystemResLang(int lang);
extern void hRequestReplacePack(void *rcb,char *fname);
extern void *hDTOpen(H_DTEDIT *dte);
extern void hDTClose(void *dte);
extern void hDTSet(void *dte,H_SE_DTEDIT *sdte);
extern void hDTSense(void *dte,H_SE_DTEDIT *sdte);
extern int hDTSelfCheck(void *dte);
extern int hDTHandleKey(void *dte,int keycode,int modifier);
extern void hDTEmphasise(void *dte,int flag);
extern void hSetVarrayInChlist(int index,int nsel,void *varray);
extern void hOODialog(int catHandle,int classno,int resid,void *rbuf);
extern int hLoadOwnDyl(int index);
#ifdef __cplusplus
}
#endif

