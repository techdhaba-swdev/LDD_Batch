#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

//Signal handler function
 void sigint_handler(int signum) {
	 printf("Caught SIGINT (%d)\n",signum);
	 //custom handling for sigint
	 //for example,cleanup or graceful shutdowun
	 exit(signum);
 }
int main() {
	//Define the struct for the signal action
	//signal(sigint , sigint_handler);
	struct sigaction sa;
	sa.sa_handler = sigint_handler;//set the signal handler function
	sigemptyset(&sa.sa_mask);//clear the signal mask
	sa.sa_flags=0; //No special flags
		      
//Registering the signal handler for SIGINT
if(sigaction(SIGINT,&sa,NULL)==-1) {
	perror("sigaction");
	exit(EXIT_FAILURE);
}
printf("signal handler registerd for SIGINT.press ctrl+c to trigger.\n");

//Loop indefinetely
while(1) {
//Do something
}
return 0;
}
