#include<conf.h>
#include<kernel.h>
#include<proc.h>
#include<paging.h>

bs_map_t bsm_tab[NBS];

void init_bs(void){
    int i;
    for(i=0; i<NBS; i++){
        bsm_tab[i].bs_status = BSM_UNMAPPED;
        bsm_tab[i].bs_pid = -1;
        bsm_tab[i].bs_vpno = 0;
        bsm_tab[i].bs_npages = 0;
        bsm_tab[i].bs_sem = 0;
    }
}