#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigint_handler(int signum){
	printf("caught SIGINT signal . exit gracefull .\n");
	exit(signum);
}

int main() {
	signal(SIGINT,sigint_handler); // registering signl handler
	printf("press the ctrl+c to trigger SIGINT signal \n");

	while(1) {
		// infinite loop 
	}
	return 0;
}
