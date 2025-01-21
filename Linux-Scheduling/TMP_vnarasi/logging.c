#include<stdio.h>
#include<kernel.h>
#include<proc.h>

struct epoch_log {
    int pid;
    char *pname;
    int pprio;
    int goodness;
    int remaining;
    int preempt;
} logs[100][10];


int numepochs = 0;
int curproc = 0;

void addepochlog(int pid, char *pname, int pprio, int goodness, int remaining, int preempt) {
    struct epoch_log *logitem = &logs[numepochs][curproc++];
    logitem->pid = pid;
    logitem->pname = pname;
    logitem->pprio = pprio;
    logitem->goodness = goodness;
    logitem->remaining = remaining;
    logitem->preempt = preempt;
}

void createnewepoch() {
    curproc = 0;
    numepochs++;
}

void printepochlogs() {
    int i;
    kprintf("\nEpoch Logs!\n");
    for (i = 0; i < numepochs; i++) {
        kprintf("\nEpoch %d\n", i);
        int j;
        for (j = 0; j < 10; j++) {
            struct epoch_log logitem = logs[i][j];
            if (logitem.pid != 0)
                kprintf("Process: %d Name: %s, Priority: %d, Goodness: %d, Remaining: %d, Preempt: %s\n", 
                    logitem.pid, logitem.pname, logitem.pprio, logitem.goodness, logitem.remaining, logitem.preempt);
        }   
    }
    kprintf("\nEnd of Logs!\n");
}
