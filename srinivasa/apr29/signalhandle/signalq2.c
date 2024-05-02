#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void signal_handler(int signum)
{
	printf("caught SIGSEGV signal : segmentation fault accurs");
	exit(signum);
}
int main()
{
	signal(SIGSEGV, signal_handler);
	int *ptr = NULL;
	*ptr = 10;
	// segementation fault  occures 
        return 0;
}
