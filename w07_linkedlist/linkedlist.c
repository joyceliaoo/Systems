#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

void print_list(struct node *target){
  struct node *current = target;
  while (current){
    printf("%s-->", current->cargo);
    current = current->next;
  }
  printf("[no next] \n");
}


struct node * insert_front(struct node *head, char *new_cargo){
  struct node *new = malloc(sizeof(struct node));
  strcpy(new->cargo, new_cargo);
  new->next = head;
  return new;
}

struct node *free_list(struct node *head) {
  struct node *old = head;
  while (head){
    struct node *next_up = head->next;
    free(head);
    head = next_up;
    printf("freed one node \n");
  }
  printf("all freed! \n");
  return old;
}
