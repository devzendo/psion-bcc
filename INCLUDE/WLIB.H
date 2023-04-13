/*	HEADER - WLIB.H
Copyright (C) Psion PLC 1991
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 22/10/93 SLT Second relase
*/
#define WLIB_H
#include <stdepoc.h>
#ifndef P_STD_H
#include <p_std.h>
#endif
#ifndef P_GRAF_H
#include <p_graf.h>
#endif
#ifndef WSKEYS_H
#include <wskeys.h>
#endif
#ifndef P_OBJECT_H
#include <p_object.h>
#endif
#ifndef P_FILE_H
#include <p_file.h>
#endif
#define G_GC_MASK_GMODE         0x2
#define G_GC_MASK_TEXTMODE      0x4
#define G_GC_MASK_STYLE         0x8
#define G_GC_MASK_FONT          0x10
#define G_GC_MASK_GREY          0x20
#define G_GC_MASK_DOUBLE        0x40

#define G_GC_FLAG_GREY_PLANE    0x1
#define G_GC_FLAG_BOTH_PLANES   0x2
#define G_GC_FLAG_DOUBLE        0x4

#define G_TEXT_ALIGN_RIGHT 1
#define G_TEXT_ALIGN_LEFT 2 
#define G_TEXT_ALIGN_CENTRE 4
#define G_FONT_FLAG_ASCII 0x01
#define G_FONT_FLAG_CP850 0x02
#define G_FONT_FLAG_BOLD 0x04
#define G_FONT_FLAG_ITALIC 0x08
#define G_FONT_FLAG_SERIF 0x10
#define G_FONT_FLAG_MONO 0x20
#define G_FONT_FLAG_HANG 0x40    /* Has over/under hang table */
#define G_FONT_SPECIAL_1 0x8000 /* Font is stored in Special format 1 */ 
#define G_TRMODE_SET 0
#define G_TRMODE_CLR 1 
#define G_TRMODE_INV 2
#define MAX_GMODE 2 /* max trmode allowed in the gmode of a gc */ 
#define G_TRMODE_REPL 4
#define MAX_BLITMODE 5 /* .. .. in a blit-type command */ 
#define MAX_TEXTMODE 5 /* .. .. in the textmode of a gc */ 
#define G_STY_NORMAL 0
#define G_STY_BOLD 0x01
#define G_STY_UNDERLINE 0x02
#define G_STY_INVERSE 0x04
#define G_STY_DOUBLE 0x08
#define G_STY_MONO 0x10
#define G_STY_ITALIC 0x20
#define G_STY_SUBSCRIPT2 0x40
#define G_STY_SUPERSCRIPT2 0x80
#define G_STY_SUBSCRIPT 0x100
#define G_STY_SUPERSCRIPT 0x200
#define G_XP_INV_BLOCK 0x01
#define G_XP_INV_OBLOID 0x02
#define G_XP_UND_BLOCK 0x04
#define G_XP_REDUCED 0x08
#define W_BORD_CORNER_2 0x00
#define W_BORD_CUSHION 0x01
#define W_BORD_CORNER_4 0x02
#define W_BORD_SHADOW_S 0x04
#define W_BORD_SHADOW_D 0x08
#define W_BORD_SHADOW_ON 0x10
#define W_BORD_OPEN 0x20
#define W_BORD_CORNER_1 0x40
#define W_BORD_TOP_OFF 0x80
#define W_BORD_BOT_OFF 0x100
#define W_BORD_TOP_ON 0x200
#define W_BORD_BOT_ON 0x400
#define X_BORD_SHADOW_BOX 0x8000
#define W_BORDER_TYPE_0 0
#define W_BORDER_TYPE_1 1
#define X_BORDER_TYPE_MAX 1
#define G_DRAW_OBJECT_TYPE_0 0
#define X_DRAW_OBJECT_TYPE_MAX 0
#define G_APPEND 0x01
#define G_DISPLAY 0x02
#define W_CTBY_S3   0x0001
#define X_CTBY_SCR_SIZE 0x0002
#define W_CTBY_S3_SCR   (X_CTBY_S3|X_CTBY_SCR_SIZE)
#define W_SUPPORT_GREY      0x01
#define W_SUPPORT_CTBY_S3   0x02
typedef struct
 {
 unsigned int flags;
 unsigned int fillers[15];
 } W_SUPPORT_INFO;
#define WS_MAX_CLIENTS 21 /* Includes rubber band client */ 
#define FONT_NAME_LEN 16
#define FONT_MAX_HEADER_LEN 128
typedef struct
 {
 unsigned short int low_ch; /* lowest code in font */ 
 unsigned short int high_ch; /* highest code in font */ 
 unsigned short int height; /* height of font */ 
 unsigned short int descent; /* height of bottom part of character */ 
 unsigned short int ascent; /* height of top part of character */ 
 unsigned short int numeric_width; /* Width of numeric character */ 
 unsigned short int max_width; /* The width of the widest character in the font */ 
 unsigned short int flags;
 char name[FONT_NAME_LEN];
 } G_FONT_INFO;
