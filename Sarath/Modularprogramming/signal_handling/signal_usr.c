#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void signal_handler(int signum)
{
	if(signum==SIGUSR1)
	{
		printf("\tFound sigusr\n");
	}
}
int main()
{
	signal(SIGUSR1,signal_handler);
	while(1)
	{

		kill(getpid(),SIGUSR1);
		sleep(2);
	}
	return 0;
}
