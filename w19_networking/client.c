#include "pipe_networking.h"


int main() {

    int to_server;
    int from_server;

    from_server = client_handshake( &to_server );

    char data[BUFFER_SIZE];
    while (1) {
        // gets input from user
        printf("Enter message: ");
        fgets(data, BUFFER_SIZE, stdin);
        // sends to server
        int w = write(to_server, data, BUFFER_SIZE);
        // printf("w: %d\n", w);
        // gets reponse from server
        int r = read(from_server, data, BUFFER_SIZE);
        // displays response
        printf("[client] received: %s", data);
    }
}
