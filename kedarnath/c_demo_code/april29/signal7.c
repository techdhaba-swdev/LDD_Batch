#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigalrm_handler(int signum) {
    printf("Caught SIGALRM signal %d: Timeout occurred\n", signum);
    // Add custom timeout handling here if needed
}

int main() {
    struct sigaction sa;
    sa.sa_handler = sigalrm_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Signal handler registered for SIGALRM. Setting a timer for 5 seconds...\n");

    // Set a timer for 5 seconds
    alarm(5);

    // Do some work here...
    printf("Waiting for timeout or interrupt...\n");

    // Program continues running until timeout or interrupt
    while (1) {
        // Do some work or wait for input...
    }

    return 0;
}




