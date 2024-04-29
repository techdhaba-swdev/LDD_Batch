#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

int n1, n2;

int signal_var =0; //Ensures that no operation has been performed by the signal handler 

void sigint_handler(int signum) { //SIGINT: requests the prog with CTRL+C interrupts the execution and terminates it.
    if (signal_var == 0) {
        printf(" enter two numbers:\n");
        printf("Number 1: ");
        scanf("%d", &n1);
        printf("Number 2: ");
        scanf("%d", &n2);
        printf(" addition: %d\n", n1 + n2);
        signal_var = 1; //the addition has been performed
    }
}

void sigtstp_handler(int signum) { //SIGSTP: use to temporarily suspend a code/process and it can be resumed later.
    if (signal_var == 0) {
        printf(" enter two numbers:\n");
        printf("Number 1: ");
        scanf("%d", &n1);
        printf("Number 2: ");
        scanf("%d", &n2);
        printf("subtraction: %d\n", n1 - n2);
        signal_var = 1;
    }
}

int main() {
    signal(SIGINT, SIG_IGN);
    signal(SIGTSTP, sigtstp_handler); //register both the signal handler function

    printf("Press Ctrl+C to add two numbers or Ctrl+Z to subtract two numbers.\n");

    while (1) { //prog enters an infinte loop continuously checking for changes in the  variable
        if (signal_var == 1) 
       	{
            signal_var  = 0;
            printf("\nPress Ctrl+C to add two numbers or Ctrl+Z to subtract two numbers.\n");

	    
        }
    }

    return EXIT_SUCCESS;
}


