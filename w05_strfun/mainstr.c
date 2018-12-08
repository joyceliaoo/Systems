#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strfun.h"

int main(){

  char s0[] = "Flaming Hot Cheetos";
  char s1[50] = "Costco grapes";
  char s2[] = "apple juice";

  printf("s0: %s \n", s0);
  printf("s1: %s \n", s1);
  printf("s2: %s \n", s2);

  printf("----------------\n");

  printf("TEST strlen(s0) \n");
  printf("expected: %ld \n", strlen(s0));
  printf("result: %d \n", my_strlen(s0));

  printf("----------------\n");

  printf("TEST strncpy(s1, s2, 5) \n");
  printf("expected: %s \n", strncpy(s1, s2, 5));
  printf("result: %s \n", my_strncpy(s1, s2, 5));

  printf("----------------\n");

  printf("TEST strcat(s1, s2) \n");
  printf("expected: %s \n", strcat(s1, s2));
  s1[strlen(s1) - strlen(s2)] = 0; //undo modification above
  printf("result: %s \n", my_strcat(s1, s2));

  printf("----------------\n");

  printf("TEST strcmp(s1, s2) \n");
  printf("expected: %d \n", strcmp(s1,s2));
  printf("result: %d \n\n", my_strcmp(s1, s2));

  printf("TEST strcmp(s2, s1) \n");
  printf("expected: %d \n", strcmp(s0,s1));
  printf("result: %d \n", my_strcmp(s0, s1));

  printf("----------------\n");

  printf("TEST strchr(s1, 'p') \n");
  printf("expected: %p \n", strchr(s1, 'p'));
  printf("result: %p \n\n", my_strchr(s1, "p"));

  printf("TEST strchr(s1, 'x') \n");
  printf("expected: %p \n", strchr(s1, 'x'));
  printf("result: %p \n", my_strchr(s1, "x"));

  

}


  
