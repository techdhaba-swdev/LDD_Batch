#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int num1, num2;

void sigint_handler(int signum) {
    printf("\nCtrl+C pressed. Adding %d and %d: %d\n", num1, num2, num1 + num2);
    //exit(signum);
}

void sigtstp_handler(int signum) {
    printf("\nCtrl+Z pressed. Subtracting %d from %d: %d\n", num2, num1, num1 - num2);
    exit(signum);
}

int main() {
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
   // signal(SIGINT,SIG_IGN);
    signal(SIGINT,sigint_handler);
    signal(SIGTSTP, sigtstp_handler);

    printf("Press Ctrl+C to add the numbers and Ctrl+Z to subtract them.\n");

    while(1);

    return 0;
}

