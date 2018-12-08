#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

static void sighandler(int signo) {
  if (signo == SIGINT) {
    int fd = open("sig", O_WRONLY | O_APPEND);
    char msg[] = "program interrupted by SIGINT\n";
    int w = write(fd, msg, 30);
    if (w  == -1) {
      printf("%s\n", strerror(errno));
    }
    else {
      printf("SIGINT message successfully appended to file\n");
    }
    close(fd);
    exit(getpid());
  }

  if (signo == SIGUSR1) {
    printf("SIGUSR1 received, my parent process is %d\n", getppid());
  }
}


int main() {

  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while (1) {
    printf("the current process is %d \n", getpid());
    sleep(1);
  }

  return 0;

}

