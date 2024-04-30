#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void sigsegv_handler(int signum){
	printf("segmentation fault occured.\n");
	exit(EXIT_FAILURE);
}
int main(){
	signal(SIGSEGV, sigsegv_handler);
	int *ptr = NULL;
	*ptr = 10;
	printf("this  code will not be executed due to segmentation fault.\n");
	return(EXIT_SUCCESS);
}

