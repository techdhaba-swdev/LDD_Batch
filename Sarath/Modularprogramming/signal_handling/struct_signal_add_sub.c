#include<stdlib.h>
#include <stdio.h>
#include<signal.h>
void signal_handler(int signum)
{
    int a=7,b=3;
    if(signum==SIGINT)
    {
        printf("Addition is %d\n",a+b);
    }
    if(signum==SIGTSTP)
    {
        printf("Subtraction is %d\n",a-b);
    }
}
int main()
{
    struct sigaction sa;
    sa.sa_handler=signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags=0;
    if(sigaction(SIGINT,&sa,NULL)==-1)
    {
        perror("interuption signal\n");
        exit(EXIT_FAILURE);
    }
    if(sigaction(SIGTSTP,&sa,NULL)==-1)
    {
        perror("interuption signal\n");
        exit(EXIT_FAILURE);
    }
    printf("Machine is Waiting for signals!!!!\n");
    while(1)
    {
    }
    return 0;
}
