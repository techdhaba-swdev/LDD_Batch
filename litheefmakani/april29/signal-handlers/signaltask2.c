#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

//signal handler function for SIGSEGV
void sigsegv_handler(int signum){
	printf("segmentation fault occured. exiting.\n");
	exit(signum);
}
int main(){
	signal(SIGSEGV,sigsegv_handler);
	printf("Accessing a NULL pointer to provoke a asegmentation fault.\n");
	//attemping to access a null pointer to provoke a segmentation fault
	int *ptr = NULL;
	*ptr= 10;//this will cause  a segmentation fault
	printf("this line will not be reached if segemenation fault occurs.\n");
	return 0;
}
