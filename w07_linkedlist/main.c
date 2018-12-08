#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

int main(){
  struct node *head;

  printf("printing empty list: \n");
  print_list(head);

  head = insert_front(head, "cry");

  printf("first insertion: \n");
  print_list(head);

  head = insert_front(head, "sad");

  printf("second insertion: \n");
  print_list(head);

  head = insert_front(head, "sigh");

  printf("third insertion: \n");
  print_list(head);

  printf("free list: \n");

  head = free_list(head);
 
  return 0;
}
