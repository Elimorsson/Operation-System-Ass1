#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
if (argc != 2){
    exit(1);
 }
  int n = atoi(argv[1]);
  policy(n);
  exit(0);
}
