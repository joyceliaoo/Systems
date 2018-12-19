#include "pipe_networking.h"

void to_upper(char * data) {
    int i = 0;
    while (data[i]) {
        if (i%2) {
            // convert to uppercase
            data[i] = toupper(data[i]);
        }
        i++;
    }
}
