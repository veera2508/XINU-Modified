/* frame.c - manage physical frames */
#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <paging.h>
#include <stdio.h>

int frm_queue[NFRAMES];
int frm_head;
int frm_tail;

/*-------------------------------------------------------------------------
 * init_frm - initialize frm_tab
 *-------------------------------------------------------------------------
 */
SYSCALL init_frm()
{
  STATWORD ps;
  disable(ps);

  if (debug)
  {
    kprintf("init_frm\n");
  }
  int i = 0;
  while (i < NFRAMES)
  {
    fr_map_t *frm = &frm_tab[i];
    frm->fr_pid = -1;
    frm->fr_status = FRM_UNMAPPED;
    frm->fr_vpno = 4096;
    frm->fr_refcnt = 0;
    frm->fr_type = FR_PAGE;
    frm->fr_dirty = 0;
    i++;
  }
  restore(ps);
  return OK;
}

/*-------------------------------------------------------------------------
 * get_frm - get a free frame according page replacement policy
 *-------------------------------------------------------------------------
 */
SYSCALL get_frm(int *avail)
{
  STATWORD ps;
  disable(ps);

  // if (debug)
  // {
  //   kprintf("get_frm\n");
  // }

  int frmno = 0;
  for (; frmno < NFRAMES; frmno++)
  {
    if (frm_tab[frmno].fr_status == FRM_UNMAPPED)
    {
      *avail = frmno;

      if (debug)
      {
        kprintf("get_frm: %d\n", frmno);
      }
      restore(ps);
      return OK;
    }
  }

  int evictedfrm = evict();

  if (evictedfrm >= 0)
  {
    if (evict_debug)
    {
      kprintf("evicted frame: %d\n", evictedfrm);
    }
    free_frm(evictedfrm);
    *avail = evictedfrm;
  }
  else
  {

    restore(ps);
    return SYSERR;
  }

  restore(ps);
  return OK;
}

/*-------------------------------------------------------------------------
 * free_frm - free a frame
 *-------------------------------------------------------------------------
 */
SYSCALL free_frm(int i)
{
  STATWORD ps;
  disable(ps);

  if (debug)
  {
    kprintf("free_frm\n");
  }

  if (frm_tab[i].fr_type == FR_PAGE)
  {

    long vaddr = frm_tab[i].fr_vpno * 4096;
    virt_addr_t *a = (virt_addr_t *)&vaddr;
    struct pentry *proc = &proctab[frm_tab[i].fr_pid];
    int pdbr = proc->pdbr;

    int p = a->pt_offset;
    int q = a->pd_offset;

    pd_t *pd = pdbr + (q * sizeof(pd_t));
    pt_t *pt = (pd->pd_base * NBPG) + (p * sizeof(pt_t));

    write_bs((i + FRAME0) * NBPG, proc->store, frm_tab[i].fr_vpno - proc->vhpno);
    // kprintf("frm_tab[i].fr_vpno - proc->vhpno: %08x\n", frm_tab[i].fr_vpno - proc->vhpno);

    pt->pt_pres = 0;
    int page_loc = pd->pd_base - FRAME0;
    // kprintf("fr_type:%d \n", frm_tab[page_loc].fr_type);
    // kprintf("page_loc:%d ", page_loc);
    (&frm_tab[page_loc])->fr_refcnt--;
    if ((&frm_tab[page_loc])->fr_refcnt == 0)
    {
      pd->pd_pres = 0;

      (&frm_tab[page_loc])->fr_refcnt = 0;
      (&frm_tab[page_loc])->fr_dirty = 0;
      (&frm_tab[page_loc])->fr_pid = -1;
      (&frm_tab[page_loc])->fr_status = FRM_UNMAPPED;
      (&frm_tab[page_loc])->fr_type = FR_PAGE;
      (&frm_tab[page_loc])->fr_vpno = 4096;
    }
  }

  restore(ps);
  // kprintf("To be implemented!\n");
  return OK;
}

int initialize_queue()
{

  if (debug)
  {
    kprintf("initialize_queue\n");
  }

  int frmno = 0;
  for (; frmno < NFRAMES; frmno++)
  {
    frm_queue[frmno] = -1;
  }
  frm_head = -1;
  frm_tail = -1;
}

