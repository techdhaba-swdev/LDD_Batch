#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function for SIGALRM
void sigalrm_handler(int signum) {
    printf("Timer expired! Caught SIGALRM (%d)\n", signum);
    exit(EXIT_SUCCESS);
}

int main() {
    // Register the signal handler for SIGALRM
    signal(SIGALRM, sigalrm_handler);

    printf("Timer set for 5 seconds. Waiting...\n");

    // Set a timer for 5 seconds
    alarm(5);

    // Loop indefinitely
    while (1) {
        // Do something...
    }

    return 0;
}
