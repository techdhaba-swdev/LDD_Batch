#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigsegv_handler(int signum) {
    printf("Segmentation fault occurred. Exiting program.\n");
    exit(EXIT_FAILURE);
}

int main() {
    signal(SIGSEGV, sigsegv_handler);
    int *ptr = NULL;
    *ptr = 5; 
    return 0;
}
