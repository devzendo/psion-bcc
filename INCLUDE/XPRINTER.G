/* Generated by Ctran from xprinter.cl */
#define XPRINTER_G
#ifndef LPRINTER_G
#include <lprinter.g>
#endif
/* Class Numbers */
#define C_XPRINTER 6
/* Method Numbers */
/* Property of xprinter */
typedef struct {
short int locked;
} PRS_XPRINTER;
typedef struct pr_xprinter
{
PRS_ROOT root;
PRS_LPRINTER lprinter;
PRS_XPRINTER xprinter;
} PR_XPRINTER;
