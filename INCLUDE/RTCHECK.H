/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  rtcheck.h -  run time check error handler interface.        		   *
*                                                                          *
*  COPYRIGHT (C) 1989, 1990 Jensen and Partners. All Rights Reserved.      *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _RTCHECK_INC_
#define _RTCHECK_INC_

/* Values for code parameter */
#define _CNS_STACK      1      /* Stack overflow */
#define _CNS_NILPTR     2      /* Nil Ptr dereference */
#define _CNS_INDEX      3      /* Index out of range  */
#define _CNS_OVERFLOW   4      /* Integer overflow */
#define _CNS_RANGE      5      /* Integer out of range */
#define _CNS_RETURN     6      /* No return in function */
#define _CNS_CASE       7      /* No matching case */
#define _CNS_DIVZERO    8      /* Long integer divide by zero */
#define _CNS_PVC       10      /* Pure virtual function called */

/* return values for handler */
#define _CNS_CONTINUE       1
#define _CNS_TERMINATE      0

#ifdef __cplusplus
extern "C" {
#endif
#pragma save,call(reg_param=>(), reg_saved=>(ax,bx,cx,dx,ds,si,di,st1,st2))
#pragma name(prefix=>"CoreSig@")
extern unsigned char (* CnsHandler)(unsigned code, unsigned IP, unsigned CS);
#pragma restore
#ifdef __cplusplus
}
#endif

#endif

