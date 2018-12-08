#include <stdlib.h>
#include <stdio.h>
#include "strfun.h"

int my_strlen( char *s ){
  int sum = 0;
  while(*s){
    sum++;
    s++;
  }
  return sum;  
}

char * my_strncpy(char *dest, char *source, int n){
  while (n--){
    *(dest + n) = *( source + n);
  }
  return dest;
}

char * my_strcat(char *dest, char *source){
  char * target = dest;
  while (*target) {
    target++;
  }
  while (*(source)) {
    *(target) = *(source);
    target++;
    source++;
  }
  *(target + 1) = 0; //ending null char
  return dest;
}

int my_strcmp(char *s1, char *s2){
  while (*(s1) == *(s2) && *s1 && *s2){
    s1++;
    s2++;
  }

  return *s1 - *s2;
}

char * my_strchr( char *s, char *c){
  while( *s != *c) {
    s++;
    if (! *s)
      return 0;
  }

  return s;
}


  
