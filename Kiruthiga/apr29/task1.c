#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// Signal handler function
void signal_handler(int signum) {
    printf("\nCaught SIGINT: Exiting the program.\n");
    exit(EXIT_SUCCESS);
}

int main() {
    // Register signal handler for SIGINT
    if (signal(SIGINT, signal_handler) == SIG_ERR) {
        perror("Unable to set up signal handler");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for Ctrl+C to exit...\n");

    // Infinite loop to keep the program running
    while (1) {}

    return 0;
}



