
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>


char * print_size(size_t file_size){
  char *size = malloc(sizeof(char) * 30);
  if (file_size < 1000)
	sprintf(size, "file size: %ld B\n", file_size);
  else if (file_size < 1000000)
	sprintf(size, "file size: %f KB\n", (float)(file_size%1000));
  else if (file_size < 1000000000)
	sprintf(size, "file size: %f MB\n", (float)(file_size%1000000));
  else
	sprintf(size, "file size: %f GB\n", (float)(file_size%1000000000));

  return size;

}

char * print_per(mode_t file_mode) {
	mode_t temp;
	char *result = malloc(sizeof(char)*9);
	for (int i = 0; i<=6; i+=3) {
		for (int j = 0; j<3; j++) {
			temp = file_mode >> i+j;
			if (temp) result[i+j] = 1;
			else result[i+j] = 0;
		}
	}
	for (int i =0; i<9; i++) {
		if(result[i]) {
			if (!(i%3)) result[i] = 'r';
			else if(i%3 == 1) result[i] = 'w';
			else result[i] = 'x';
		}
		else 
			result[i] = '-';
	}
	return result;
}

int main(){
  
  struct stat* hold = malloc(sizeof(struct stat)); 
  stat("file.txt", hold);

  //print basic info of a file
  printf("metadata of file.txt \n");
  printf("file size: %ld\n", hold->st_size);
  printf("user id: %d \ngroup id: %d\n", hold-> st_uid, hold-> st_gid);
  printf("file mode: %d\n", hold->st_mode);
  printf("last access: %slast mod: %s", ctime(&(hold->st_atime)), ctime(&(hold->st_mtime)));

  //print out size of file
  char *info = print_size(hold->st_size);
  printf("%s\n", info);
  free(info);

  //print permission of file
  mode_t mode = hold->st_mode;
  info = print_per(mode);
  printf("file permission of file.txt (0777): \n");
  for (int i = 0; i<9; i++) {
  	printf("%c", info[i]);
  }
  printf("\n");
  free(info);
  free(hold);
  return 0;
}