int evict()
{

  if (debug)
  {
    kprintf("evict\n");
  }
  STATWORD ps;
  disable(ps);

  int iter = frm_head;
  int prev;

  while (iter != -1)
  {

    virt_addr_t *a = NBPG * frm_tab[iter].fr_vpno;
    int p = a->pd_offset;
    int q = a->pt_offset;

    int pid = frm_tab[iter].fr_pid;
    pd_t *pd = (pd_t *)(proctab[pid].pdbr + p * sizeof(pd_t));
    pt_t *pt = (pt_t *)(pd->pd_base * NBPG + q * sizeof(pt_t));

    if (pt->pt_acc == 1)
    {
      pt->pt_acc = 0;
    }
    else
    {
      // if (prev == -1)
      // {
      //   // int ret = frm_head;
      //   // frm_head = frm_queue[frm_head];
      //   // frm_queue[ret] = -1;
      //   int ret =

      //   restore(ps);
      //   return ret;
      // }
      // else
      // {
      //   // frm_queue[prev] = frm_queue[iter];
      //   // frm_queue[iter] = -1;

      //   restore(ps);
      //   return iter;
      // }

      if (iter == frm_head)
      {
        int ret = iter;
        int temp_next = frm_queue[iter];
        frm_queue[frm_head] = -1;
        frm_head = temp_next;
        if (frm_head == frm_tail)
        {
          frm_tail = temp_next;
        }

        restore(ps);
        return ret;
      }
      else
      {
        int ret = iter;
        int temp_next = frm_queue[iter];

        int temp_iter = frm_head;
        while (frm_queue[temp_iter] != iter)
        {
          temp_iter = frm_queue[temp_iter];
        }

        frm_queue[temp_iter] = frm_queue[iter];
        frm_queue[iter] = -1;

        if (iter == frm_tail)
        {
          frm_tail = temp_iter;
        }

        restore(ps);
        return ret;
      }
    }

    if (iter == frm_tail)
    {
      iter = frm_head;
    }
    else
    {
      iter = frm_queue[iter];
    }
  }

  // while (iter != -1)
  // {
  //   virt_addr_t *a = NBPG * frm_tab[iter].fr_vpno;
  //   int p = a->pd_offset;
  //   int q = a->pt_offset;

  //   int pid = frm_tab[iter].fr_pid;
  //   pd_t *pd = (pd_t *)(proctab[pid].pdbr + p * sizeof(pd_t));
  //   pt_t *pt = (pt_t *)(pd->pd_base * NBPG + q * sizeof(pt_t));

  //   if (pt->pt_acc == 1)
  //   {
  //     pt->pt_acc = 0;
  //   }
  //   else
  //   {
  //     if (prev == -1)
  //     {
  //       int ret = frm_head;
  //       frm_head = frm_queue[frm_head];
  //       frm_queue[ret] = -1;

  //       restore(ps);
  //       return ret;
  //     }
  //     else
  //     {
  //       frm_queue[prev] = frm_queue[iter];
  //       frm_queue[iter] = -1;

  //       restore(ps);
  //       return iter;
  //     }
  //   }

  //   prev = iter;
  //   iter = frm_queue[iter];
  // }

  // iter = frm_head;
  // prev;

  // while (iter != -1)
  // {
  //   virt_addr_t *a = NBPG * frm_tab[iter].fr_vpno;
  //   int p = a->pd_offset;
  //   int q = a->pt_offset;

  //   int pid = frm_tab[iter].fr_pid;
  //   pd_t *pd = (pd_t *)(proctab[pid].pdbr + p * sizeof(pd_t));
  //   pt_t *pt = (pt_t *)(pd->pd_base * NBPG + q * sizeof(pt_t));

  //   if (pt->pt_acc == 1)
  //   {
  //     pt->pt_acc = 0;
  //   }
  //   else
  //   {
  //     if (prev == -1)
  //     {
  //       int ret = frm_head;
  //       frm_head = frm_queue[frm_head];
  //       frm_queue[ret] = -1;

  //       restore(ps);
  //       return ret;
  //     }
  //     else
  //     {
  //       frm_queue[prev] = frm_queue[iter];
  //       frm_queue[iter] = -1;

  //       restore(ps);
  //       return iter;
  //     }
  //   }

  //   prev = iter;
  //   iter = frm_queue[iter];
  // }

  restore(ps);
  return -1;
}

void insert_frame(int frm)
{
  if (frm_head == -1)
  {
    frm_head = frm;
    frm_tail = frm;
    return;
  }

  int iter = frm_head;
  int prev;

  // while (iter != -1)
  // {
  //   prev = iter;
  //   iter = frm_queue[iter];
  // }

  frm_queue[frm_tail] = frm;
  // frm_queue[frm] = -1;
  frm_tail = frm;
  return;
}
