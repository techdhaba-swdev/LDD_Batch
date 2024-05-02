#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void handle_signal(int signum)
{
	printf("user1 signal caught");
}
int main()
{
	signal(SIGUSR1, handle_signal);
	printf("PID : %d",getpid());
	while(1)
	return 0;
}
