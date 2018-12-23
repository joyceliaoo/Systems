#include "pipe_networking.h"


int main() {

    signal(SIGINT, sighandler);

    while (1) {
        // create well known pipe
        int mk_wkp = mkfifo("main", 0644);
        if (mk_wkp == - 1) {
            printf("error %d: %s\n", errno, strerror(errno));
            return 1;
        }
        else printf("[server] wkp has been created!\n");
        // wait
        int wkp = open("main", O_RDONLY);
        // receive msg
        char msg[HANDSHAKE_BUFFER_SIZE];
        read(wkp, msg, HANDSHAKE_BUFFER_SIZE);
        printf("[server] received message:[%s]\n", msg);

        // fork subserver
        int f = fork();

        if (f) { // parent
            // rm wkp
            remove("main");
            close(wkp);
            printf("[server] wkp has been removed\n");

        }
        else { // subserver
            int to_client;
            int from_client;

            from_client = wkp;
            server_handshake( from_client, &to_client, msg );
            // printf("from_client: %d\n", from_client);

            char data[BUFFER_SIZE];
            // get data from client
            while(read(from_client, data, BUFFER_SIZE)) {
                printf("[subserver %d] received: %s", getpid(), data);
                // process data
                to_upper(data);
                // reply to client
                int w = write(to_client, data, BUFFER_SIZE);
            }

            close(to_client);
            close(from_client);
            printf("[subserver %d] session closed\n", getpid());
            return 0;
        }
    }

    return 0;
}

static void sighandler(int signo) {
    if (signo == SIGINT) {
        remove("main");
        printf("wkp removed\n");
        exit(0);
    }
}
