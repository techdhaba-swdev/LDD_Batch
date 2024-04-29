#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigusr1_handler(int sig)
{
	printf("caught SIGUSR1 \n");
}
void siguser2_handler(int sig)
{
	printf("caught SIGUSR2 \n");
}


int main()
{
	signal(SIGUSR1 , sigusr1_handler);
	signal(SIGUSR2 , sigusr2_handler);

	printf("PID: %d\n" , getpid());
	printf("send SIGUSR1 OR SIGUSR2 to this process to trigger signal handlers\n");

	while(1)
	{
		
		sleep(3);
	}
	return 0;
}

