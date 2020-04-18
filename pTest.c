
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {
  int pid;
  int k, n;
  int x, z;

  policy(2);
  if (argc != 2) {
    printf(2, "usage: %s n\n", argv[0]);
  }

  n = atoi(argv[1]);

  for ( k = 0; k < n; k++ ) {
    pid = fork ();
    if ( pid < 0 ) {
      printf(1, "%d failed in fork!\n", getpid());
      exit(0);
    } else if (pid == 0) {
      // child
      printf(1, "Child %d created\n",getpid());
      for ( z = 0; z < 100.0; z += 1 )
         x =  x + 3.14 * 89.64;   // useless calculations to consume CPU time
      exit(0);
    }
  }

  for (k = 0; k < n; k++) {
    wait(0);
  }

  exit(0);
}
