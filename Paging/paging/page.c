#include <conf.h>
#include <i386.h>
#include <kernel.h>
#include <proc.h>
#include <sem.h>
#include <sleep.h>
#include <mem.h>
#include <tty.h>
#include <q.h>
#include <io.h>
#include <paging.h>


int creatept(unsigned int* pt_frame) {
  int avail_frame;
  pt_t *pt_element;

  if (get_frm(&avail_frame) == SYSERR) return SYSERR;
  pt_element = (1024 + avail_frame) * NBPG;
  int pt_element_i = 0;
  while(pt_element_i < NFRAMES) {
    pt_element->pt_pres = 1;
    pt_element->pt_write = 1;
    pt_element->pt_user = 0;
    pt_element->pt_pwt = 0;
    pt_element->pt_pcd = 0;
    pt_element->pt_acc = 0;
    pt_element->pt_dirty = 0;
    pt_element->pt_mbz = 0;
    pt_element->pt_global = 1;
    pt_element->pt_avail = 0;
    pt_element->pt_base =  0; //each page starting from memory location 0 to 4096 divided by 1024 per table
    pt_element++;
    pt_element_i++;
  }

  *pt_frame = avail_frame;
  return OK;
}

void setupbtables() {
  pt_t *pt_element;
  int avail_frame;
  int page_table_i = 0;
  //4 page tables for base memory
  while (page_table_i < 4) {
    get_frm(&avail_frame); //Get the first available frame (will be 0 since initialize runs first)
    fr_map_t *frm = &frm_tab[avail_frame];
    frm->fr_status = FRM_MAPPED;
    frm->fr_pid = NULLPROC;
    frm->fr_type = FR_TBL;
    
    int page_j = 0;
    pt_element = (1024 + avail_frame) * NBPG; //the pt elemets start at the beginning of the frame we got
    //1024 page entry per table
    while (page_j < 1024) {
      pt_element->pt_pres = 1;
      pt_element->pt_write = 1;
      pt_element->pt_user = 0;
      pt_element->pt_pwt = 0;
      pt_element->pt_pcd = 0;
      pt_element->pt_acc = 0;
      pt_element->pt_dirty = 0;
      pt_element->pt_mbz = 0;
      pt_element->pt_global = 1;
      pt_element->pt_avail = 0;
      pt_element->pt_base =  page_table_i * 1024 + page_j; //each page starting from memory location 0 to 4096 divided by 1024 per table
      pt_element++;
      page_j++;
    }
    page_table_i++;
  }
}

void createptdir(int pid) {
  int page_table_entry_i = 0;
  int avail_frame;
  struct pentry *proc = &proctab[pid];
  get_frm(&avail_frame);
  fr_map_t *frm = &frm_tab[avail_frame];
  frm->fr_status = FRM_MAPPED;
  frm->fr_pid = pid;
  frm->fr_type = FR_DIR;
  frm->fr_refcnt = 4; //4 base tables mapped for each process

  pd_t *pd_element;
  proc->pdbr = (1024 + avail_frame) * NBPG; //Starting from the available frame
  pd_element = proc->pdbr;

  if(debug){
    kprintf("pdbr: %d pid:%d", pd_element,pid);
  }

  //1024 page table entries per directory
  while (page_table_entry_i < 1024) {
    //First 4 tables (base tables) are common
    if (page_table_entry_i < 4) {
      pd_element->pd_base = (1024 + page_table_entry_i); //base page in kb (where each page table starts from) + which page table it is 
      pd_element->pd_pres = 1;
    } else {
      pd_element->pd_base = 0;
      pd_element->pd_pres = 0;
    }
    
    pd_element->pd_write = 1;
    pd_element->pd_user = 0;
    pd_element->pd_pwt = 0;
    pd_element->pd_pcd = 0;
    pd_element->pd_acc = 0;
    pd_element->pd_fmb = 0;
    pd_element->pd_mbz = 0;
    pd_element->pd_global = 0;
    pd_element->pd_avail = 0;
    pd_element++;
    page_table_entry_i++;

  }
}


