#ifndef LIBRARY_H
#define LIBRARY_H

void add_song(char *song, char *musician);
struct song_node *search_song(char *song, char *musician);
struct song_node *search_artist(char *musician);
void print_alpha(char letter);
void print_artist(char *musician);
void print_all();
void delete_song();
void shuffle();
void clear_library();

int get_index(char *musician); //helper

#endif