#define WS_FONT_SYSTEM 0x4099
#define WS_DEFAULT_ICON (WS_BITMAP_BASE+8)
typedef struct
 {
 unsigned short int keycode; /* Code for the key pressed */ 
 unsigned char modifiers; /* A bit set for each modifier key held down */ 
 unsigned char count;
 } WMSG_KEY;
typedef struct
 {
 unsigned short int unused;
 unsigned char modifiers; /* A bit set for each modifier key held down */ 
 unsigned char filler;
 } WMSG_CAPS;
typedef struct
 {
 unsigned char event;
 unsigned char state;
 P_POINT pos;
 } WMSG_MOUSE;
typedef struct
 {
 unsigned short int state;
 P_EXTENT extent;
 } WMSG_RUBBER;
typedef union
 {
 unsigned short int uword;
 unsigned char *dpoint; /* Data pointer */ 
 P_RECT rect;
 WMSG_KEY key;
 WMSG_MOUSE mouse;
 WMSG_RUBBER rubber;
 WMSG_CAPS caps;
 } WS_EVENT_UNION;
typedef struct
 {
 unsigned short int handle; /* Destination handle */ 
 unsigned short int time;
 WS_EVENT_UNION u;
 } WS_EVENT_X;
typedef struct
 {
 short int type; /* E_FILE_PENDING,or -ve error,or +ve good event type */ 
 WS_EVENT_X x;
 } WS_EVENT;
typedef struct /* The WS_EV struct runs in parallel to the WS_EVENT struct */ 
 { /* but is in a simplified form without the WS_EVENT_X */ 
 /* sub structure */
 short int type;
 unsigned short int handle;
 unsigned short int time;
 WS_EVENT_UNION p;
 } WS_EV;
#define MAX_CLIENT_TO_WSERV_BUFFER 300
#define MAX_WSERV_TO_CLIENT_BUFFER 300
#define W_INFO_MSG_MAX_LEN 64
#define W_BUSY_MSG_MAX_LEN 20
#define W_DRAW_BUTTON_MAX_LEN 64
#define W_ALERT_TEXT_MAX_LEN 80
#define W_PASSWORD_ALERT_TEXT_MAX_LEN 128
#define W_BUTTON_TYPE_1 0
#define W_BUTTON_TYPE_2 1
typedef struct
 {
 unsigned char gmode; /* transfer mode */ 
 unsigned char textmode; /* transfer mode for writing text */ 
 unsigned char style; /* style of text : bold,underline etc. */ 
 unsigned char flags;
 unsigned short int font; /* handle of curr font in use */ 
 } G_GC;
typedef struct
 {
 P_EXTENT start; /* Current dimension */ 
 P_EXTENT outer; /* Outer bounding rectangle */ 
 P_EXTENT inner; /* Inner bounding rectangle */ 
 unsigned short int flags; /* TRUE if the rubber band is resizable */ 
 unsigned short int minx; /* Max and Min limits only used if resize is TRUE */ 
 unsigned short int miny;
 unsigned short int maxx;
 unsigned short int maxy;
 P_POINT grid_snap;
 } W_RUBBER_BAND;
typedef struct
 {
 unsigned short int flags; /* see below */ 
 P_EXTENT extent; /* position and size relative to parent */ 
 short int mouse_icon; /* handle of mouse icon */ 
 unsigned char background; /* Auto clear to black,white or none on redraws */ 
 unsigned char filler;
 } W_WINDATA;
typedef struct
 {
 P_POINT pos; /* position within window */ 
 unsigned char height;
 char ascent;
 unsigned char width;
 unsigned char flags;
 } W_CURSOR;
#define W_CURSOR_OBLOID 0x01
#define W_CURSOR_NO_FLASH 0x02
#define W_CURSOR_GREY 0x04
typedef struct
 {
 short int bitmap;
 P_POINT pos;
 P_RECT rect;
 unsigned short int mode;
 unsigned long int time;
 } WS_WIN_BITMAP;
#define WS_WIN_BITMAP_GREY 0x8000
typedef struct
 {
 short int bit_set;
 short int bit_clr;
 short int bit_inv;
 short int bit_gr_set;
 short int bit_gr_clr;
 short int bit_gr_inv;
 P_POINT offset;
 unsigned short int time;
 } W_SPRITE;
#define MAX_SET_SPRITE 13
#define W_SPRITE_CLIP_CHILDREN 0x0001
typedef struct
 {
 short int id;        /* Window id */
 short int type;      /* Clock type */
 P_POINT pos;
 short int offset;     /* Time offset */
 short int flags;      /* Clock flags */
 short int font;
 short int style;
 } WS_CREATE_CLOCK;
typedef struct
 {
 short int FontId;
 unsigned char Styles;
 unsigned char FontStyles;
 short int BaseOffset;
 } G_FONT_CONFIG;
