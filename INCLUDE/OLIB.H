/*      HEADER - OLIB.H
OLIB standard header
Copyright (c) Psion PLC 1991 - 1996.
*/

#define OLIB_H

GLREF_C INT cl_add(INT,VOID *);
GLREF_C INT cl_add_alloc(VOID *);
GLREF_C INT cl_add_iochan(VOID *);
GLREF_C INT cl_add_object(VOID *);
GLREF_C INT cl_add_shared(VOID *);
GLREF_C INT cl_add_dyl(HANDLE);
GLREF_C VOID cl_clean_item(INT);
GLREF_C VOID cl_remove(INT);
