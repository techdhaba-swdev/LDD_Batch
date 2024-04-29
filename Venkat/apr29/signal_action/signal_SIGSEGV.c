#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigsegv_handler(int signum) {
	printf("caught SIGSEGV signal \n");
	printf("segmentation erro\n");
	exit(signum);
}

int main() {
	signal(SIGSEGV, sigsegv_handler); // resgistering SIGSEGV handler 
	int *ptr = NULL; // null pointer 
	*ptr = 5 ; // i try to dereference ptr to access the memory location by the way ptr point to nothing
		   // leads to segmentation falut
        return 0;
}
