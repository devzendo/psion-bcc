/* Generated by Ctran from nchlist.cl */
#define NCHLIST_G
#ifndef CHLIST_G
#include <chlist.g>
#endif
/* Class Numbers */
#define C_VANUMBER 78
#define C_NCHLIST 79
/* Method Numbers */
#define O_VAN_SET_MAX 24
/* Property of vanumber */
typedef struct {
char data[8];
} PRS_VANUMBER;
typedef struct pr_vanumber
{
PRS_ROOT root;
PRS_VAROOT varoot;
PRS_VANUMBER vanumber;
} PR_VANUMBER;
/* Property of nchlist */
typedef struct pr_nchlist
{
PRS_ROOT root;
PRS_WIN win;
PRS_LODGER lodger;
PRS_CHLIST chlist;
} PR_NCHLIST;
