#ifndef SONG_H
#define SONG_H


struct song_node{ 
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_song(struct song_node *song);
void print_songlist(struct song_node *list);
struct song_node *insert_front(struct song_node *list, char *song, char *musician);
struct song_node *insert_alpha(struct song_node *list, char *song, char *musician);
struct song_node *find_one(struct song_node *list, char *song, char *musician);
struct song_node *find_first(struct song_node *list, char *musician);
struct song_node *random_song(struct song_node *list);
struct song_node *remove_song(struct song_node *list, char *song);
struct song_node *free_list(struct song_node *list);

int list_length(struct song_node *list); //helper function

#endif

