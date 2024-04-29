#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void handle_sigint(int sig)
	{
	printf(" program stopped\n");
	exit(0);
	}

int main()
	{
		signal(SIGINT , handle_sigint);
		printf("enter ctl+c to exit program\n");
		while(1)
			{

			}
		return 0;
	}



