#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigsegv_handler(int signum) {
	printf("\n segmentation fault (SIGSEGV) caught .Exiting \n");
	exit(signum);
}

int main() {
	if(signal(SIGSEGV,sigsegv_handler)==SIG_ERR) {
		perror("signal");
        	exit(EXIT_FAILURE);
	}

	//cause a segmentation fault(accessing null pointer)
	int *ptr = NULL;
	*ptr = 10;

	exit(EXIT_SUCCESS);

}
