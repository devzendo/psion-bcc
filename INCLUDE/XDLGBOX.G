/* Generated by Ctran from xdlgbox.cl */
#define XDLGBOX_G
#ifndef DLGBOX_G
#include <dlgbox.g>
#endif
#ifndef SERDLGS_G
#include <serdlgs.g>
#endif
/* Class Numbers */
#define C_ATSDIAL 17
/* Method Numbers */
/* Property of atsdial */
typedef struct {
void *owner;
void *main;
void *buts;
PR_WIN *filter;
short int filmethod;
short int chlist;
short int pid;
short int ret;
unsigned short int locked;
} PRS_ATSDIAL;
typedef struct pr_atsdial
{
PRS_ROOT root;
PRS_WIN win;
PRS_DLGCHAIN dlgchain;
PRS_DLGBOX dlgbox;
PRS_ATSDIAL atsdial;
} PR_ATSDIAL;
