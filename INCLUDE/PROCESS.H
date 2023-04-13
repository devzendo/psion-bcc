/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  process.h -	header for process control functions.			   *
*                                                                          *
*  COPYRIGHT (C) 1989, 1990 Jensen and Partners. All Rights Reserved.      *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _PROCESS_INC_
#define _PROCESS_INC_


/*  Modes available as first argument of the spawn? functions. */

#define P_WAIT	  0	/* child runs separately, parent waits */
#define P_NOWAIT  1	/* both concurrent */
#define P_OVERLAY  2	/* parent dies, same as exec? */

#ifdef __cplusplus
extern "C" {
#endif
extern void	   abort(void);
extern int	   atexit(void (* func)(void));
extern void   (*  onexit(void (* func)(void)))();

extern int        execl(const char *_path, char *_arg0, ...);
extern int        execlp(const char *_path, char *_arg0, ...);
extern int        execv(const char *_path, char *_argv[]);
extern int        execvp(const char *_path, char *_argv[]);

extern void	   exit(int _status);
extern void       _exit(int _status);
extern unsigned   getpid(void);

extern int        spawnl(int _mode, const char *_path, char *_arg0, ...);
extern int        spawnlp(int _mode, const char *_path, char *_arg0, ...);
extern int        spawnv(int _mode, const char *_path, char *_argv[]);
extern int        spawnvp(int _mode, const char *_path, char *_argv[]);
extern int        system(const char *_command);
#ifdef __cplusplus
}
#endif

#endif
