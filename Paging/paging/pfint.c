/* pfint.c - pfint */

#include <conf.h>
#include <kernel.h>
#include <paging.h>
#include <proc.h>


/*-------------------------------------------------------------------------
 * pfint - paging fault ISR
 *-------------------------------------------------------------------------
 */


SYSCALL pfint()
{
  STATWORD ps;
  disable(ps);
  int pt_frame, page_frame;
  long virt_addr = read_cr2();
  virt_addr_t *vaddr = (virt_addr_t*)&virt_addr;
  unsigned long pdbr = proctab[currpid].pdbr;
  if (vaddr->pd_offset >= 1024) {
    kill(currpid);
    restore(ps);
    return SYSERR;
  }
  pd_t *pd_element = pdbr + (vaddr->pd_offset * sizeof(pd_t));

  if (pd_element->pd_pres == 0) {
    if(debug){
      // kprintf("NO PD\n");
    }
    //empty directory
    if(get_frm(&pt_frame) == SYSERR) {
      restore(ps);
      return SYSERR;
    }

    pt_t *pgt_element = (1024 + pt_frame)*NBPG;
    int pgt_element_i = 0;
    while (pgt_element_i < NFRAMES) {
      pgt_element->pt_pres=0;
      pgt_element->pt_write=0;
      pgt_element->pt_user=0;
      pgt_element->pt_pwt=0;
      pgt_element->pt_pcd=0;
      pgt_element->pt_acc=0;
      pgt_element->pt_dirty=0;
      pgt_element->pt_mbz=0;
      pgt_element->pt_global=0;
      pgt_element->pt_avail=0;
      pgt_element->pt_base=0;
      pgt_element++;
      pgt_element_i++;	
    }
    
    fr_map_t *pt_frm = &frm_tab[pt_frame];
    pt_frm->fr_status = FRM_MAPPED;
    pt_frm->fr_pid = currpid;
    pt_frm->fr_type = FR_TBL;
    
    pd_element->pd_base=1024+pt_frame;
    pd_element->pd_pres=1;
    pd_element->pd_write=1;
    pd_element->pd_user=0;
    pd_element->pd_pwt=0;
    pd_element->pd_pcd=0;
    pd_element->pd_acc=0;
    pd_element->pd_mbz=0;
    pd_element->pd_fmb=0;
    pd_element->pd_global=0;
    pd_element->pd_avail=0;

  }

  //Now we need to go to the start of the page table pointed by pd_base and then offset into the correct page table using the pt offset from vaddr
  
  pt_t *pt_element = (pd_element->pd_base * NBPG + vaddr->pt_offset * sizeof(pt_t));
  if(pt_element -> pt_pres == 0) {
    //if page is not present we find a new frame for this page
    if(debug){
      // kprintf("No Page!\n");
    }

    if (get_frm(&page_frame) == SYSERR) {
      restore(ps);
      return SYSERR;
    }

    fr_map_t *page_frm = &frm_tab[page_frame];
    page_frm->fr_status = FRM_MAPPED;
    page_frm->fr_pid = currpid;
    page_frm->fr_type = FR_PAGE;
    page_frm->fr_vpno = virt_addr/NBPG;
    page_frm->fr_refcnt++;
    
    pt_element->pt_pres = 1;
    pt_element->pt_base = 1024 + page_frame;
    pt_element->pt_write = 1;

    //Now we find the backing store associated with this pid
    
    int store, page_in_store;

    if(bsm_lookup(currpid, virt_addr, &store, &page_in_store) == SYSERR) {
      restore(ps);
      return SYSERR;
    } 

    //Now we copy the page from backing store into our frame

    read_bs((char *) ((1024 + page_frame) * NBPG), store, page_in_store);
    insert_frame(page_frame);
  }
  pt_element->pt_acc = 1;
  write_cr3(pdbr);
  restore(ps);
  return OK;
}


