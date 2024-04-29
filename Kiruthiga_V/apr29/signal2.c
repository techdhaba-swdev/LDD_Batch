#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
 void sigint_handler(int signum)
 {
     //custom handling for SIGINT
     //For example, cleanup or graceful shutdown
 	printf("caught SIGINT(%d)\n",signum);
 	exit(signum);
 }
 int main()
 {
 	struct sigaction sa; //define the struct for the signal action // signal(SIGINT, sigint_handler)
 	sa.sa_handler = sigint_handler;
 	sigemptyset(&sa.sa_mask);
 	sa.sa_flags = 0;
 	
 	//register the signal handler for SIGINT
 	if(sigaction(SIGINT, &sa, NULL) == -1)
 	{
 		perror("sigaction");
 		exit(EXIT_FAILURE);
 	}
 	printf("Signal handler registered for SIGINT. Press Ctrl+C to trigger.\n");
 	
 	//loop indefinitely
 	while(1)
 	{
 		//do something
 	}
 	return 0;
 }
