#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {

  srand(time(NULL));

  printf("The parent process has begun...\n");

  printf("Forking first child...\n");

  int child0, child1 = 0;
  child0 = fork();
  
  //only parent forks a second child
  if (child0) {
    printf("Forking second child...\n");
    child1 = fork();
  }

  //if parent 
  if (child1) {
  	int status;
  	//get pid of child that exited first
  	int child_pid = wait(&status);
  	//get return value of child that exited
  	int child_num = WEXITSTATUS(status);
  	printf("child %d slept for %d seconds and exited first\n", child_pid, child_num);
  	printf("This is the end of the parent process!\n");
  }

  //if children
  else {
  	printf("\tI'm a child and my pid is %d\n", getpid());
  	int num = rand() % 16 + 5;

  	//second child needs a different random number
  	if (child0) {
  		num = rand() % 16 + 5;
  	}

  	sleep(num);
  	printf("\tThis is the end of child process %d after sleeping for %d seconds\n", getpid(), num);
    return num;
  }


  return 0;

}
