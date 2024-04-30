#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void signal_handler(int signum)
{
	int a=7,b=3;
	if(signum==SIGINT)
	{
		printf("Add is %d\n",a+b);
	}
	if(signum==SIGTSTP)
	{
		printf("Sub is %d\n",a-b);
	}
}

int main()
{
	//signal(SIGINT,SIG_IGN);
	if(signal(SIGINT,signal_handler)==SIG_ERR)
	{
		perror("Error sigint\n");
		exit(EXIT_FAILURE);
	}
	if(signal(SIGTSTP,signal_handler)==SIG_ERR)
	{
		perror("Error sigterm\n");
		exit(EXIT_FAILURE);
	}
	printf("This World is Waiting for your Signals!!!\n");
	while(1)
	{
	}

	return 0;
}
