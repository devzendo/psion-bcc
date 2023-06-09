/* Generated by Ctran from ncedit.cl */
#define NCEDIT_G
#ifndef LODGER_G
#include <lodger.g>
#endif
#ifndef MFNE_G
#include <mfne.g>
#endif
/* Class Numbers */
#define C_LNCEDIT 28
#define C_NCEDIT 29
#define C_WNCEDIT 30
/* Method Numbers */
/* Constants for lncedit */
#define SE_LNCEDIT_VALUE	0x01
#define SE_LNCEDIT_LOW	0x02
#define SE_LNCEDIT_HIGH	0x04
/* Types for lncedit */
typedef struct
{
long int value;
long int low;
long int high;
} IN_LNCEDIT;
typedef struct
{
long int value;
long int low;
long int high;
unsigned short int flags;
} SE_LNCEDIT;
/* Property of lncedit */
typedef struct pr_lncedit
{
PRS_ROOT root;
PRS_WIN win;
PRS_LODGER lodger;
PRS_MFNE mfne;
} PR_LNCEDIT;
/* Constants for ncedit */
#define SE_NCEDIT_VALUE	0x01
#define SE_NCEDIT_LOW	0x02
#define SE_NCEDIT_HIGH	0x04
/* Types for ncedit */
typedef struct
{
unsigned short int value;
unsigned short int low;
unsigned short int high;
} IN_NCEDIT;
typedef struct
{
unsigned short int value;
unsigned short int low;
unsigned short int high;
unsigned short int flags;
} SE_NCEDIT;
/* Property of ncedit */
typedef struct pr_ncedit
{
PRS_ROOT root;
PRS_WIN win;
PRS_LODGER lodger;
PRS_MFNE mfne;
} PR_NCEDIT;
/* Constants for wncedit */
#define SE_WNCEDIT_VALUE	0x01
#define SE_WNCEDIT_LOW	0x02
#define SE_WNCEDIT_HIGH	0x04
/* Types for wncedit */
typedef struct
{
short int value;
short int low;
short int high;
} IN_WNCEDIT;
typedef struct
{
short int value;
short int low;
short int high;
short int flags;
} SE_WNCEDIT;
/* Property of wncedit */
typedef struct pr_wncedit
{
PRS_ROOT root;
PRS_WIN win;
PRS_LODGER lodger;
PRS_MFNE mfne;
} PR_WNCEDIT;
