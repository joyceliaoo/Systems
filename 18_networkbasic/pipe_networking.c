#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client

  Performs the server side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {
    // create well known pipe
    int wkp = mkfifo("main", 0644);
    if (wkp == - 1) printf("error %d: %s\n", errno, strerror(errno));
    else printf("wkp has been created!\n");
    // wait
    int receive = open("main", O_RDONLY);
    // receive msg
    char msg[HANDSHAKE_BUFFER_SIZE];
    int r = read(receive, msg, HANDSHAKE_BUFFER_SIZE);
    printf("received message from client!\n");
    printf("first client msg: %s\n", msg);
    // rm wkp
    remove("main");
    printf("wkp has been removed\n");
    // connects to private fifo
    *to_client = open(msg, O_WRONLY);
    // send initial msg
    int w = write(*to_client, ACK, HANDSHAKE_BUFFER_SIZE);
    // get response from client
    r = read(receive, msg, HANDSHAKE_BUFFER_SIZE);
    printf("second msg from client: [%s]\n", msg);
    // return fd to wkp
    printf("3 way handshake is done\n");
    return receive;
}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
    // create private fifo
    char pipe_name[HANDSHAKE_BUFFER_SIZE];
    sprintf(pipe_name, "%d", getpid());
    int private = mkfifo(pipe_name, 0644);
    printf("private pipe created!\n");
    // set to_server to wkp
    *to_server = open("main", O_WRONLY);
    if (*to_server == - 1) printf("error %d: %s\n", errno, strerror(errno));
    // sends private fifo name to server
    int w = write(*to_server, pipe_name, HANDSHAKE_BUFFER_SIZE);
    if (w == - 1) printf("error %d: %s\n", errno, strerror(errno));
    else printf("private pipe name sent to server\n");
    // wait for response
    int receive = open(pipe_name, O_RDONLY);
    // receive server msg
    char msg[HANDSHAKE_BUFFER_SIZE];
    int r = read(receive, msg, HANDSHAKE_BUFFER_SIZE);
    printf("msg received from server: [%s]\n", msg);
    // remove private fifo
    remove(pipe_name);
    printf("private pipe has been removed\n");
    // send response to server
    w = write(*to_server, ACK, HANDSHAKE_BUFFER_SIZE);
    // return fd to private fifo
    return receive;
}
