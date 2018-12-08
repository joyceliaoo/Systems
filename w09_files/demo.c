#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {

  //creates new file, giving it read and write permissions
  int fd = open("new.txt", O_RDWR | O_CREAT);

  printf("fd: %d \n", fd); 

  //writes to file
  int w = write(fd, "Hello World! \n", strlen("Hello World! \n"));

  printf("%d bytes written \n", w);

  //closes file represented by fd
  if (!close(fd)) printf("file closed!\n");
  else printf("error \n");

  fd = open("new.txt", O_RDONLY);
  printf("fd: %d \n", fd);

  //reads a file
  char *c = calloc(100, sizeof(char));
  int r = read(fd, c, 20);

  printf("%d bytes read \n", r);

  c[r] = '\0';

  printf("file content: %s \n", c);

  close(fd);

  return 0;

}

