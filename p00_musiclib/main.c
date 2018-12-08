#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "song.h"
#include "library.h"

int main(){

  printf("==========linkedlist functions==========\n");

  printf("testing insert_front and print_songlist \n");
  struct song_node *list0 = NULL;

  printf("first insertion: \n");
  list0 = insert_front(list0,"Yellow Submarine", "The Beatles");
  print_songlist(list0);

  printf("second insertion: \n");
  list0 = insert_front(list0, "Pompeii", "Bastille");
  print_songlist(list0);

  printf("-----------------------\n");

  printf("testing print_song \n");
  print_song(list0);

  printf("-----------------------\n");

  printf("testing insert_alpha \n");

  struct song_node *list1 = NULL;

  printf("first insertion: \n");
  list1 = insert_front(list1,"Yellow Submarine", "The Beatles");
  print_songlist(list1);

  printf("second insertion: \n");
  list1 = insert_front(list1, "Pompeii", "Bastille");
  print_songlist(list1);

  printf("third insertion: \n");
  list1 = insert_alpha(list1, "Party Rock Anthem", "LMFAO");
  print_songlist(list1);

  printf("fourth insertion: \n");
  list1 = insert_alpha(list1, "Strawberry Fields", "The Beatles"); 
  print_songlist(list1);

  printf("fifth insertion: \n");
  list1= insert_alpha(list1, "They Don't Know About Us", "One Direction");
  print_songlist(list1);

  printf("-----------------------\n");

  printf("testing finding first song of artist\n");

  printf("pointing to first song by LMFAO:\n");
  print_songlist(find_first(list1, "LMFAO"));

  printf("pointing to first song by The Beatles:\n");
  print_songlist(find_first(list1, "The Beatles"));

  printf("pointing to first song by Taylor Swift: \n");
  print_songlist(find_first(list1, "Taylor Swift \n"));

  printf("-----------------------\n");

  printf("testing finding specific song of artist\n");

  printf("finding Strawberry Fields by The Beatles: \n");
  print_songlist(find_one(list1, "Strawberry Fields", "The Beatles"));

  printf("finding Radioactive by Imagine Dragons: \n");
  print_songlist(find_one(list1, "Radioactive", "Imagine Dragons"));

  printf("-----------------------\n");

  printf("testing remove_song \n");

  printf("original list: \n");
  print_songlist(list1);

  printf("removing Party Rock Anthem by LMFAO: \n");
  list1 = remove_song(list1, "Party Rock Anthem");
  print_songlist(list1);

  printf("removing Try by Jay Chou (not in list) \n");
  list1 = remove_song(list1, "Try");
  print_songlist(list1);

  printf("-----------------------\n");

  list1 = insert_alpha(list1, "Lego House", "Ed Sheeran");
  list1 = insert_alpha(list1, "Worth It", "Fifth Harmony");
  list1 = insert_alpha(list1, "Never Enough", "Loren Allred");

  printf("testing random_song\n");

  srand(time(NULL));

  int i = 3;
  while (i) {
    printf("Here's our pick: \n");
    print_song(random_song(list1));
    i--;
  }

  printf("-----------------------\n");

  printf("testing list_length (helper) \n");

  printf("There are %d songs in this playlist: \n", list_length(list0));
  print_songlist(list0);

  printf("-----------------------\n");

  printf("tesing free_list \n"); 

  printf("after freeing list0: \n");
  list0 = free_list(list0); 
  print_songlist(list0);

  printf("after freeing list1: \n");
  list1 = free_list(list1);
  print_songlist(list1); 

  printf("==========music library functions==========\n");

  printf("testing get_index (helper) \n");
  printf("Shawn Mendes goes in slot %d \n", get_index("Shawn Mendes"));
  printf("Katy Perry goes in slot %d \n", get_index("Katy Perry"));
  printf("5 Seconds of Summer goes in slot %d \n", get_index("5 Seconds of Summer"));

  printf("-----------------------\n");

  printf("testing print_all and add_song \n");

  printf("Adding Never Be the Same by Camila Cabello: \n");
  add_song("Never Be the Same", "Camila Cabello");
  print_all();

  printf("Adding Say Something by Justin Timberlake: \n");
  add_song("Say Something", "Justin Timberlake");
  print_all();

  printf("Adding Call Me Maybe by Carly Rae Jepsen: \n");
  add_song("Call Me Maybe", "Carly Rae Jepsen");
  print_all();

  printf("Adding Amnesia by 5 Seconds of Summer: \n");
  add_song("Amnesia", "5 Seconds of Summer");
  print_all();

  printf("-----------------------\n");

  printf("testing print_alpha (entries under specific letter) \n");

  printf("Artists in J list: \n");
  print_alpha('J');

  printf("Artists in non-letter list: \n");
  print_alpha('#');

  printf("-----------------------\n");

  printf("testing search_song \n");

  printf("Looking for Never Be the Same by Camila Cabello: \n");
  print_song(search_song("Never Be the Same", "Camila Cabello"));

  printf("Looking for Hello by Adele: \n");
  print_song(search_song("Hello", "Adele"));

  printf("-----------------------\n");

  printf("testing search_artist \n");

  printf("searching for Camila Cabello: \n");
  print_songlist(search_artist("Camila Cabello"));

  printf("searching for JJ Lin (not in list) \n");
  print_songlist(search_artist("JJ Lin"));

  printf("-----------------------\n");

  printf("testing print_artist \n");

  add_song("Lego House", "Ed Sheeran");
  add_song("Perfect", "Ed Sheeran");

  printf("Library: \n");
  print_all();

  printf("printing all songs by Ed Sheeran: \n");
  print_artist("Ed Sheeran");

  printf("printing all songs by Carly Rae Jepsen: \n");
  print_artist("Carly Rae Jepsen");

  printf("printing all songs by G.E.M. \n");
  print_artist("G.E.M.");

  printf("-----------------------\n");

  printf("testing shuffle \n");

  shuffle();

  printf("-----------------------\n");

  printf("testing delete_song \n");

  printf("removing Perfect by Ed Sheeran: \n");
  delete_song("Perfect", "Ed Sheeran");
  printf("Library: \n");
  print_all();

  printf("removing Say Something by Justin Timberlake: \n");
  delete_song("Say Something", "Justin Timberlake");
  printf("Library: \n");
  print_all();

  printf("removing Just Dance by Lady Gaga (not in library): \n");
  delete_song("Just Dance", "Lady Gaga");
  printf("Library: \n");
  print_all();

  printf("-----------------------\n");

  printf("clear library! \n");
  clear_library();
  printf("Library: \n");
  print_all();
  return 0;
}
