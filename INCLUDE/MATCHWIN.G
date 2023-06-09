/* Generated by Ctran from matchwin.cl */
#define MATCHWIN_G
#ifndef MATCHER_G
#include <matcher.g>
#endif
#ifndef GRIDWIN_G
#include <gridwin.g>
#endif
/* Class Numbers */
#define C_MATCHWIN 21
/* Method Numbers */
#define O_MW_STOP_MATCH 24
#define O_MW_HIT_MAXLEN 25
#define O_MW_START_MATCH 23
/* Constants for matchwin */
#define PR_MATCHWIN_UNSET (-1)
/* Types for matchwin */
typedef struct
{
PR_VAROOT *array;
unsigned int maxlen;
unsigned short int txtoff;
unsigned int minrec;
unsigned int maxrec;
int offset;
unsigned int column;
int position;
} IN_MATCHWIN;
/* Property of matchwin */
typedef struct {
PR_VMATCHER *matcher;
IN_MATCHWIN params;
unsigned char matchlen;
unsigned char filler;
} PRS_MATCHWIN;
typedef struct pr_matchwin
{
PRS_ROOT root;
PRS_WIN win;
PRS_GRIDWIN gridwin;
PRS_MATCHWIN matchwin;
} PR_MATCHWIN;
