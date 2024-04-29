#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler function for SIGUSR1
void sigusr1_handler(int signum) {
    printf("Caught SIGUSR1 (%d)\n", signum);
    // Custom handling for SIGUSR1
    // For example, logging or specific action
}

int main() {
    // Define the struct for the signal action
    struct sigaction sa;
    sa.sa_handler = sigusr1_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    // Register the signal handler for SIGUSR1
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Signal handler registered for SIGUSR1. Send SIGUSR1 to trigger.\n");

    // Loop indefinitely
    while (1) {
        // Do something...
    }

    return 0;
}
