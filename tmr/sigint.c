#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler function for SIGINT
void sigint_handler(int signal) {
    printf("Received SIGINT (Ctrl+C). Exiting gracefully.\n");
    exit(EXIT_SUCCESS); // Exit the program gracefully
}

int main() {
    // Registering the signal handler for SIGINT
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    printf("Press Ctrl+C to trigger SIGINT...\n");

    // Infinite loop to keep the program running until Ctrl+C is pressed
    while (1) {
        // Program logic goes here
    }

    return 0;
}