typedef struct
 {
 unsigned char BodyColour;
 unsigned char ShadowColour;
 unsigned char LightColour;
 unsigned char filler;
 unsigned short int Flags;
 short int ShadowSizeX;
 short int ShadowSizeY;
 short int LightSizeX;
 short int LightSizeY;
 short int Spacing;
 } G_SHADOW;
#define G_COLOUR_BLACK 0
#define G_COLOUR_WHITE 1
#define G_COLOUR_GREY  2
#define G_COLOUR_NONE  3
#define G_COLOUR_DARK_GREY 4
#define G_COLOUR_LIGHT_GREY 5
#define G_COLOUR_MAX   5
#define G_SHADOW_SOLID      0x01
#define G_SHADOW_CORNER_1   W_BORD_CORNER_1
#define G_SHADOW_CORNER_4   W_BORD_CORNER_4
#define WE_KEY     0x0001
#define WE_REDRAW  0x0002
#define WE_STATUS  0x0004
#define WE_MOUSE   0x0008
#define WE_OTHERS  0x0010
#define WE_ESC     0x8000
#define WE_NORMAL  0x0FFF
#define WSIPC_LINK_PASTE 0x0004
#define WSIPC_LINK_SERVER 0x0003
#define WSIPC_CLIENT_TO_SERVER 0x0100
#define WSIPC_OS_CLIENT_DIED 0x0200
#define WSIPC_NOTIFY 0x0300
#define WSIPC_ALERT 0x0400
#define WSIPC_WATCHALL 0x0500
#define IPC_HEAD_FLAG_REPORT_ERRORS 0x0100
#define IPC_HEAD_FLAG_READ_FLAGS 0x0200
typedef struct
 {
 unsigned char *data;
 unsigned char word_len;
 unsigned char flags;
 WS_EVENT *read;
 union
  {
  unsigned int read_flags; /* What sort of events to read */
  unsigned char *reply;   /* Optional address for reply buffers */
  }r;
 }IPC_HEAD;
typedef struct
 {
 P_POINT pixels; /* Display size */ 
 unsigned short int width_1000_pixels_mm;
 unsigned short int height_1000_pixels_mm;
 unsigned char set_is_dark;
 unsigned char version_id;
 unsigned short int system_font_handle;
 unsigned short int flags;
 unsigned short int dummy;
 } W_SERVER_INFO;
#define W_SERVER_INFO_FLAG_GREY1    0x0001
typedef struct
 {
 unsigned short int client_handle; /* S_CCB table index */ 
 W_SERVER_INFO info;
 } CONNECT_INFO;
typedef struct
 {
 int (*write)(struct _WSERV_SPEC *,short int *,WS_EV *,unsigned int,unsigned int);
 void (*close)(struct _WSERV_SPEC *);
 void (*init_transmit)(struct _WSERV_SPEC *);
 void (*panic)(struct _WSERV_SPEC *,unsigned int);
 } CLINK_REDIRECTOR;
typedef struct
 {
 /* The following symbols are only used in debug mode but have been left
 in as they be useful for future expansion */
 unsigned char *log;
 char *par_file;
 void (*cpanic_handler)(int);
 /**/
 unsigned short int usage_count;
 unsigned char *p_commands;
 unsigned char *p_end; /* End is not always the end of the buffer,this is because
 the limit may be constrained by the receiveing end */ 
 union
	{
	struct
	 {
	 unsigned char commands[1];
	 } local;
	struct
	 {
	 unsigned char commands[1];
	 } metafile;
	unsigned char buf[MAX_CLIENT_TO_WSERV_BUFFER];
	} msg;
 } WSERV_CLIENT_DATA;
typedef struct _WSERV_SPEC /* WSERV_SPEC */ 
 {
 unsigned short int handle_check;
 CONNECT_INFO conn;
 char error;
 unsigned char leaves_disabled;
 unsigned short int cpanic;
 CLINK_REDIRECTOR redirector; /* magic cookie - switches between :- */ 
 /* 1) IPC to WSERV,*/
 /* 2) metafile code,*/
 /* 3) and p_io() */
 union /* link :- link specific parts */ 
	{
	struct /* local link */ 
	 {
	 unsigned short int wserv_pid;
	 IPC_HEAD ipc_head;
	 } local;
	struct /* metafile recording */ 
	 { 
	 unsigned char *io_channel; /* p_io() - to link-layer-like device */ 
	 struct _WSERV_SPEC * display; /* if display while recording: */ 
	 /* else NULL */
	 unsigned char *transmit_start;
	 } metafile;
	} link;
 unsigned short int os_ds; /* Operating system DS */ 
 } WSERV_SPEC;
typedef struct
 {
 P_POINT size;
 char seg_name[14];
 } W_OPEN_BIT_SEG;
typedef struct
 {
 UWORD checksum;
 P_POINT size;
 UWORD byte_size;
 ULONG offset;
 }WS_PIC_HEADER;
typedef struct
 {
 P_FSIG sig;
 UWORD count;
 WS_PIC_HEADER wspic;
 } PIC_HEAD;
