#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function for SIGUSR1
void sigusr1_handler(int signum) {
    printf("Caught SIGUSR1 (%d)\n", signum);
    printf("Exiting...\n");
    exit(EXIT_SUCCESS);
}

// Signal handler function for SIGUSR2
void sigusr2_handler(int signum) {
    printf("Caught SIGUSR2 (%d)\n", signum);
    // Custom handling for SIGUSR2
    // For example, continue program execution
    printf("Continuing program execution...\n");
}

int main() {
    // Register the signal handler for SIGUSR1
    signal(SIGUSR1, sigusr1_handler);

    // Register the signal handler for SIGUSR2
    signal(SIGUSR2, sigusr2_handler);

    printf("Signal handlers registered for SIGUSR1 and SIGUSR2.\n");

    // Loop indefinitely
    while (1) {
        // Do something...
        sleep(1); // Sleep for 1 second
    }

    return 0;
}
