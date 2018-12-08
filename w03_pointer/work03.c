#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int first_array[10];
  srand(time(NULL));
  for (int c = 0; c < 9; c++) {
    first_array[c] = rand();
  }
  first_array[9] = 0;

  printf("First array: \n");
  for (int c = 0; c < 10; c++) {
      printf("Index %d: %d\n", c, first_array[c]);
    }

  int second_array[10];
  int *pf = first_array;
  int *ps = second_array;

  printf("Second array: \n");

  for (int c = 0; c < 10; c++) {
    *( ps + c) = * ( pf + (9 - c));
    printf("Index %d: %d\n", c, *(ps + c));
  }


  
  return 0;
}


