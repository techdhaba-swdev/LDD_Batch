#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void sigsegv_handler(int signum) {
    printf("Segmentation fault occurred. Exiting the program.\n");
    exit(signum);
}

int main() {
    // Install sigsegv_handler as the handler for SIGSEGV
    signal(SIGSEGV, sigsegv_handler);

    // Cause a segmentation fault by accessing invalid memory
    int *ptr = NULL;
    *ptr = 10;

    // This line will not be reached if a segmentation fault occurs
    printf("Program continues after segmentation fault.\n");

    return 0;
}