/* Flags used in field set and the flag field in the window structure */
#define W_WIN_INPUT_ONLY 0x01
#define W_WIN_RUBBER_BAND_CAPTURE 0x02
#define W_WIN_INACTIVE 0x04
#define W_WIN_MOUSE_MOVE 0x08
#define W_WIN_MOUSE_DRAG 0x10
#define W_WIN_MOUSE_GRAB 0x20
#define W_WIN_DOUBLE_PIXEL 0x40
#define W_WIN_FOREGROUND_ONLY 0x80
#define W_WIN_PRIORITY 0x100
#define W_WIN_NO_REDRAW 0x200
#define W_WIN_NO_MOUSE 0x400
#define W_WIN_RUBBER_BAND_COMPLETE_ON_RELEASE 0x800
#define W_WIN_ALL_FLAGS 0xfff
/* Flags used in field set only */
#define W_WIN_EXTENT 0x1000
#define W_WIN_MOUSE_ICON 0x2000
#define W_WIN_BACKGROUND 0x4000
#define W_STATUS_HIDDEN 0x8000 /* Used internally to mark window as hidden */ 
/* Status flags */
#define W_UNINITIALISED 0x80
#define W_REDRAW 0x40
#define W_BACKGROUND 0x20 /* Window is invisible because it is background */ 
#define W_SET_INVISIBLE 0x10 /* Window is set to invisible by client */ 
#define W_XXXXXXX 0x08
#define W_INVALID 0x04 /* The whole window contents is invalid */ 

