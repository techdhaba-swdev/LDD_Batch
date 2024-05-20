#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigint_handler(int signum) {
	printf("caught SIGINT (%d)\n ", signum);
    exit(signum); // Exit with the signal number
}

int main() {
    struct sigaction sa;

    sa.sa_handler = sigint_handler; // Set the signal handler function
    sigemptyset(&sa.sa_mask); // Clear the signal mask
    sa.sa_flags = 0; // No special flags

    // Register the signal handler for SIGINT
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Signal handler registered for SIGINT. Press Ctrl+C to trigger.\n");

    // Loop indefinitely
    while (1) {
    }

    return 0; // This line is added to indicate successful program termination
}                                                                                                                                        
