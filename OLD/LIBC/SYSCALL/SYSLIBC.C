/* Copyright (C) 1995,1996 Robert de Bath <rdebath@cix.compulink.co.uk>
 * This file is part of the Linux-8086 C library and is distributed
 * under the GNU Library General Public License.
 */

#include <sys/types.h>
#include <errno.h>
#include <time.h>

/* MSDOS has it's own versions */
#ifndef __MSDOS__

/********************** Function time ************************************/

#ifdef L_time
time_t time(where)
time_t *where;
{
   struct timeval rv;
   if( gettimeofday(&rv, (void*)0) < 0 ) return -1;
   if(where) *where = rv.tv_sec;
   return rv.tv_sec;
}
#endif

/********************** Function abort ************************************/

#ifdef L_abort
#include <signal.h>

int abort()
{
   signal(SIGABRT, SIG_DFL);
   kill(SIGABRT, getpid());	/* Correct one */
   pause();			/* System may just schedule */
   signal(SIGKILL, SIG_DFL);
   kill(SIGKILL, getpid());	/* Can't trap this! */
   __exit(255);			/* WHAT!! */
}
#endif

/********************** Function wait ************************************/

#ifdef L_wait
int
wait(status)
int * status;
{
   return wait4(-1, status, 0, (void*)0);
}
#endif

/********************** Function waitpid ************************************/

#ifdef L_waitpid
int
waitpid(pid, status, opts)
int pid;
int * status;
int opts;
{
   return wait4(pid, status, opts, (void*)0);
}
#endif

/********************** Function killpg ************************************/

#ifdef L_killpg
int
killpg(pid, sig)
int pid;
int sig;
{
   if(pid == 0)
       pid = getpgrp();
   if(pid > 1)
       return kill(-pid, sig);
   errno = EINVAL;
   return -1;
}
#endif

/********************** Function setpgrp ************************************/

#ifdef L_setpgrp
int
setpgrp()
{
   return setpgid(0,0);
}
#endif

/********************** Function sleep ************************************/

#ifdef L_sleep
#include <signal.h>

/* This uses SIGALRM, it does keep the previous alarm call but will lose
 * any alarms that go off during the sleep
 */

static void alrm() { }

unsigned int sleep(seconds)
unsigned int seconds;
{
   void (*last_alarm)();
   unsigned int prev_sec;

   prev_sec = alarm(0);
   if( prev_sec <= seconds ) prev_sec = 1; else prev_sec -= seconds;

   last_alarm = signal(SIGALRM, alrm);
   alarm(seconds);
   pause();
   seconds = alarm(prev_sec);
   signal(SIGALRM, last_alarm);
   return seconds;
}
#if 0
        /* Is this a better way ? If we have select of course :-) */
#include <sys/time.h>
unsigned int
sleep(seconds)
unsigned int seconds;
{
        struct timeval timeout;
	time_t start = time((void*)0);
        timeout.tv_sec = seconds;
        timeout.tv_usec = 0;
        select(1, NULL, NULL, NULL, &timeout);
	return seconds - (time((void*)0) - start);
}
#endif

#endif

/********************** Function usleep ************************************/

#ifdef L_usleep
#include <sys/time.h>
void
usleep(useconds)
unsigned long useconds;
{
        struct timeval timeout;
        timeout.tv_sec = useconds%1000000L;
        timeout.tv_usec = useconds/1000000L;
        select(1, NULL, NULL, NULL, &timeout);
}
#endif

/********************** THE END ********************************************/

#endif /* __MSDOS__ */
