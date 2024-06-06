#include<stdio.h>
#include <signal.h>
#include<stdlib.h>

void sigint_handler(int signum) {
	printf("Exit from the terminal...\n");
	exit(signum);
}

int main() {
	signal(SIGINT, sigint_handler);

	while(1) {
		printf("Message has been printed\n");
	}

	return EXIT_SUCCESS;
}
