#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Signal handler for SIGUSR1
void sigusr1_handler(int signum) {
    printf("Custom signal SIGUSR1 received.\n");
}

int main() {
    // Register the signal handler for SIGUSR1
    if (signal(SIGUSR1, sigusr1_handler) == SIG_ERR) {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    printf("Program started. Press Ctrl+C to exit.\n");

    // Loop to periodically generate SIGUSR1 signal
    while (1) {
        // Sleep for 2 seconds
        sleep(2);
        
        // Generate SIGUSR1 signal
        if (kill(getpid(), SIGUSR1) == -1) {
            perror("kill");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
