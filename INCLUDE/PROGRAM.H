/*      HEADER - PROGRAM.H
PROGRAM header
Copyright (c) Psion PLC 1993.

 VER    DATE    BY  DESCRIPTION
----- -------- ---- -----------
1.00A 03/03/93 HP  Initial release
*/

#define PROGRAM_H
#ifndef P_STD_H
#include <p_std.h>
#endif
#ifndef P_FILE_H
#include <p_file.h>
#endif

/* Constants for progexec */
#define PROGEXEC_SIGNAL 0x01        /* signal on completion */
#define PROGEXEC_NOTIFY 0x02        /* call notifier on error */
#define H_COMMAND_TRANSLATE_FILE 'T'
#define H_COMMAND_RUN_FILE 'R'
#define H_COMMAND_XTRANSLATE_FILE 't'

/* Constants for progtran */
#define PT_PROGTRAN_LINE  0x10      /* get a line of source */
#define PT_PROGTRAN_DEATH 0x11      /* Opl translator death */

/* Types for progtran */
typedef struct
    {
    WORD stat;          /* completion status */
    UWORD mode;         /* translation mode */
    UWORD line;         /* line number */
    UWORD offset;       /* offset to syntax error */
    } PROGTRAN_STATUS;

typedef struct
    {
    UWORD pid;                       /* process id of source */
    TEXT *buffer_offset;             /* offset of buffer in source process */
    PROGTRAN_STATUS *status_offset;  /* offset of status block in source */
    } PROGTRAN_SOURCE;

/* Types for progexec */
typedef struct
    {       /* receives data from sys$prg?.img on completion */
    WORD  error;              /* runtime error */
    UWORD line;               /* line no of start of proc containing error */
    UWORD offset;             /* Q code offset to runtime error */
    TEXT  err[40];            /* runtime error string */
    TEXT  src[P_FNAMESIZE];   /* to take source module name */
    } PROGEXEC_RESBUF;

typedef struct
    {       /* used to pass parameters to sys$prg?.img in p_execc() */
    UWORD  flags;                   /* mode information */
    UWORD  pid;                     /* requestor process id */
    PROGEXEC_RESBUF *result_offset; /* result buffer offset */
    } PROGEXEC_PAR;
