/* vcreate.c - vcreate */

#include <conf.h>
#include <i386.h>
#include <kernel.h>
#include <proc.h>
#include <sem.h>
#include <mem.h>
#include <io.h>
#include <paging.h>

/*
static unsigned long esp;
*/

LOCAL newpid();
/*------------------------------------------------------------------------
 *  create  -  create a process to start running a procedure
 *------------------------------------------------------------------------
 */
SYSCALL vcreate(procaddr, ssize, hsize, priority, name, nargs, args)
int *procaddr; /* procedure address		*/
int ssize;	   /* stack size in words		*/
int hsize;	   /* virtual heap size in pages	*/
int priority;  /* process priority > 0		*/
char *name;	   /* name (for debugging)		*/
int nargs;	   /* number of args that follow	*/
long args;	   /* arguments (treated like an	*/
			   /* array in the code)		*/
{

	STATWORD ps;
	disable(ps);

	if (debug)
	{
		kprintf("vcreate\n");
	}
	int avail;
	int bsm_err = get_bsm(&avail);
	if (bsm_err == SYSERR)
	{
		restore(ps);
		return SYSERR;
	}

	int newpid = create(procaddr, ssize, hsize, priority, name, nargs, args);

	if (newpid != SYSERR)
	{
		int bsm_map_err = bsm_map(newpid, 4096, avail, hsize);
		if (bsm_map_err != SYSERR)
		{
			(&proctab[newpid])->store = avail;
			(&proctab[newpid])->vhpno = 4096;
			(&proctab[newpid])->vhpnpages = hsize;
			(&proctab[newpid])->vmemlist->mnext = NBPG * 4096;
			(&proctab[newpid])->vmemlist->mnext->mlen = NBPG * hsize;
			struct mblock *bs = BACKING_STORE_BASE + (avail * BACKING_STORE_UNIT_SIZE);
			bs->mlen = NBPG * hsize;
			bs->mnext = NULL;
			restore(ps);
			return newpid;
		}
	}

	// kprintf("To be implemented!\n");
	restore(ps);
	return SYSERR;
}

/*------------------------------------------------------------------------
 * newpid  --  obtain a new (free) process id
 *------------------------------------------------------------------------
 */
LOCAL newpid()
{
	int pid; /* process id to return		*/
	int i;

	for (i = 0; i < NPROC; i++)
	{ /* check all NPROC slots	*/
		if ((pid = nextproc--) <= 0)
			nextproc = NPROC - 1;
		if (proctab[pid].pstate == PRFREE)
			return (pid);
	}
	return (SYSERR);
}
