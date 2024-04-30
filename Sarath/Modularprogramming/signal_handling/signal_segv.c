#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void signal_handler(int signum)
{
        printf("\tOOPSS!! SEGMENTATION FAULT OCCURED!!!\n");
        exit(1);
}
int main()
{
        signal(SIGSEGV,signal_handler);
	int *ptr=NULL;
        *ptr=7;
        printf("Enter ctrl+c to exit\n");
        return 0;
}

