/* Generated by Ctran from chlist.cl */
#define CHLIST_G
#ifndef LODGER_G
#include <lodger.g>
#endif
#ifndef VARES_G
#include <vares.g>
#endif
#ifndef MATCHER_G
#include <matcher.g>
#endif
#ifndef LISTBOX_G
#include <listbox.g>
#endif
/* Class Numbers */
#define C_CHLIST 21
/* Method Numbers */
/* Constants for chlist */
#define SE_CHLIST_NSEL 0x01
#define SE_CHLIST_DATA 0x02
#define SE_CHLIST_RETAIN 0x04
#define IN_CHLIST_INCREMENTAL 0x01
#define PR_CHLIST_RETAIN 0x04
#define PR_CHLIST_SUSPENDED 0x08
#define PR_CHLIST_FIXED_WIDTH 0x10
/* Types for chlist */
typedef struct
{
short int rid;
unsigned char nsel;
unsigned char flags;
} IN_CHLIST;
typedef struct
{
unsigned short int set_flags;
PR_VAROOT *data;
unsigned short int nsel;
} SE_CHLIST;
/* Property of chlist */
typedef struct {
PR_LISTBOX *pop;
PR_VMATCHER *matcher;
PR_VARES *data;
unsigned short int nsel;
unsigned short int flags;
unsigned short int matchlen;
} PRS_CHLIST;
typedef struct pr_chlist
{
PRS_ROOT root;
PRS_WIN win;
PRS_LODGER lodger;
PRS_CHLIST chlist;
} PR_CHLIST;
