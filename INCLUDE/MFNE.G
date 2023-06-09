/* Generated by Ctran from mfne.cl */
#define MFNE_G
#ifndef LODGER_G
#include <lodger.g>
#endif
/* Class Numbers */
#define C_MFNE 27
/* Method Numbers */
#define O_MF_RANGE_BEEP 19
/* Constants for mfne */
#define MFNE_MAX_FIELDS 4
#define MFNE_MAX_WIDTH 10
#define MFNE_MAX_TRAILER 3
#define MFNE_LOWER 0
#define MFNE_UPPER 1
#define MFNE_CURSOR_WIDTH 3
#define MFNE_SIGNED 0x01
#define MFNE_LEFT_ALIGN 0x02
#define MFNE_SUPPRESS_LEADING 0x04
#define MFNE_SUPPRESS_SEPARATOR 0x08
#define MFNE_TRAILER 0x10
#define MFNE_SETS_NEXT 0x20
#define MFNE_SETS_PREV 0x40
#define MFNE_AUTO_SIZE 0x80
#define MFNE_EMPHASISED_KLUDGE 0x20
/* Types for mfne */
typedef struct
{
short int flags;
long int value;
unsigned char width;
unsigned char hWidth;
unsigned char hPos;
unsigned char separator;
long int limits[2];
} MFNE_FIELD;
/* Property of mfne */
typedef struct {
short int selected;
short int cField;
short int nField;
short int totWidth;
short int cPos;
short int changed;
char eStr[MFNE_MAX_WIDTH+2];
char dStr[MFNE_MAX_FIELDS*(MFNE_MAX_WIDTH+1)+MFNE_MAX_TRAILER+2];
char trail[2][MFNE_MAX_TRAILER+1];
MFNE_FIELD f[MFNE_MAX_FIELDS];
} PRS_MFNE;
typedef struct pr_mfne
{
PRS_ROOT root;
PRS_WIN win;
PRS_LODGER lodger;
PRS_MFNE mfne;
} PR_MFNE;
