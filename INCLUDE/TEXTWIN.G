/* Generated by Ctran from textwin.cl */
#define TEXTWIN_G
#ifndef LODGER_G
#include <lodger.g>
#endif
#ifndef EDIT_G
#include <edit.g>
#endif
/* Class Numbers */
#define C_TEXTWIN 4
/* Method Numbers */
/* Constants for textwin */
#define PR_TEXTWIN_AL_LEFT 0x00
#define PR_TEXTWIN_AL_RIGHT 0x01
#define PR_TEXTWIN_AL_CENTRE 0x02
#define PR_TEXTWIN_BOLD 0x04
#define PR_TEXTWIN_BULLET 0x20
#define PR_TEXTWIN_POPOUT 0x40
#define PR_TEXTWIN_FLASHING 0x80
#define IN_TEXTWIN_AL_LEFT PR_TEXTWIN_AL_LEFT
#define IN_TEXTWIN_AL_RIGHT PR_TEXTWIN_AL_RIGHT
#define IN_TEXTWIN_AL_CENTRE PR_TEXTWIN_AL_CENTRE
#define IN_TEXTWIN_BOLD PR_TEXTWIN_BOLD
#define IN_TEXTWIN_BULLET PR_TEXTWIN_BULLET
#define IN_TEXTWIN_POPOUT PR_TEXTWIN_POPOUT
#define SE_TEXTWIN_ALIGN (PR_TEXTWIN_AL_RIGHT|PR_TEXTWIN_AL_CENTRE)
#define SE_TEXTWIN_BOLD PR_TEXTWIN_BOLD
#define SE_TEXTWIN_TEXT 0x08
#define SE_TEXTWIN_BULLET PR_TEXTWIN_BULLET
/* Types for textwin */
typedef struct
{
unsigned short int state;
char label[1];
}IN_TEXTWIN;
typedef struct
{
int flags;
unsigned short int state;
char *buf;
unsigned short int len;
}SE_TEXTWIN;
/* Property of textwin */
typedef struct {
PR_EPFLAT *label;
unsigned short int state;
} PRS_TEXTWIN;
typedef struct pr_textwin
{
PRS_ROOT root;
PRS_WIN win;
PRS_LODGER lodger;
PRS_TEXTWIN textwin;
} PR_TEXTWIN;
