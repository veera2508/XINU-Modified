/* resched.c  -  resched */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sched.h>
#include <math.h>

unsigned long currSP;	/* REAL sp of current process */
extern int ctxsw(int, int, int, int);
int maxgoodnessproc = 0;
int maxgoodness = 0;
/*-----------------------------------------------------------------------
 * resched  --  reschedule processor to highest priority ready process
 *
 * Notes:	Upon entry, currpid gives current process id.
 *		Proctab[currpid].pstate gives correct NEXT state for
 *			current process if other than PRREADY.
 *------------------------------------------------------------------------
 */

int schedtype;
void setschedclass(int type) {
	schedtype = type;
}

int getschedclass() {
    return schedtype;
}


int getexpprio(int head, int tail, int key) {
    int next, prev;
    next = head;
    while (q[next].qkey < key)
        next = q[next].qnext;
    if (next == head)
        return getfirst(head);
    else if (next == tail)
        return getlast(tail);
    next = dequeue(next);
    return next;
}

int resched() {
	switch(schedtype) {
		case DEFAULT_SCHED: resched_defualt(); break; 
		case EXPDISTSCHED: resched_exp(); break;
        case LINUXSCHED: resched_linux(); break;
	}
}

int resched_defualt()
{
	register struct	pentry	*optr;	/* pointer to old process entry */
	register struct	pentry	*nptr;	/* pointer to new process entry */

	/* no switch needed if current process priority higher than next*/

	if ( ( (optr= &proctab[currpid])->pstate == PRCURR) &&
	   (lastkey(rdytail)<optr->pprio)) {
		return(OK);
	}
	
	/* force context switch */

	if (optr->pstate == PRCURR) {
		optr->pstate = PRREADY;
		insert(currpid,rdyhead,optr->pprio);
	}

	/* remove highest priority process at end of ready list */

	nptr = &proctab[ (currpid = getlast(rdytail)) ];
	nptr->pstate = PRCURR;		/* mark it currently running	*/
    #ifdef	RTCLOCK
	    preempt = QUANTUM;		/* reset preemption counter	*/
    #endif
	
	ctxsw((int)&optr->pesp, (int)optr->pirmask, (int)&nptr->pesp, (int)nptr->pirmask);
	
	/* The OLD process returns here when resumed. */
	return OK;
}

int resched_exp() {
	register struct	pentry	*optr;	/* pointer to old process entry */
	register struct	pentry	*nptr;	/* pointer to new process entry */
	int targetprio = (int)expdev(0.1);
	optr = &proctab[currpid];
    if (optr->pstate == PRCURR) {
	    optr->pstate = PRREADY;
        insert(currpid, rdyhead, optr->pprio);
    }
	nptr = &proctab[ (currpid = getexpprio(rdyhead, rdytail, targetprio)) ];
	nptr->pstate = PRCURR;		/* mark it currently running	*/
    #ifdef RTCLOCK
        preempt = QUANTUM;
    #endif /* ifdef RTCLOCK
        preempt = QUANTUM; */
	ctxsw((int)&optr->pesp, (int)optr->pirmask, (int)&nptr->pesp, (int)nptr->pirmask);
	return OK;
}

int getmaxgoodness() {
    int maxgoodness = 0;
    int node;
    for (node = q[rdyhead].qnext; node != rdytail; node = q[node].qnext) {
        if (proctab[node].goodness >= maxgoodness) { //Ensures round robin between epochs
            maxgoodnessproc = node;
            maxgoodness = proctab[node].goodness;
        }
    }
    return maxgoodness;
}

void promoteproc(register struct pentry *optr, int newpid) {
	register struct	pentry	*nptr;	/* pointer to new process entry */
    if (optr->pstate == PRCURR) {
        optr->pstate = PRREADY;
        insert(currpid, rdyhead, optr->pprio);
    }

    nptr = &proctab[ (currpid = dequeue(newpid)) ];
    nptr->pstate = PRCURR;		/* mark it currently running	*/
    if (newpid == NULLPROC) {
        #ifdef RTCLOCK
            preempt = QUANTUM;
        #endif 

    } else {
        preempt = nptr->remaining;
    }
    //kprintf("\nContext switch %s -> %s \n", optr->pname, nptr->pname);
    ctxsw((int)&optr->pesp, (int)optr->pirmask, (int)&nptr->pesp, (int)nptr->pirmask);
}

int ispreemptready(register struct pentry *optr) {
    return (optr->remaining == 0 || optr->pstate != PRCURR);
}

void setupnewepoch() {
    struct pentry *p;
    int i;
    //createnewepoch();
    //kprintf("\nEnd of epoch! \n");
    for (i = 0; i <= NPROC; i++) {
        p = &proctab[i];
        if (p->pstate != PRFREE) {
            p->oprio = p->pprio;
            p->remaining = (int)p->remaining/2 + p->oprio;
            p->goodness = p->oprio + p->remaining;
        }
    }
    /*
    for (i = 0; i <= NPROC; i++) {
            if (proctab[i].pstate != PRFREE)
                addepochlog(i, proctab[i].pname, proctab[i].pprio, proctab[i].goodness, proctab[i].remaining, preempt);
    }
    */


}
/*
 * Linux Resched Logic
 * if process used its quantum this epoch, set its goodness to 0 and recalculate remaining for this process
 * This is also true for NULLPROC
 * Since resched needs to always schedule maxproc whenever it is called calculate MAXGOODNESS
 * set optr remaining to preempt since we might pop optr out
 * Now check if the max goodness is > 0 and ( current count is over or current is killed or current goodness < maxgoodness )
 * if it is then swap the max process with current
 * Otherwise check if max goodness is 0 and (current is nullproc or current count is over or current is killed or current goodness = 0)
 * Reinitialize all goodness values and put NULLPROC into the current state and reinitialize preempt for NULLPROC as Quantum
 * If current process is not killed and cur goodness > maxgoodness then continue with current process and update preempt
 * */

int resched_linux() {
    register struct	pentry	*optr;	/* pointer to old process entry */
    optr = &proctab[currpid];

    if (preempt == 0 || currpid == NULLPROC)
        optr->goodness = 0;

    optr->remaining = preempt;

    maxgoodness = getmaxgoodness();

    //switch to maxproc
    if (maxgoodness > 0 && (ispreemptready(optr) || optr->goodness <= maxgoodness)) {
        promoteproc(optr, maxgoodnessproc);
    } else if (maxgoodness == 0 && (ispreemptready(optr) || currpid == NULLPROC)) { //End of epoch
        setupnewepoch();
        promoteproc(optr, NULLPROC);
    } else if (optr->goodness > maxgoodness && optr->pstate == PRCURR) {
        preempt = optr->remaining;
    }

    return OK;
}
