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

int printbytes(char * target, int total)
{
  if(total<1000)
  {
    printf("total size of files in %s: %d bytes\n\n", target, total);
  }
  else if(1000<=total<1000000)
  {
    float kb = (float)total/1000.0;
    printf("total size of files in %s: %f kb\n\n", target, kb);

  }
  else if(1000000<=total<1000000000)
  {
    float mb = (float)total/1000000.0;
    printf("total size of files in %s: %f mb\n", target, mb);
  }
  else if(1000000000<=total)
  {
    double gb = (double)total/1000000000.0;
    printf("total size of files in %s: %f gb\n", target, gb);
  }
}

int scan_dir(char *target) {
  int total = 0;

  char *directories[25];
  char *files[100];
  int dir_count = 0;
  int file_count = 0;

  DIR *dir = opendir(target);
  if (!dir) return 1; //if failed to open directory

  struct dirent *current_file = readdir(dir);

  while (current_file) {
    int type = current_file->d_type;

    if (current_file->d_type == DT_REG) {
      files[file_count] = current_file->d_name;
      file_count++;

      char path[30];
      strcpy(path, target);
      strcat(path, "/");
      strcat(path, current_file->d_name);
      struct stat *info = malloc(sizeof(struct stat));
      stat(path, info);
      total += info->st_size;
      free(info);
    }

    else {
      directories[dir_count] = current_file->d_name;
      dir_count++;
    }

    current_file = readdir(dir);
  }

  printf("\n");
  printf("directory info for %s: \n", target);
  printf("\n");

  printf("dir count: %d, file count: %d \n", dir_count, file_count);
  printf("\n");

  printf("Directories: \n");
  for (int i = 0; i < dir_count; i++)
    {
      printf("\t%s\n", directories[i]);
    }

  printf("Files: \n");
  for (int i = 0; i < file_count; i++)
    {
      printf("\t%s\n", files[i]);
    }

  printf("\n");

  printbytes(target, total);
  //printf("total size of files in %s: %d bytes\n\n", target, total);

  closedir(dir);

  return 0; //successfully scanned directory
}

int rescan_dir(char * target)
{
  DIR * dir = opendir(target);
  if (!dir)
  {
    return 1;
  }

  printf("%s\n", target);
  int total = helper(target, "");
  //printf("total: %d bytes\n", total);
  printbytes(target, total);
  return 0;
}

int helper(char * target, char * prefix)
{
  int total = 0;

  DIR * dir = opendir(target);
  struct dirent * current_file = readdir(dir);

  while (current_file)
  {
    int type = current_file->d_type;

    printf("%s├── %s\n", prefix, current_file->d_name);
    if (current_file->d_type == DT_DIR &&
        strcmp(".", current_file->d_name) != 0 &&
        strcmp("..", current_file->d_name) != 0)
    {

      char nprefix[256];
      strcpy(nprefix, prefix);
      strcat(nprefix, "│   ");

      char ntarget[256];
      strcpy(ntarget, target);
      strcat(ntarget, "/");
      strcat(ntarget, current_file->d_name);
      total += helper(ntarget, nprefix);
    }
    else
    {
      char path[30];
      strcpy(path, target);
      strcat(path, "/");
      strcat(path, current_file->d_name);
      struct stat * info = malloc(sizeof(struct stat));
      stat(path, info);
      total += info->st_size;
      free(info);
    }

    current_file = readdir(dir);
  }

  return total;
}
