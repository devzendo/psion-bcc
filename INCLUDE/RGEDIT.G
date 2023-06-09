/* Generated by Ctran from rgedit.cl */
#define RGEDIT_G
#ifndef LODGER_G
#include <lodger.g>
#endif
#ifndef MFNE_G
#include <mfne.g>
#endif
/* Class Numbers */
#define C_RGEDIT 32
/* Method Numbers */
/* Constants for rgedit */
#define SE_RGEDIT_LOW 0x01
#define SE_RGEDIT_VALUE_1 0x02
#define SE_RGEDIT_VALUE_2 0x04
#define SE_RGEDIT_HIGH 0x08
#define IX_RGEDIT_LOW	0
#define IX_RGEDIT_VALUE_1	1
#define IX_RGEDIT_VALUE_2	2
#define IX_RGEDIT_HIGH	3
/* Types for rgedit */
typedef struct
{
unsigned short int value[4];
} IN_RGEDIT;
typedef struct
{
unsigned short int value[4];
unsigned short int flags;
} SE_RGEDIT;
/* Property of rgedit */
typedef struct {
IN_RGEDIT in;
} PRS_RGEDIT;
typedef struct pr_rgedit
{
PRS_ROOT root;
PRS_WIN win;
PRS_LODGER lodger;
PRS_MFNE mfne;
PRS_RGEDIT rgedit;
} PR_RGEDIT;
