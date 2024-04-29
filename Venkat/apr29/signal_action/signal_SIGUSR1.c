#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigusr1_handler(int signum){
	printf("caught SIGUSER1 signal\n");
}
int main() {
	signal(SIGUSR1,sigusr1_handler);  // register SIGUSR1 handler it will generate
        printf("%d\n",getpid());
	printf("gererated a custom signal\n"); 

	while(1) {
		printf("waiting for the signal\n");

		sleep(2);
		printf("generating the custom signal SIGUSR1\n");
		kill(getpid(),SIGUSR1); // generate the custom signal
	}
	return 0;
}
