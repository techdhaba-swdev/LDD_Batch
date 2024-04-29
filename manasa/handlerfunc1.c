#include <stdio.h>
#include <signal.h>

int num1, num2;

void add() {
    printf("Enter two numbers to add: ");
    scanf("%d %d", &num1, &num2);
    printf("Result of addition: %d\n", num1 + num2);
}

void subtract() {
    printf("Enter two numbers to subtract: ");
    scanf("%d %d", &num1, &num2);
    printf("Result of subtraction: %d\n", num1 - num2);
}

void sigint_handler(int signum) {
    add();
}

void sigtstp_handler(int signum) {
    subtract();
}

int main() {
	signal(SIGINT, SIG_IGN);
	signal(SIGALRM, SIG_DFL);
    signal(SIGINT, sigint_handler);
    signal(SIGTSTP, sigtstp_handler);

    printf("Press Ctrl+C to add two numbers and Ctrl+Z to subtract two numbers.\n");

    while (1) {
        // Loop indefinitely, waiting for signals
    }

    return 0;
}

