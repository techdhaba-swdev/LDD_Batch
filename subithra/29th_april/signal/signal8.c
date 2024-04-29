#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int num1 = 0, num2 = 0;


void sigint_handler(int signum) {
    printf("\nReceived SIGINT (Ctrl+C).Addition: %d + %d = %d\n", num1, num2, num1 + num2);
    exit(EXIT_SUCCESS);
}


void sigtstp_handler(int signum) {
    printf("\nReceived SIGTSTP (Ctrl+Z).Subtraction: %d - %d = %d\n", num1, num2, num1 - num2);
    exit(EXIT_SUCCESS);
}

int main() {
    
    signal(SIGINT, SIG_IGN);
    signal(SIGTSTP, sigtstp_handler);

    printf("Enter two numbers ");
    scanf("%d %d", &num1, &num2);
    while (1) {     
    }
    return 0;
}
