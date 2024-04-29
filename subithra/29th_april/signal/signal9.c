#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigint_handler(int signum) {
    printf("\nCtrl+C pressed. Exiting program.\n");
    exit(EXIT_SUCCESS);
}

int main() {
    signal(SIGINT, sigint_handler);

    printf("Press Ctrl+C to exit.\n");
    while (1) {
    
    }

    return 0;
}
