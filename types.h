typedef unsigned int   uint;
typedef unsigned short ushort;
typedef unsigned char  uchar;
typedef uint pde_t;

struct perf {
  int ps_priority;              // field for set priority
  int rtime;                    // time process was in running state
  int stime;                    // time process was in sleeping state
  int retime;                   // time process was in ready/runnable state
};


#ifndef NULL
#define NULL (void*) 0
#endif