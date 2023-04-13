/* Release 3.00 */

/*-------------------------------------------------------------------------*
*                                                                          *
*  signal.h -  software signalling definitions and prototypes.		   *
*                                                                          *
*  COPYRIGHT (C) 1989, 1990 Jensen and Partners. All Rights Reserved.      *
*                                                                          *
*--------------------------------------------------------------------------*/
#include <stdepoc.h>

#ifndef _SIGNAL_INC_
#define _SIGNAL_INC_

typedef int     sig_atomic_t;
#define NSIG 23     /* maximum signal number + 1 */

/* signal types */
#define SIGINT      2   /* interrupt - corresponds to DOS 3.x int 23H */
#define SIGILL      4   /* illegal opcode */
#define SIGFPE      8   /* floating point error */
#define SIGSEGV     11  /* segment violation */
#define SIGTERM     15  /* Software termination signal from kill */
#define SIGUSR1     16  /* User defined signal 1 */
#define SIGUSR2     17  /* User defined signal 2 */
#define SIGUSR3     20  /* User defined signal 3 */
#define SIGABRT     22  /* abnormal termination triggered by abort call */

/* signal action codes */

#define SIG_DFL (void (*)(int))0L     /* default signal action */
#define SIG_IGN (void (*)(int))1L     /* ignore */
#define SIG_SGE (void (*)(int))3L     /* signal gets error */
#define SIG_ACK (void (*)(int))4L     /* error if handler not setup */

/* signal error value (returned by signal call on error) */

#define SIG_ERR (void (*)(int)) 0xFFFFL  /* signal error value */

/* function prototypes */

#ifdef __cplusplus
extern "C" {
#endif
extern void ( *  signal(int _sig, void (*_func)(int _signum)))(int _signum);
extern int       raise(int _sig);
#ifdef __cplusplus
}
#endif
#endif

