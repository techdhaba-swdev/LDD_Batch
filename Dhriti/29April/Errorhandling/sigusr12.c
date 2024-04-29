#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int num1, num2;
volatile sig_atomic_t flag = 0;

void sigint_handler(int signum) {
    if (flag == 0) {
        printf("\nPlease enter two numbers:\n");
        printf("Number 1: ");
        scanf("%d", &num1);
        printf("Number 2: ");
        scanf("%d", &num2);
        printf("Result of addition: %d\n", num1 + num2);
        flag = 1;
    }
}

void sigtstp_handler(int signum) {
    if (flag == 0) {
        printf("\nPlease enter two numbers:\n");
        printf("Number 1: ");
        scanf("%d", &num1);
        printf("Number 2: ");
        scanf("%d", &num2);
        printf("Result of subtraction: %d\n", num1 - num2);
        flag = 1;
    }
}

int main() {
    signal(SIGINT, sigint_handler);
    signal(SIGTSTP, sigtstp_handler);

    printf("Press Ctrl+C to add two numbers or Ctrl+Z to subtract two numbers.\n");

    while (1) {
        if (flag == 1) {
            flag = 0;
            printf("\nPress Ctrl+C to add two numbers or Ctrl+Z to subtract two numbers.\n");
        }
    }

    return 0;
}
