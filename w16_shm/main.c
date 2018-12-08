#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define STR_LEN 200

int main() {
    //generate a key
    key_t key;
    key = ftok("makefile", 'J');

    // printf("key: %d\n", key);

    int sgid;
    char *segment;
    int detach;
    char input[STR_LEN];
    char new_seg = 1;

    while (1) {
        //get id to shared segment
        sgid = shmget(key, STR_LEN, 0644 | IPC_CREAT);
        //get pointer to segment specified by id
        segment = shmat(sgid, (void *) 0, 0);

        //if segment is newly created
        if (new_seg) printf("You have made a new segment!\n");
        //if segment was previously created
        else printf("segment content: %s", segment);

        new_seg = 0; //not a new segment for next loop unless it gets deleted
        input[0] = 0; //reset input

        //ask until the user answers y or n
        while (strcmp(input, "y") && strcmp(input, "n")) {
            // ask for user input
            printf("Do you wish to change the data in the segment? (y/n)\n>");
            fgets(input, STR_LEN, stdin);
            //remove trailing new line char
            input[strlen(input) - 1] = 0;

            // printf("input: %s %d\n", input, strcmp(input, "y"));
        }

        //if user wants to change string
        if (!strcmp(input, "y")) {
            printf("What do you wish to write to the segment?\n>");
            fgets(segment, STR_LEN, stdin);
            printf("You have written: \n%s", segment);
        }

        input[0] = 0;

        while (strcmp(input, "y") && strcmp(input, "n")) {
            //ask if user wants to delete segment
            printf("Do you wish to delete this segment? (y/n)\n>");
            fgets(input, STR_LEN, stdin);
            input[strlen(input) - 1] = 0;
        }

        //if user wants to delete
        if (!strcmp(input, "y")) {
            detach = shmdt((void*) segment); //detach from shared segment
            shmctl(sgid, IPC_RMID, NULL); //delete share segment
            new_seg = 1; //next loop will create new segment
            printf("segment has been deleted\n");
            printf("=========================\n");
        }
    }

    return 0;
}
