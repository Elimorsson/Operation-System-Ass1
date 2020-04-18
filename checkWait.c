#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
   if (fork() == 0){
       exit(0);
   }
   int status = -12;
   wait(&status);
   printf(1, "the status is %d\n", status);
   exit(0);
}
