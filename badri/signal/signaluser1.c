#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void user1_handler()
{
	printf("CAUGHT SIGUSER1 \n");

}

void handler()
{
	printf("program exit\n");
}
int main()
{
	signal(SIGUSR1 , user1_handler);
	printf("PID : %d\n" , getpid());
	signal(SIGTSTP , handler);
	printf("enter ctrl+z to exit program");
	printf("send SIGUSER1 to the process to trigger signal handlers\n");
	while(1)
	{
		sleep(3);
		
	}
	return 0; 
}
