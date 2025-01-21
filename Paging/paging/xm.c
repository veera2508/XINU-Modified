/* xm.c = xmmap xmunmap */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <paging.h>


/*-------------------------------------------------------------------------
 * xmmap - xmmap
 *-------------------------------------------------------------------------
 */
SYSCALL xmmap(int virtpage, bsd_t source, int npages)
{
  //kprintf("xmmap - to be implemented!\n");
  if(debug){
    kprintf("xmmap\n");
  }
  if(virtpage < 4096 || source < 0 || source >= NBS || npages <= 0){
    return SYSERR;
  }

  // if(bsm_tab[source].bs_status != BSM_UNMAPPED){
  //   return SYSERR;
  // }
  if(bsm_map(currpid, virtpage, source, npages) == SYSERR){
    return SYSERR;
  }
  return OK;
}



/*-------------------------------------------------------------------------
 * xmunmap - xmunmap
 *-------------------------------------------------------------------------
 */
SYSCALL xmunmap(int virtpage)
{
  //kprintf("To be implemented!");
  if(debug){
    kprintf("xmunmap\n");
  }
  if(virtpage < 4096){
    return SYSERR;
  }
  if(bsm_unmap(currpid, virtpage, 1) == SYSERR){
    return SYSERR;
  }
  return OK;
}
