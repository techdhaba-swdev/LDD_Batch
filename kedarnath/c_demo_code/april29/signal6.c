#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigsegv_handler(int signum) {
    printf("Caught SIGSEGV signal %d: Segmentation fault (invalid memory access)\n", signum);
    exit(signum);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = sigsegv_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Signal handler registered for SIGSEGV. To simulate a segmentation fault, accessing invalid memory...\n");

    // Simulating a segmentation fault by accessing invalid memory
    int *ptr = NULL;
    *ptr = 10; // This will cause a segmentation fault

    // Program continues running if the segmentation fault is not encountered.
    return 0;
}




