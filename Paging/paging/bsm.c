/* bsm.c - manage the backing store mapping*/

#include <conf.h>
#include <kernel.h>
#include <paging.h>
#include <proc.h>

#define BS_BASE_ADDR(store) (BACKING_STORE_BASE + (store) * BACKING_STORE_UNIT_SIZE)

/*-------------------------------------------------------------------------
 * init_bsm- initialize bsm_tab
 *-------------------------------------------------------------------------
 */
SYSCALL init_bsm()
{	
    STATWORD(ps);
	disable(ps);

    if (debug){
        kprintf("init_bsm\n");
    }
    int i;
    for(i=0; i<NBS; i++){
        bsm_tab[i].bs_status = BSM_UNMAPPED;
        bsm_tab[i].bs_pid = -1;
        bsm_tab[i].bs_vpno = 4096;
        bsm_tab[i].bs_npages = 0;
        bsm_tab[i].bs_sem = 0;
    }

    restore(ps);
    return OK;
}

/*-------------------------------------------------------------------------
 * get_bsm - get a free entry from bsm_tab 
 *-------------------------------------------------------------------------
 */
SYSCALL get_bsm(int* avail)
{

    STATWORD(ps);
	disable(ps);
    if(debug){
        kprintf("get_bsm\n");
    }
    int i;
    for(i=0; i<NBS; i++){
        if(bsm_tab[i].bs_status == BSM_UNMAPPED) {
            *avail = i;
            restore(ps);
            return OK;
        }
    }
    restore(ps);
    return SYSERR;
}


/*-------------------------------------------------------------------------
 * free_bsm - free an entry from bsm_tab 
 *-------------------------------------------------------------------------
 */
SYSCALL free_bsm(int i)
{
    STATWORD(ps);
	disable(ps);
    if(debug){
        kprintf("free_bsm\n");
    }
    if(i<0 || i>NBS){

        restore(ps);
        return SYSERR;
    }
    bsm_tab[i].bs_status = BSM_UNMAPPED;
    bsm_tab[i].bs_pid = -1;
    bsm_tab[i].bs_vpno = 4096;
    bsm_tab[i].bs_npages = 0;
    bsm_tab[i].bs_sem = 0;
    restore(ps);
    return OK;
}

/*-------------------------------------------------------------------------
 * bsm_lookup - lookup bsm_tab and find the corresponding entry
 *-------------------------------------------------------------------------
 */
SYSCALL bsm_lookup(int pid, long vaddr, int* store, int* pageth)
{
    STATWORD(ps);
	disable(ps);
    int i;
    int vpgno = vaddr / NBPG;
    for(i=0; i<NBS; i++){
        if(bsm_tab[i].bs_pid == pid){
        *store = i;
        *pageth = vpgno - bsm_tab[i].bs_vpno;
        if (debug) {
            kprintf("bsm_lookup - store: %d, page: %d\n", *store, *pageth);
        }
        restore(ps);
        return OK;
        }
    }  
    restore(ps);
    return SYSERR;
}


/*-------------------------------------------------------------------------
 * bsm_map - add an mapping into bsm_tab 
 *-------------------------------------------------------------------------
 */
SYSCALL bsm_map(int pid, int vpno, int source, int npages)
{
    STATWORD(ps);
	disable(ps);
    if(debug){
        kprintf("bsm_map\n");
    }
    if(source < 0 || source >= NBS){
        restore(ps);
        return SYSERR;
    }
    bsm_tab[source].bs_status = BSM_MAPPED;
    bsm_tab[source].bs_pid = pid;
    bsm_tab[source].bs_vpno = vpno;
    bsm_tab[source].bs_npages = npages;

    proctab[currpid].vhpno = vpno;
    proctab[currpid].store = source;

    restore(ps);
    return OK;
}



/*-------------------------------------------------------------------------
 * bsm_unmap - delete an mapping from bsm_tab
 *-------------------------------------------------------------------------
 */
SYSCALL bsm_unmap(int pid, int vpno, int flag)
{
    if(debug){
        kprintf("bsm_unmap\n");
    }
    int i;
    for(i=0; i<NBS; i++){
        if(bsm_tab[i].bs_pid == pid && bsm_tab[i].bs_vpno == vpno){
            bsm_tab[i].bs_status = BSM_UNMAPPED;
            bsm_tab[i].bs_pid = -1;
            bsm_tab[i].bs_vpno = 0;
            bsm_tab[i].bs_npages = 0;
            return OK;
        }
    }
    return SYSERR;
}


