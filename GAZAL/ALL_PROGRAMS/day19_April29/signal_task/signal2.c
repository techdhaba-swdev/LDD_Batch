#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigsegv_handler(int signum) {
    printf("Segmentation fault occurred. Exiting...\n");
    exit(EXIT_FAILURE); // Exit the program with failure status
}

int main() {
    // Register signal handler for SIGSEGV
    if (signal(SIGSEGV, sigsegv_handler) == SIG_ERR) {
        perror("Unable to set signal handler for SIGSEGV");
        return EXIT_FAILURE;
    }

    // Attempt to access invalid memory
    int *ptr = NULL;
    *ptr = 10; // This will cause a segmentation fault

    printf("This line will not be executed.\n");

    return 0;
}
