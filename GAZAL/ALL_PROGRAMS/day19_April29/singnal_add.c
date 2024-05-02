#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int add_flag = 0;
int sub_flag = 0;

void signal_handler(int signum) {
    if (signum == SIGINT) {
        add_flag = 1;
    } else if (signum == SIGTSTP) {
        sub_flag = 1;
    }
}

int main() {
    
    if (signal(SIGINT, signal_handler) == SIG_ERR) {
        perror("Unable to set signal handler for SIGINT");
        return 1;
    }

    if (signal(SIGTSTP, signal_handler) == SIG_ERR) {
        perror("Unable to set signal handler for SIGTSTP");
        return 1;
    }

    int num1, num2;
//printf("Enter two numbers : ");
           // scanf("%d %d", &num1, &num2);

    while (1) {
        if (add_flag) {
            printf("Enter two numbers to add: ");
            scanf("%d %d", &num1, &num2);
            printf("Sum of %d + %d=%d\n",num1,num2, num1 + num2);
            add_flag = 0;
	     exit(EXIT_FAILURE);

        }

        if (sub_flag) {
            printf("Enter two numbers to subtract: ");
           scanf("%d %d", &num1, &num2);
            printf("Difference of %d - %d = %d",num1,num2, num1 - num2);
            sub_flag = 0;
	    exit(EXIT_FAILURE);
        }
    }

    return 0;
}
