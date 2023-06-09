/* Generated by Ctran from win.cl */
#define WIN_G
#ifndef OLIB_G
#include <olib.g>
#endif
#ifndef WLIB_H
#include <wlib.h>
#endif
/* Class Numbers */
#define C_WIN 1
/* Method Numbers */
#define O_WN_INIT 13
#define O_WN_VISIBLE 7
#define O_WN_SENSE 11
#define O_WN_POSITION 4
#define O_WN_KEY 6
#define O_WN_DODRAW 2
#define O_WN_CALC_POSITION 5
#define O_WN_CONNECT 3
#define O_WN_REDRAW 1
#define O_WN_EMPHASISE 8
#define O_WN_SENSE_HELP 9
#define O_WN_SET 10
#define O_WN_DRAW 12
/* Constants for win */
#define CURSOR_WIDTH 2
#define CURSOR_COLWID 2
#define SYSTEM_FONT_COLWID 2
#define W_KEY_SPACE 32
#define PR_BWIN_CUSHION 0x1
#define PR_BWIN_CORNER_4 0x2
#define PR_BWIN_SHADOW_1 0x4
#define PR_BWIN_SHADOW_2 0x8
#define PR_WIN_EMPHASISED 0x10
#define PR_BWIN_OPEN 0x20
#define PR_BWIN_CORNER_1 0x40
#define PR_WIN_IS_DLCTRL 0x80
#define PR_WIN_IS_OVCTRL 0x100
#define PR_WIN_INITIALISED 0x800
#define PR_WIN_FORCE_RIGHT 0x1000
#define PR_WIN_FORCE_LEFT 0x2000
#define PR_WIN_FORCE_BOTTOM 0x4000
#define PR_WIN_FORCE_TOP 0x8000
#define PR_WIN_FORCE_FLAGS 0xf000
#define WIN_3dBORDER PR_WIN_FORCE_RIGHT
#define WIN_FROM_ATS PR_WIN_FORCE_LEFT
#define IN_WIN_EMPHASISED (PR_WIN_EMPHASISED)
#define WV_INVISIBLE 0
#define WV_VISIBLE 1
#define WV_INITINVIS 2
#define WV_INITVIS 3
#define WN_KEY_NO_CHANGE 0
#define WN_KEY_CHANGED 3
#define WN_KEY_CHANGED_DEFER	7
#define WN_KEY_CANCELLED (-1)
#define WN_KEY_ABSORB_ON (-2)
#define ERROR_RID_OFFSET 512
/* Property of win */
typedef struct {
unsigned short int id;
unsigned short int flags;
} PRS_WIN;
typedef struct pr_win
{
PRS_ROOT root;
PRS_WIN win;
} PR_WIN;
