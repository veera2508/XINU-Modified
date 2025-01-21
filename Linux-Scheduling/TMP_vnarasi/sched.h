#ifndef  _sched_h_
#define _sched_h_
#define DEFAULT_SCHED 0
#define EXPDISTSCHED 1
#define LINUXSCHED 2
void setschedclass(int type);
int getschedclass();
#endif
extern int schedtype;
