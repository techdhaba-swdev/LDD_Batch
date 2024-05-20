#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function
void signal_handler(int signum) {
    if (signum == SIGUSR1) {
        printf("Custom signal (SIGUSR1) received.\n");
    }
}

int main() {
    // Register signal handler for SIGUSR1
    if (signal(SIGUSR1, signal_handler) == SIG_ERR) {
        perror("Unable to set up signal handler");
        return 1;
    }

    printf("Sending SIGUSR1 signal every 2 seconds.\n");

    // Periodically send SIGUSR1 signal every 2 seconds
    while (1) {
        kill(getpid(), SIGUSR1);
        sleep(2);
    }

    return 0;
}