#define X_WIN_BACK_NO_REDRAW        0x08    /* Private */
#define X_WIN_BACK_GREY_REDRAW      0x80    /* Private */
#define W_WIN_BACK_NONE             0x00
#define W_WIN_BACK_CLR              0x01
#define W_WIN_BACK_SET              0x02
#define W_WIN_BACK_BITMAP           0x03
#define W_WIN_BACK_NONE_NO_REDRAW   (00+X_WIN_BACK_NO_REDRAW)
#define W_WIN_BACK_CLR_NO_REDRAW    (01+X_WIN_BACK_NO_REDRAW)
#define W_WIN_BACK_SET_NO_REDRAW    (02+X_WIN_BACK_NO_REDRAW)
#define W_WIN_BACK_GREY_CLR         (00+X_WIN_BACK_GREY_REDRAW)
#define W_WIN_BACK_GREY_NONE        (16+X_WIN_BACK_GREY_REDRAW)
#define W_WIN_BACK_GREY_SET         (32+X_WIN_BACK_GREY_REDRAW)
#define W_WIN_BACK_GREY_BITMAP      (48+X_WIN_BACK_GREY_REDRAW)
#define W_WIN_BACK_GREY_CLR_NO_REDRAW   0x00
#define W_WIN_BACK_GREY_NONE_NO_REDRAW  0x10
#define W_WIN_BACK_GREY_SET_NO_REDRAW   0x20
#define W_VER_DOUBLE_BITS   0x0001
#define X_CORNER_BOTTOM 0x40
#define X_CORNER_RIGHT 0x80
#define W_CORNER_TOP_LEFT 0x00
#define W_CORNER_TOP_RIGHT X_CORNER_RIGHT
#define W_CORNER_BOTTOM_LEFT X_CORNER_BOTTOM
#define W_CORNER_BOTTOM_RIGHT (X_CORNER_RIGHT+X_CORNER_BOTTOM)
#define WSERV_FLAG_NO_SHELL_REBOOT 0x0001
#define WSERV_FLAG_NO_NOTIFIER_REBOOT 0x0002
#define WSERV_FLAG_NO_PANIC_NOTIFYS 0x0004
#define WSERV_FLAG_HOOK_NOTIFIER 0x0008
#define WSERV_FLAG_UPDATE_MSGS 0x0010
#define WSERV_FLAG_LOW_BATTERY_WARNINGS 0x0020
#define WSERV_FLAG_HUNG_UP_SW 0x0040
#define WSERV_FLAG_SW_NO_LOW_BATTERY  0x0080
#define WSERV_FLAG_SW_NO_PACKS        0x0100
#define WSERV_FLAG_SW_NO_LINK         0x0200
#define WSERV_FLAG_SW_NO_CAPS         0x0400
#define WSERV_FLAG_TOP_BIT 0x8000 /* Can not be set */ 
#define W_CONNECT_AT_BACK 0x01
#define W_CONNECT_CONNECTED 0x01 /* Only used in replys to wClientInfo() */ 
#define W_CONNECT_USER_FLAG 0x02
#define W_CONNECT_SYSTEM_MODAL 0x04
#define W_CONNECT_PRIORITY 0x40
#define W_CONNECT_DISABLE_LEAVES 0x80
#define WS_TEMPORARY_GC 1
#define WS_BIT_WRITE 0x01
#define WS_BIT_SEG 0x02
#define WS_BIT_SEG_NAME 0x04
#define WS_BIT_SEG_ACCESS (WS_BIT_SEG|WS_BIT_SEG_NAME)
#define WS_BIT_SEG_ZERO_SIZE 0x08
#define WS_BIT_MASK (WS_BIT_WRITE+WS_BIT_SEG+WS_BIT_SEG_NAME+WS_BIT_SEG_ZERO_SIZE)
#define WS_BIT_ROM 0x80
#define WS_BIT_FILE 0x100
#define WX_BIT_GREY 0x8000  /* secret do not use */
#define WS_CLOCK_SMALL_DIGITAL 0x00
#define WS_CLOCK_MEDIUM 0x01
#define WS_CLOCK_LARGE_ANALOG 0x02
#define WS_CLOCK_MEDIUM2 0x03
#define WS_CLOCK_XL_ANALOG 0x04
#define WS_CLOCK_FORMATTED 0x05
#define WS_CLOCK_MAX 0x06
#define WS_CLOCK_VINE            0x06
#define WS_CLOCK_MAX_VINE        0x07   /* Last clock type on vine plus 1 */
#define WS_CLOCK_MEDIUM3         0x06
#define WS_CLOCK_XL2_ANALOG      0x07
#define WS_CLOCK_MAX_OAK         0x08   /* Last clock type on oak plus 1 */
#define CLOCK_FLAG_COLON_OFFSET 0x04
#define CLOCK_FLAG_DIGITAL 0x08
#define CLOCK_FLAG_WSRV 0x04
#define CLOCK_FLAG_XXXX 0x08
#define WS_CLOCK_WITH_DATE 0x10
#define WS_CLOCK_WITH_SECONDS 0x20
#define WS_CLOCK_FORCE_ANALOG 0x40
#define WS_CLOCK_FORCE_DIGITAL 0x80
#define WS_CLOCK_AM_PM 0x100
#define WS_CLOCK_AM_PM_BUT_NOT_IN_MEDIUM_ANALOG 0x400
#define WS_CLOCK_CENTRED 0x200
#define WS_CLOCK_WITH_DATE_EXTRA 0x400
#define WS_CLOCK_GREY 0x800
#define WS_CLOCK_DBL_PLANE 0x1000
#define WS_CLOCK_RIGHT_ALIGN 0x2000
#define WS_CLOCK_SUMMER_TIME 0x4000
#define WS_CLOCK_BOX 0x8000
#define OLD_CLOCK_FLAGS 0xFFF0
#define WS_BITMAP_CLOCK_SIZE_X 36
#define WS_BITMAP_CLOCK_SIZE_Y 32
#define WS_BITMAP_LARGE_CLOCK_SIZE_X 66
#define WS_BITMAP_LARGE_CLOCK_SIZE_Y 60
#define WS_BITMAP_XL_CLOCK_SIZE_X 99
#define WS_BITMAP_XL_CLOCK_SIZE_Y 99
#define WS_BITMAP_MEDIUM2_CLOCK_SIZE_X 58
#define WS_BITMAP_MEDIUM2_CLOCK_SIZE_Y 51
#define WS_LEFT_POS_CONS 189
#define WS_LEFT_POS_CORP 109
#define WS_TOP_POS 0
#define WS_WIDTH 51
#define WS_HEIGHT 80
#define WS_WIDTH_V4 64
#define WS_WIDTH_SMALL_V4 32
#define WS_WIDTH_V4C            51
#define WS_WIDTH_SMALL_V4C      32
#define WS_WIDTH_VINE           36  /* Same number as small but different width on vine */
/* Basic WSERV-to-client message types
*/
#define WM_KEY 1
#define WM_MOUSE 2
#define WM_REDRAW 3
#define WM_BACKGROUND 5
#define WM_FOREGROUND 6
#define WM_RUBBER 7
#define WM_USER_MSG 8
#define WM_ACTIVE 9
#define WM_CANCELLED 11
#define WM_KEYBOARD_STATE_CHANGE 12
#define WM_RUBBER_BAND_INIT 13
#define WM_DEICONISE 14
#define WM_ATTACHED 15
#define WM_DETACHED 16
#define WM_COMMAND 17
#define WM_TASK_KEY 18
#define WM_TASK_UPDATE 19
#define WM_ON 20
#define WM_ESCAPE 21
#define WM_DATE_CHANGED 22
#define WM_MAX_WSERV 23
#define WM_NULL_EVENT 24
#define WS_BITMAP_GREY 0x4000
#define WS_BITMAP_GREY_SIZE_X 192
#define WS_BITMAP_GREY_SIZE_Y 16
#define WS_BITMAP_BASE 0x4001
#define WS_FONT_BASE 0x4000
#define WS_FONT_BASE2 0x6000
#define WS_MI_BASE 0x4002
#define WS_LAST_CLIENT_POSITION 100
/* system mouse icon handles */
#define W_WIN_MI_STANDARD 0x4000 /* index 0 + Base 0x4000 */ 
#define W_WIN_MI_NULL 0x4001 /* index 1 + Base 0x4000 */ 
#define WM_MOUSE_RELEASE 1
#define WM_MOUSE_PRESS 2
#define WM_MOUSE_MOVE 3
#define P_MAX_COORD 0x7fff
#define WS_MAX_PRINT_TEXT_LEN 246
#define WS_MAX_PRINT_CLIP_TEXT_LEN 244
#define WS_MAX_PRINT_BOX_TEXT_LEN 236
#define WS_MAX_XPRINT_TEXT_LEN 244
#define WS_MAX_SHADOW_TEXT_LEN 234
#define WS_MAX_FORMATTED_CLOCK 238
#define W_MAX_FONT_CONFIG 24
#define WM_BAND_NOMOVE 0
#define WM_BAND_MOVE 1
#define WM_BAND_RESIZE 2
#define WM_BAND_CANCEL 3
#define WM_BAND_ERROR 4
#define W_BAND_RESIZE 0x01
#define W_BAND_INNER 0x02
#define W_BAND_OUTER 0x04
#define W_BAND_START 0x08
#define W_BAND_COMPLETE_ON_UP 0x10
#define W_BAND_KILL_CAPTURE 0x20
#define W_BAND_GRID_SNAP_SIZE 0x40
#define W_XXXX_GRID_SNAP_POS 0x80 /* Secret internal #define */ 
#define W_BAND_GRID_SNAP (W_XXXX_GRID_SNAP_POS|W_BAND_GRID_SNAP_SIZE)
#define WS_TYPE_MASK 0xF0
#define WS_VERSION_MASK 0x0F
#define WS_TYPE_MC 0x00
#define WS_TYPE_S3 0x10
#define WS_TYPE_HC 0x20
#define WS_TYPE_MCA 0x30
#define WS_TYPE_S3A 0x40
#define WS_TYPE_HCA 0x50
#define WS_TYPE_S3C 0x60
#define WS_TYPE_VINE 0x70
#define WS_VERSION_2 0x00
#define WS_VERSION_3 0x01
#define WS_VERSION_3_5 0x02
#define WS_VERSION_4 0x02
/* The alert type is made of a base value one of ...*/
#define WS_ALERT_CLIENT 0x00
#define WS_ALERT_TIMED 0x01
#define WS_ALERT_CANCEL 0x08
/* ...with one or none of the following flags or'ed in */
#define WS_ALERT_PERMANENT 0x02
#define WS_ALERT_UPDATE 0x04 /* Wserv internal use only */ 
#define WS_ALERT_B 0x10
#define WS_UPDATE_NAME 0x01
#define WS_UPDATE_CLOCK 0x02
#define WSERV_PANIC_FIRST 81
#define WSERV_PANIC_LAST 116
#define W_STATUS_WINDOW_OFF 0
#define W_STATUS_WINDOW_SMALL 1
#define W_STATUS_WINDOW_BIG 2
#define W_STATUS_WINDOW_CTBY 3
#define W_STATUS_WINDOW_MAX W_STATUS_WINDOW_CTBY
#define W_STATUS_WIN_NO_DIAMOND -1
#define W_STATUS_WINDOW_ICON -1
typedef struct
 {
 unsigned char hposition;
 unsigned char length;
 unsigned short int offset;
 } DESC;
