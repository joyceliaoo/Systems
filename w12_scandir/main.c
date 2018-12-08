#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "scanner.h"

int main(int argc, char *argv[]) {

  //scan current directory
  printf("current directory: \n");
  scan_dir(".");

  //if the user has provided an argument
  printf("directory requested by user: \n");
  if (argc > 1) {
    if(scan_dir(argv[1])) { //if directory was not found
      printf("%s\n", strerror(errno)); //prints error message
    }
  }
  else {
    char input[100];
    fgets(input, 100, stdin);
    input[strlen(input)-1] = '\0'; //remove trailing \n character
    if (scan_dir(input)) {
      printf("%s\n", strerror(errno));
    }
  }

  printf("tree of current directory:\n");
  rescan_dir(".");


  printf("tree of directory requested by user:\n");
  if (argc > 1)
  {
    if(rescan_dir(argv[1])) { //if directory was not found
      printf("%s\n\n", strerror(errno)); //prints error message
    }
  }
  else if (argc)
  {
    char input[100];
    fgets(input, 100, stdin);
    input[strlen(input)-1] = '\0'; //remove trailing \n character
    if (rescan_dir(input)) {
      printf("\n%s\n\n", strerror(errno));
    }
  }


  return 0;

}
