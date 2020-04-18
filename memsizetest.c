#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{

  int size = memsize();
  printf(1,"the process is using: %d \n", size);
  int* newPlace = (int*) malloc(2048);
  size = memsize();
  printf(1,"the process is using: %d \n", size);
  free(newPlace);
  size = memsize();
  printf(1,"the process is using: %d \n", size);
  exit(0);
}
