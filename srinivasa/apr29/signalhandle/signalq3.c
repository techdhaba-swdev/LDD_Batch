#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
void signal_handle(int signum)
{
	printf("custem signal is generated");
}
int main ()
{
	signal(SIGUSR1, signal_handle);
	while(1)
	{
		printf("generating custom signaln\n");
		raise(SIGUSR1);
		sleep(5);

	}
	return 0;
}
