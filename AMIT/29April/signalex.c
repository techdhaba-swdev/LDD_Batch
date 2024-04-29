#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int a,b;

void handle_sigint(int signum)       
{
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Addition: %d\n", a + b);
}

void handle_sigtstp(int signum)
{
    printf("Substraction : %d\n", a - b);
}

int main()
{
    signal(SIGINT, handle_sigint);   
    signal(SIGTSTP, handle_sigtstp); 

    printf("Press Ctrl+C to add numbers and Ctrl+Z to subtract numbers.\n");

    while (1)
    {
        // Do nothing
    }

    return 0;
}
