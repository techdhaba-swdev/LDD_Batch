#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler for SIGSEGV
void sigsegv_handler(int signum) {
    printf("Segmentation fault (SIGSEGV) occurred. Exiting program.\n");
    exit(EXIT_FAILURE);
}

int main() {
    // Register the signal handler for SIGSEGV
    if (signal(SIGSEGV, sigsegv_handler) == SIG_ERR) {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    // Accessing NULL pointer to cause segmentation fault
    int *ptr = NULL;
    *ptr = 10; // Causes segmentation fault

    // This line will not be reached due to the segmentation fault
    printf("This line will not be executed\n");

    return 0;
}
