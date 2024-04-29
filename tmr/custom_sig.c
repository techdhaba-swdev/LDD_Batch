#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void sigint(int sig)
{
	if (sig==SIGINT)
	{
		printf("SIGINT signal");
		exit(EXIT_SUCCESS);
	}
	else if(sig ==SIGTSTP )
	{
		printf("periodic data");
	}
}

int main()
{
	signal(SIGINT,sigint);
	signal(SIGTSTP,sigint);

	while(1)
	{
		kill(getpid(),SIGTSTP);
	}
	return 0;
}
