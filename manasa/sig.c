#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigint_handler(int signum) {
    printf("\nCtrl+C pressed. Exiting the program gracefully.\n");
    exit(signum);
}

int main() {
    // Install sigint_handler as the handler for SIGINT
    signal(SIGINT, sigint_handler);

    printf("Press Ctrl+C to exit the program.\n");

    while (1) {
        // Loop indefinitely until Ctrl+C is pressed
    }

    return 0;
}
