#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "song.h"
#include "library.h"

struct song_node *lib[27];

//identity the slot in array that corresponds to first letter of artist's name
int get_index(char *musician) {
	char temp[100];
	strcpy(temp, musician);
	int i = temp[0] - 'A';
	if (i<0 || i>26) return 27;
	return i;
}

void add_song(char *song, char *musician){
	int i = get_index(musician);
	lib[i] = insert_alpha(lib[i], song, musician);
}

struct song_node *search_song(char *song, char *musician) {
	int i = get_index(musician);
	return find_one(lib[i], song, musician);
}

struct song_node *search_artist(char *musician) {
	int i = get_index(musician);
	return find_first(lib[i], musician);
}

void print_alpha(char letter) {
	int i = get_index(&letter);
	//printf("%d \n", i);
	print_songlist(lib[i]);
}

void print_artist(char *musician){
	int i = get_index(musician);
	struct song_node *current = find_first(lib[i], musician);
	if (!current) printf("artist not found! \n");
	while (current) {
		print_song(current);
		current = find_first(current->next, musician);
	}
}

void print_all() {
	printf("=====\n");
	for (int i = 0; i<=27; i++) {
		if (lib[i]) {
			printf("%c list: \n", 'A'+i);
			print_alpha('A'+i);
		}
	}
	printf("=====\n");
}

void shuffle() {
	int num = 5;
	int ran;
	for (int i = 5; i>0;) {
		ran = rand() % 27;
		if (lib[ran]) {
			printf("chance %d: \n", 5-i);
			print_song(random_song(lib[ran]));
			i--;
		}
	}
}

void delete_song(char *song, char *musician) {
	int i = get_index(musician);
	lib[i] = remove_song(lib[i], song);
}

void clear_library() {
	for (int i = 0; i <=27; i++) {
		if(lib[i])
			lib[i] = free_list(lib[i]);
	}
}
