#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client

  Performs the server side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
void server_handshake(int from_client, int *to_client, char *msg) {
    // connects to private fifo
    *to_client = open(msg, O_WRONLY);
    // send initial msg
    write(*to_client, msg, HANDSHAKE_BUFFER_SIZE);
    // get response from client
    read(from_client, msg, HANDSHAKE_BUFFER_SIZE);
    printf("[subserver %d] received message:[%s]\n", getpid(), msg);
    // return fd to wkp
    printf("[subserver %d] handshake completed\n", getpid());
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
    if (private == - 1) {
        printf("error %d: %s\n", errno, strerror(errno));
        return 1;
    }
    printf("[client] private pipe created!\n");
    // set to_server to wkp
    *to_server = open("main", O_WRONLY);
    if (*to_server == - 1) {
        printf("error %d: %s\n", errno, strerror(errno));
        remove(pipe_name);
        return 1;
    }
    // sends private fifo name to server
    int w = write(*to_server, pipe_name, HANDSHAKE_BUFFER_SIZE);
    printf("[client] private pipe name sent to server\n");
    // wait for response
    int read_end = open(pipe_name, O_RDONLY);
    // receive server msg
    char msg[HANDSHAKE_BUFFER_SIZE];
    int r = read(read_end, msg, HANDSHAKE_BUFFER_SIZE);
    printf("[client] received message: [%s]\n", msg);
    // remove private fifo
    remove(pipe_name);
    printf("[client] private pipe has been removed\n");
    // send response to server
    w = write(*to_server, ACK, HANDSHAKE_BUFFER_SIZE);
    // return fd to private fifo
    return read_end;
}
