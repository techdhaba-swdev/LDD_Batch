#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<time.h>
void signal_handler(int signum)
{
	printf("Hakuna Matata!!!\n");
	exit(EXIT_SUCCESS);
}
int main()
{
	signal(SIGINT,signal_handler);
	printf("Enter ctrl+c to exit\n");
	while(1)
	{
		sleep(1);
	}
	return 0;
}
