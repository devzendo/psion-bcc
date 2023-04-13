/* Release 3.00 */
/*-------------------------------------------------------------------------*
*                                                                          *
*  window.h - definitions for window module types and functions.           *
*                                                                          *
*  COPYRIGHT (C) 1989..1991 Jensen and Partners. All Rights Reserved       *
*                                                                          *
*--------------------------------------------------------------------------*/

#ifndef _WINDOWS
#ifndef _TSWIN_INC_
#define _TSWIN_INC_

#define TRUE  1
#define FALSE 0

#ifdef __cplusplus
extern "C" {
#endif
extern void    gotoxy(int x, int y);
extern int     wherex(void);
extern int     wherey(void);
extern void    clrscr(void);
extern void    cursoron(void);
extern void    cursoroff(void);
extern void    insline(void);
extern void    delline(void);
extern void    clreol(void);
extern void    setwrap(int on);
#ifdef __cplusplus
}
#endif
#endif
#endif
