#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int * ran_gen() {
	int *arr = malloc(10*sizeof(int));

	int fd = open("//dev/random", O_RDONLY);
	//printf("fd of random : %d \n", fd);

	int *buff = malloc(10*sizeof(int));
	int r = read(fd, buff, 10*sizeof(int)); //read 10 ints from dev/random

	//printf("%d bytes read from random \n", r);

	//transfer random nums from buffer to array
	for (int i = 0; i < 10; i++) {
		arr[i] = buff[i];
		//printf("num %d: %d \n", i, arr[i]);
	}

	free(buff);
	return arr;

}

int main() {
	int *num = ran_gen();

	printf("numbers generated: \n");
	for (int i = 0; i < 10; i++) {
		printf("num %d: %d \n", i, num[i]);
	}

	int fd = open("num.txt", O_RDWR);

	printf("\nwrite random numbers to file");
	int w = write(fd, num, 10*sizeof(int));

	printf(" (%d bytes written) \n\n", w);

	close(fd); //close file to save changes

	fd = open("num.txt", O_RDONLY);

	printf("read numbers from file \n");
	int buff[10];
	int r = read(fd, buff, 10*sizeof(int));

	printf("%d bytes read \n\n", r);

	printf("numbers read from file (verification): \n");
	for (int i = 0; i < 10; i++) {
		printf("num %d: %d \n", i, buff[i]);
	}

	free(num);
	return 0;
}