typedef struct
 {
 unsigned char zero;
 unsigned char filler;
 DESC desc[3];
 } WS_ALERT_DESC;
#define G_OPEN_MODE_NORMAL 0
#define G_OPEN_MODE_OFFSET 1
#define G_OPEN_MODE_LONG_PTR_OFFSET 2
#define G_OPEN_MODE_WORD_PTR_OFFSET 3
#define MAX_G_OPEN_MODE 3
#define W_SYSTEM_FONT_S3B 0
#define W_SYSTEM_FONT_S3 1
#define W_SYSTEM_FONT_INTERNAL_S3B 2
#define W_SYSTEM_FONT_INTERNAL_S3 3
#ifdef __cplusplus
extern "C" {
#endif
#pragma save
extern void cdecl wsAlertA(int,short int *,const char *,const char *,...);
extern int cdecl wsAlertUpdate(const char *,const char *,...);
extern int cdecl wsAlertW(int,const char *,const char *,...);
extern int cdecl wAllDump(char *,unsigned int);
#pragma call(reg_param =>(bx,cx,dx,si),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int gOpenBit(const char *,unsigned int,unsigned int,void *);
extern int gGetBit(unsigned int,unsigned int,unsigned int,void *);
extern int gPeekBit(unsigned int,const P_POINT *,unsigned int,void *);
#pragma call(reg_param =>(bx,cx,si),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int gReadFontHeader(const char *name,int index,unsigned char *buf);
extern int wInquireWindowOffset(unsigned int,unsigned int,P_POINT *);
extern int gQueryBit(int,int,P_POINT *);
#pragma call(reg_param =>(bx,si),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int gReadFontGroupHeader(const char *name,unsigned char *buf);
extern int wInquireWindow(unsigned int,W_WINDATA *);
extern int wInquireStatusWindow(int state,P_EXTENT *ext);
extern void wCompatibilityMode(unsigned int flags,WSERV_SPEC *wSpec);
extern int  gInitBit(const char *,int *);
extern void gInquireChecksum(int id,unsigned short int *checksum);
#pragma call(reg_param =>(bx,si,ax,cx,dx,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void gPrintBoxText(const P_RECT *,unsigned int,unsigned int,unsigned int,const char *,unsigned int);
#pragma call(reg_param =>(dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int gPlayBack(void *);
extern unsigned int wDisableLeaves(unsigned int);
extern void wGetEventWait(WS_EV *);
extern void wGetEventUpdate(unsigned int);
extern void wPanic(unsigned int);
extern void wSelect(WSERV_SPEC *);
extern int gCheckBitmapID(unsigned int);
#pragma call(reg_param =>(dx,cx,di),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int gFontInfo(unsigned int,unsigned int,G_FONT_INFO *);
extern void wGetEventSpecial(WS_EV *,unsigned int);
#pragma call(reg_param =>(dx,si,di,cx,ax),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int gTextWidth(unsigned int,unsigned int,const char *,unsigned int);
extern int gTextCount(unsigned int,unsigned int,const char *,unsigned int,unsigned int *);
extern int gGetWidthTable(unsigned int,unsigned int,unsigned char *);
#pragma call(reg_param =>(di,cx,dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void gRecordToMetaFile(WSERV_SPEC *,void *,unsigned int);
#pragma call(reg_param =>(bx,cx,dx,di,si),reg_saved =>(bx,cx,si,di,EPOC_SAVE))
extern void wBeginRedrawGC0(unsigned int,const P_RECT *);
#pragma call(reg_param =>(bx,cx,dx,di,si),reg_saved =>(bx,dx,si,di,EPOC_SAVE))
extern int gCreateGC0(unsigned int);
extern void gCreateTempGC0(unsigned int);
extern void gSetGC0(unsigned int);
extern void wBeginRedrawWinGC0(unsigned int);
#pragma call(reg_param =>(si),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern int wGetCommand(unsigned char *);
extern void wGetProcessList(unsigned short int *);
extern void wSupportInfo(W_SUPPORT_INFO *);
#pragma call(reg_param =>(bx,cx,dx,di,si),reg_saved =>(cx,dx,si,di,EPOC_SAVE))
extern int wCancelBusyMsg(void);
#pragma call(reg_param =>(bx,cx,dx,di,si),reg_saved =>(si,di,EPOC_SAVE))
extern void wStartup(void);
#pragma call(reg_param =>(bx,cx,dx,di,si),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void wsScreenExt(P_EXTENT *);
extern void gClrRect(const P_RECT *,unsigned short int);
extern int gCloseMetaFile(void);
extern void gCopyBit(const P_POINT *,unsigned int,const P_RECT *,unsigned int);
extern int gDrawBit(const P_POINT *,int,const P_RECT *,int,int);
extern void gCopyRect(const P_RECT *,const P_POINT *,int);
extern int gCreateGC(unsigned int,unsigned int,G_GC *);
extern void gCreateTempGC(unsigned int,unsigned int,G_GC *);
extern void gDrawLine(int,int,int,int);
extern void gDrawPolyLine(int,int,short int *);
extern void gFreeTempGC(void);
extern void gInvObloid(P_EXTENT *);
extern int gOpenFont(const char *);
extern int gOpenFontIndex(const char *,unsigned int);
extern int gOpenMouseIcon(const char *,unsigned int);
extern unsigned int gPrintClipText(int,int,const char *,int,int);
extern void gPrintText(int,int,const char *,int);
extern int gCreateBit(unsigned int,void *);
extern int gSaveBit(const char *,unsigned int);
extern int gSaveRect(const char *,unsigned int,const P_RECT *);
extern int gInitMultiSave(const char *,int);
extern int gSaveMultiBit(int,int);
extern int gSaveMultiRect(int,int,const P_RECT *);
extern int gEndMultiSave(int);
extern void gSetGC(unsigned int,unsigned int,G_GC *);
extern void gXPrintText(int,int,const char *,unsigned int,unsigned int);
extern int wAttachToClient(unsigned int);
extern void wAttachToForegroundClient(void);
extern void wBeginRedraw(unsigned int,const P_RECT *);
extern void wBeginRedrawGC(unsigned int,const P_RECT *,unsigned int,G_GC *);
extern void wBeginRedrawWin(unsigned int);
extern void wBeginRedrawWinGC(unsigned int,unsigned int,G_GC *);
extern void wCallDYL(unsigned int,unsigned int,unsigned int,void *);
extern int wCallDYLReply(unsigned int,unsigned int,unsigned int,void *,void *);
extern int wCancelCaptureKey(unsigned int,unsigned int,unsigned int);
extern void wCancelGetEvent(void);
extern void wCancelSystemModal(unsigned int);
extern int wCaptureKey(unsigned int,unsigned int,unsigned int);
extern int wSetTaskKey(unsigned int,unsigned int,unsigned int);
extern int wSetBackTaskKey(unsigned int,unsigned int,unsigned int);
extern int wCancelTaskKey(unsigned int,unsigned int,unsigned int);
extern int wCancelBackTaskKey(unsigned int,unsigned int,unsigned int);
extern void wCaptureMouse(unsigned int);
extern void wChangeWinBitmap(unsigned int,unsigned int,WS_WIN_BITMAP *);
extern void wClientIconised(unsigned int);
extern unsigned int wClientInfo(unsigned int);
extern void wClientPosition(unsigned int,unsigned int);
extern void wCloseDown(void);
extern int wCreateWindow(unsigned int,unsigned int,W_WINDATA *,unsigned short int);
extern void wDetachClient(void);
extern void wDisablePauseKey(void);
extern void wAppKeyHandler(void);
extern void wDrawTextCursor(unsigned int,W_CURSOR *);
extern void wTextCursor(unsigned int,W_CURSOR *);
extern void wEnablePauseKey(void);
extern void wEndCompute(void);
extern void wEraseTextCursor(void);
extern void wEscapeOff(void);
extern void wEscapeOn(void);
extern void wFree(unsigned int);
extern unsigned int wGetWindowPosition(unsigned int);
extern void wInvalidateRect(unsigned int,const P_RECT *);
extern int wSetWinBitmap(unsigned int,unsigned int,WS_WIN_BITMAP *);
extern int wSetPriorityControl(unsigned int flag);
extern int gConfigureFonts(int count,G_FONT_CONFIG *cfg);
extern int wSetSystemFont(int type,int font,unsigned int style);
extern int wCreateSprite(int winId,const P_POINT *pos,int flags,int count,W_SPRITE *sprite);
extern int wSetSprite(int id,const P_POINT *pos,int index,W_SPRITE *);
extern int wsSetList(int count,char **list,int pos);
extern void wsSelectList(int move);
extern void gShadowText(int,int,G_SHADOW *,const char *,int);
extern void gDrawObject(int type,const P_RECT *,int flags);
extern void gBorder2Rect(int type,const P_RECT *,int flags);
extern void gBorder2(int type,int flags);
extern int gCreateFontHeader(G_FONT_INFO *info,char *SegName);
extern void wInformInactivity(void);
extern void wDisableKeyClick(int);
extern int wLoadDYL(const char *);
extern void wReassignRootWindow(unsigned int);
extern void wReleaseMouse(void);
extern void wRubberBand(unsigned int,unsigned int,W_RUBBER_BAND *);
extern void wScrollRect(unsigned int,const P_RECT *,const P_POINT *);
extern void wScrollWin(unsigned int,const P_POINT *);
extern int wsCreateClock(unsigned int,unsigned int,int,int,int);
extern int wsCreateClock2(WS_CREATE_CLOCK *,char *);
extern void wsDisable(void);
extern void wsDisableTemp(void);
extern void wsEnable(void);
extern void wsEnableTemp(void);
extern void wStatusWindow(int);
extern void wsSetClock(unsigned int,int);
extern void wSetWindow(unsigned int,unsigned int,W_WINDATA *);
extern int wSetBusyMsg(const char *,unsigned int);
extern void wStartCompute(void);
extern void wsUpdate(unsigned int);
extern void wInformOn(void);
extern void wInformOnAll(unsigned int);
extern int wSystem(unsigned int,unsigned int);
extern void wSystemModal(unsigned int);
extern void wUserMsg(void);
extern void wValidateRect(unsigned int,const P_RECT *);
extern int wInfoMsg(const char *);
extern int wInfoMsgCorner(const char *,unsigned int);
extern void gSetOpenAddress(unsigned int,unsigned long int);
extern void wDrawButton(const P_RECT *,const char *,unsigned int);
extern void wDrawButton2(int,const P_RECT *,const char *,unsigned int);
extern unsigned int wInquireCompatibility(void);
extern int wSendCommand(unsigned short int,unsigned char *,unsigned short int);
#pragma call(reg_param =>(si,di,cx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void wConnect(WSERV_SPEC *,unsigned int,unsigned int);
#pragma call(reg_param =>(dx),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void wGetEvent(WS_EV *);
#pragma call(reg_param =>(bx,cx,dx,di,si),reg_saved =>(bx,cx,dx,si,di,EPOC_SAVE))
extern void gBorder(unsigned int);
extern void gBorderRect(const P_RECT *,unsigned int);
extern void gDrawBox(const P_RECT *);
extern void gFillPattern(const P_RECT *,unsigned int,unsigned int);
extern void wsAlertCancel(void);
extern int wCheckPoint(void);
extern void wCleanUp(void);
extern void wCloseWindowTree(unsigned int);
extern void wDisconnect(void);
extern void wEndRedraw(void);
extern void wFlush(void);
extern void wInitialiseWindowTree(unsigned int);
extern void wInvalidateWin(unsigned int);
extern void wMakeInvisible(unsigned int);
extern void wMakeVisible(unsigned int);
extern void wValidateWin(unsigned int);
extern void wWindowPosition(unsigned int,unsigned int);
#pragma restore
#ifdef __cplusplus
}
#endif

