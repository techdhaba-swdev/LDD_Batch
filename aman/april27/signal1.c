#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
 

void sigint_handler(int signum) {
    printf("Caught SIGINT signal\n");
    exit(signum);
}
 
void sigterm_handler(int signum) {
    printf("Caught SIGTERM signal\n");
    exit(signum);
}
 
void sigsegv_handler(int signum) {
    printf("Caught SIGSEGV signal (Segmentation fault)\n");
    exit(signum); 
}
 
int main() {
    
    signal(SIGINT, sigint_handler);
    signal(SIGTERM, sigterm_handler);
    signal(SIGSEGV, sigsegv_handler);
 
    printf("Running... Press Ctrl+C to interrupt\n");
    int *ptr = NULL;
    *ptr = 10;
    printf("This line will not be executed\n");
 
    return 0;
}
