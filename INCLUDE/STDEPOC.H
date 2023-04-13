/*      HEADER - STDEPOC.H
Epoc/Os standard C calling convention, structures and constants.
Copyright (c) Psion PLC 1991.

 VER    DATE    BY  DESCRIPTION
----- -------- ---- -----------
1.00F 26/04/91 NSM  Final release
*/
#ifndef STDEPOC_H
#define STDEPOC_H
#pragma call(reg_saved=>(ax,bx,cx,dx,di,si,ds,st1,st2),\
             reg_param=>(ax,bx,cx,dx,st0,st6,st5,st4,st3),\
	     reg_return=>(ax,dx,st0),standard_float=>off,\
	     opt_var_arg=>on,c_conv=>off)
#pragma call(seg_name =>null)
#pragma data(ss_in_dgroup =>on,seg_name =>null)
#pragma warn(wall=>on,wpnu=>off,wovr=>off)
#define EPOC_SAVE ds,st1,st2
#endif

