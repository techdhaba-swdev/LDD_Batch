#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// Signal handler function
void signal_handler(int signum) {
    if (signum == SIGSEGV) {
        printf("Segmentation fault occurred. Exiting the program.\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Register signal handler for SIGSEGV
    if (signal(SIGSEGV, signal_handler) == SIG_ERR) {
        perror("Unable to set up signal handler");
        exit(EXIT_FAILURE);
    }

    // Simulate segmentation fault
    int *ptr = NULL;
    *ptr = 10; // Accessing NULL pointer will cause a segmentation fault

    return 0;
}


