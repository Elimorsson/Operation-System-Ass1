#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"



int main1(int argc, char *argv[]) {
  int pid;
  int k;
  printf(1,"sanity:\n");
  printf(1,"PID\tPS_PRIORITY\tSTIME\tRETIME\tRTIME\n");
  
  for ( k = 0; k < 3; k++ ) {
    pid = fork ();
    if ( pid < 0 ) {
      printf(1, "%d failed in fork!\n", getpid());
      exit(0);
    } else if (pid == 0) {
      // child
        struct perf* performance = malloc(sizeof(struct perf));
      switch(k){
          case 0:
            set_cfs_priority(3);
            set_ps_priority(10);
            break;
          case 1:
            set_cfs_priority(2);
            set_ps_priority(5);
            break;
          case 2:
            set_ps_priority(1);
            set_cfs_priority(1);
            break;
      }
      for (long long i = 0; i < 100; i += 1 ){
         //x =  x + 3.14 * 89.64;  // useless calculations to consume CPU time
         int  t1 = 0, t2 = 1, nextTerm;
        long long z, n = 10000;
        
        for (z = 1; z <= n; ++z) {
            printf(0,"");
            printf(1,"");
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
        }
      
      }
    printf(1,"%d\t",getpid());
    proc_info(performance);
    printf(1,"%d \t\t %d \t %d \t %d\n", performance->ps_priority, performance->stime, performance->retime, performance->rtime);
      free(performance);
      exit(0);
    }
  }
  
  for (k = 0; k < 3; k++) {
    wait(0);
  }

  exit(0);
}

