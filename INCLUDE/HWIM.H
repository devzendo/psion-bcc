/*      HEADER - HWIM.H
Hwim utilities constants, structures and function prototypes
Copyright (c) Psion PLC 1991 - 1996.
*/

#define HWIM_H

#define PTR_CALL call(reg_param =>(bx,ax,cx,dx,si,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))

#ifndef HWIMMAN_G
#include <hwimman.g>            /* for the definition of DL_DATA */
#endif

GLREF_C INT CDECL hConfirm(INT rid,...);
GLREF_C INT CDECL h2LineConfirm(INT secondrid,INT rid,...);
GLREF_C INT CDECL hErrorDialog(INT err,INT rid,...);
GLREF_C VOID CDECL hInfoPrint(INT rid,...);
GLREF_C VOID CDECL hBusyPrint(INT delay,INT rid,...);
GLREF_C TEXT * CDECL hAtos(TEXT *buf,INT frid,...);
#pragma save,call(reg_param =>(bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
GLREF_C VOID hDestroy(VOID *hand);
#pragma call(reg_param =>(bx,ax,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
GLREF_C INT hLaunchDial(P_CATID cat,INT class,DL_DATA *data);
#pragma call(reg_param =>(dx,si),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
GLREF_C INT hLoadResBuf(INT id,VOID *pb);
GLREF_C INT hLoadResource(INT id,VOID *ppdata);
#pragma call(reg_param =>(cx,dx,bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
GLREF_C INT hAtob(TEXT *pb,INT rid,INT *pargs);
#pragma call(reg_param =>(bx,ax),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
GLREF_C VOID hErrs(TEXT *buf,INT err);
#pragma call(reg_param =>(ax),reg_saved =>(bx,dx,si,di,EPOC_SAVE))
GLREF_C VOID hInfoPrintErr(INT err);
#pragma call(reg_param =>(dx,si,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
GLREF_C TEXT *hLoadChlistResBuf(INT rid,INT choice,TEXT *buf);
#pragma call(reg_param =>(cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
GLREF_C VOID hWservComSend(INT comid);
#pragma call(reg_param =>(bx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
GLREF_C VOID hInitVis(VOID *win);
GLREF_C VOID hAppendEllipsis(TEXT *buf);
GLREF_C VOID hSetGStyle(UINT style);
GLREF_C VOID hEnsurePath(TEXT *filename);
#pragma call(reg_param =>(),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
GLREF_C VOID hBeep(VOID);
#pragma call(reg_param =>(ax),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
GLREF_C VOID hSetGTmode(UINT tmode);
#pragma call(reg_param =>(cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
GLREF_C VOID hSetGFont(UINT fid);
GLREF_C INT hGetSWid(TEXT *pzts);
#pragma call(reg_param =>(cx,ax),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
GLREF_C INT hGetBWid(TEXT *pb,INT blen);
GLREF_C INT hGetBBWid(TEXT *pb,INT blen);
#pragma call(reg_param =>(bx,ax),reg_saved =>(cx,dx,si,di,EPOC_SAVE))
GLREF_C VOID hTwipsToBuf(TEXT *pbuf,UINT val);
GLREF_C UINT hDoubleToTwips(DOUBLE *val);
GLREF_C VOID hTwipsToDouble(DOUBLE *dd,UINT value);
#pragma call(reg_param =>(dx,ax),reg_saved =>(si,di,EPOC_SAVE))
GLREF_C VOID hDlgSet(UBYTE index,VOID *set);
GLREF_C VOID hDlgSense(UBYTE index,VOID *sense);
#pragma call(reg_param =>(dx,ax),reg_saved =>(si,di,EPOC_SAVE))
GLREF_C VOID hDlgSetPrompt(UBYTE index,TEXT *pmt);
GLREF_C VOID hDlgSetText(UBYTE index,TEXT *buf);
GLREF_C VOID hDlgSetEdwin(UBYTE index,TEXT *buf);
GLREF_C VOID hDlgSetChlist(UBYTE index,INT nsel);
GLREF_C VOID hDlgSetChlistOn(UBYTE index);
GLREF_C VOID hDlgSetNcedit(UBYTE index,UINT value);
GLREF_C VOID hDlgSetLledit(UBYTE index,INT value);
GLREF_C VOID hDlgSetPtedit(UBYTE index,UBYTE ch);
GLREF_C VOID hDlgSetFledit(UBYTE index,DOUBLE *value);
GLREF_C VOID hDlgSetTwips(UBYTE index,UINT value);
GLREF_C VOID hDlgSenseRgedit(UBYTE index,UWORD *values);
GLREF_C VOID hDlgSenseFledit(UBYTE index,DOUBLE *value);
GLREF_C VOID hDlgItemDim(UBYTE index,INT flag);
GLREF_C VOID hDlgItemLock(UBYTE index,INT flag);
#pragma call(reg_param =>(dx,ax,bx),reg_saved =>(si,di,EPOC_SAVE))
GLREF_C VOID hDlgSetDtedit(UBYTE index,ULONG value);
GLREF_C VOID hDlgSetRgedit(UBYTE index,UINT value1,UINT value2);
#pragma call(reg_param =>(dx),reg_saved =>(si,di,EPOC_SAVE))
GLREF_C VOID hDlgSetTitleByRid(INT rid);
GLREF_C TEXT *hDlgSenseEdwin(UBYTE index);
GLREF_C INT hDlgSenseChlist(UBYTE index);
GLREF_C UINT hDlgSenseNcedit(UBYTE index);
GLREF_C INT hDlgSenseLledit(UBYTE index);
GLREF_C INT hDlgSensePtedit(UBYTE index);
GLREF_C UINT hDlgSenseTwips(UBYTE index);
GLREF_C ULONG hDlgSenseDtedit(UBYTE index);
GLREF_C VOID hDlgTakeFocus(UBYTE index);
#pragma METHOD_CALL
GLREF_C VOID hDlgInit(VOID *dlg,HD_DLGBOX_RSC *head,VOID *rbuf);
#pragma restore
