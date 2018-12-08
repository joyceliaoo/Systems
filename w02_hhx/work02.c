#include <stdio.h>
#include <math.h>

unsigned int num = 2234567892;
char * pointer = &num;

int main(){
  printf("int in hex: %x\n", num);
  printf("location: %p\n", pointer);
  //printf("num through pointer: %hhx\n", *pointer);

  //show each byte of num
  int b;
  char * temp_pointer0 = pointer;
  for(b = 0; b < sizeof(num); b++) {
    printf("Byte %d of num is %hhx\n", b, *temp_pointer0);
    temp_pointer0 ++; //goes to next byte
  }

  //increment each byte by 1
  char * temp_pointer1 = pointer;
  for(b = 0; b < sizeof(num); b++) {
    *temp_pointer1 += 1;
    printf("modification %d: \n", b);
    printf("resulting num in hex: %x\n", num);
    printf("resulting num in decimal: %u\n", num);
    printf("-----------\n");
    temp_pointer1++;
  }

  //increment each byte by 16
  char * temp_pointer2 = pointer;
  for(b = 0; b < sizeof(num); b++) {
    *temp_pointer2 += 16;
     printf("modification %d: \n", b+4);
    printf("resulting num in hex: %x\n", num);
    printf("resulting num in decimal: %u\n", num);
    printf("-----------\n");
    temp_pointer2++;
  }
  return 0;
}





