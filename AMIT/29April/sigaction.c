#include<stdio.h>
#include<stdlib.h>
#include<signal.h>


void sigint_handler(int signum)                       //signal handler function 
{
	printf("Caught SIGINT (%d)\n",signum);   //costum handling for SIGINT e.g cleanup or gracefull shutdown
	exit(signum);
}

int main()
{            //signal(SIGINT, sigint_handler)
	struct sigaction sa;                   //define the structure for signal action 
	sa.sa_handler=sigint_handler;          //set the signal_handler fn 
	sigemptyset(&sa.sa_mask);              //clear the signal mask
	sa.sa_flags=0;                         //no special flag

	if(sigaction(SIGINT , &sa,NULL)== -1)    //register the signal handler for SIGINT
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}

	printf("Signal handler register for SIGINT , press Ctrl+C to trigger,\n");

	while(1)  //loop indefinitely
	{
		//do nothing
	}
	return 0;
}

