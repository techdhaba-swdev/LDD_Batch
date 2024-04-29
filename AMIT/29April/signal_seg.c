#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler for SIGSEGV (segmentation fault)
void handle_sigsegv(int signum)
{
    printf("Error: Segmentation fault occurred. Exiting gracefully.\n");
    exit(EXIT_FAILURE);
}

int main() {
                                             // set  the signal handler for SIGSEGV
    signal(SIGSEGV, handle_sigsegv);

    // Access an invalid memory location (causing segmentation fault)
    int* ptr = NULL;
    *ptr = 42; // This will trigger a segmentation fault

    // The program will never reach this point due to the segmentation fault

    return 0;
}
