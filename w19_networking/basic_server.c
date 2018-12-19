#include "pipe_networking.h"


int main() {

    signal(SIGINT, sighandler);

    int to_client;
    int from_client;

    while (1) {
        from_client = server_handshake( &to_client );
        // printf("from_client: %d\n", from_client);

        char data[BUFFER_SIZE];
        // get data from client
        while(read(from_client, data, BUFFER_SIZE)) {
            printf("[server] received: %s", data);
            // process data
            to_upper(data);
            // reply to client
            int w = write(to_client, data, BUFFER_SIZE);
        }
        // when client exits, reset
        close(to_client);
        close(from_client);
    }
}

static void sighandler(int signo) {
    if (signo == SIGINT) {
        remove("main");
        printf("wkp removed\n");
        exit(0);
    }
}
