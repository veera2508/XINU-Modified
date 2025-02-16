#include <conf.h>
#include <kernel.h>
#include <mark.h>
#include <bufpool.h>
#include <proc.h>
#include <paging.h>

SYSCALL read_bs(char *dst, bsd_t bs_id, int page) {

  /* fetch page page from map map_id
     and write beginning at dst.
  */
   if(debug){
      kprintf("read_bs\n");
   }
   if(dst == NULL || bs_id < 0 || bs_id >= NBS || page < 0 || page >= 256){
      return SYSERR;
   }
   void * phy_addr = BACKING_STORE_BASE + bs_id*BACKING_STORE_UNIT_SIZE + page*NBPG;
   bcopy(phy_addr, (void*)dst, NBPG);
}


