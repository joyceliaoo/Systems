#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args(char * line)
{
  char ** arr = malloc(5 * sizeof(char *));
  int counter = 0;

  while (line)
  {
    arr[counter] = malloc(256);
    char *s = strsep(&line, " ");
    strcpy(arr[counter], s);
    counter++;
  }

  arr[counter] = NULL;

  return arr;
}

int main()
{
  printf("executing ls -a -l: \n");
  char ln[100] = "ls -a -l";
  char ** parsed = parse_args(ln);
  execvp(parsed[0], parsed);

  return 0;
}
