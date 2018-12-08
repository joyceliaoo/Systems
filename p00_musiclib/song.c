#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "song.h"

void print_song(struct song_node *song) {
    if (song)
      printf("song: %s by %s \n", song->name, song->artist);
    else
      printf("song is not in library \n");
}

void print_songlist(struct song_node *target){
  if (!target)
    printf("list is empty or target does not exist! \n");
  else{
    struct song_node *current = target;
    while (current){
      print_song(current);
      current = current->next;
    }
    printf("--- \n");
  }
}

struct song_node * insert_front(struct song_node *list, char *song, char *musician){
  struct song_node *new = malloc(sizeof(struct song_node));
  strcpy(new->name, song);
  strcpy(new->artist, musician);
  new->next = list;
  return new;
}

struct song_node * insert_alpha(struct song_node *list, char *song, char *musician) {
  if (!list || strcmp(musician, list->artist) < 0)
    return insert_front(list, song, musician);
  struct song_node *original = list;
  while(list->next) {
    struct song_node *temp = list->next;
    if(strcmp(musician, temp->artist) <= 0)
      break;
    else if(strcmp(musician, temp->artist) == 0) {
      while(list->next) {
        if (strcmp(song, list->next->name) < 0)
          break;
        list = list->next;
      }
    }
    else {list = list->next;}
    }
    list->next = insert_front(list->next, song, musician);
    return original;
}

struct song_node *find_first(struct song_node *list, char *musician){
  while (list) {
    if (strcmp(musician, list->artist) == 0)
      return list;
    list = list->next;
  }
  return NULL;
}

struct song_node *find_one(struct song_node *list, char *song, char *musician){
  struct song_node *to_artist = find_first(list, musician);
  while (to_artist){
    if (strcmp(song, to_artist->name) == 0)
      return to_artist;
    to_artist = to_artist->next;
  }
  return NULL;
}

struct song_node *remove_song(struct song_node *list, char *song){
  if (list) {
    if (strcmp(song, list->name) == 0)
      return list->next;
    struct song_node *current = list;
    struct song_node *temp;
    while(current->next) {
      temp = current->next;
      if (strcmp(song, temp->name) == 0)
        current->next = temp->next;
      else
        current = current->next;
    }
  }
  return list;
}


//helper function to get the number of songs in the list
int list_length(struct song_node *list) {
  int c = 0;
  while(list) {
    c++;
    list = list->next;
  }
  return c;
}

struct song_node *random_song(struct song_node *list){
  int ran = rand();
  //printf("%d \n", ran);
  ran = ran % list_length(list);
  while (ran) {
    list = list->next;
    ran--;
  }
  return list;
}

struct song_node *free_list(struct song_node *list) {
  struct song_node *current = list;
  while (current){
    current = list->next;
    free(list);
    list = current;
  }
  return list;
}
