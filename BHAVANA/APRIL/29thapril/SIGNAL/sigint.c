#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler for SIGINT
void sigint_handler(int signum) {
    printf("\nCtrl+C pressed. Exiting program.\n");
    exit(EXIT_SUCCESS);
}

int main() {
    // Register the signal handler for SIGINT
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    printf("Press Ctrl+C to exit.\n");

    // Infinite loop to keep the program running
    while (1) {
        // Do nothing, waiting for Ctrl+C signal
    }

    return 0;
}
