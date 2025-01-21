#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <paging.h>

int get_bs(bsd_t bs_id, unsigned int npages) {

  /* requests a new mapping of npages with ID map_id */
    // kprintf("To be implemented!\n");
    if(debug){
      kprintf("get_bs\n");
    }
    if(bs_id <0 || bs_id >= NBS || npages ==0 || npages > 256){
      return SYSERR;
    }

    // if(bsm_tab[bs_id].bs_status == BSM_MAPPED){
    //   return bsm_tab[bs_id].bs_npages;
    // }

    bsm_tab[bs_id].bs_status = BSM_MAPPED;
    bsm_tab[bs_id].bs_npages = npages;
    bsm_tab[bs_id].bs_pid = currpid;
    bsm_tab[bs_id].bs_vpno = 0;
    bsm_tab[bs_id].bs_sem = 0;
    
    return npages;

}


