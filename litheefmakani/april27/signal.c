#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
//signal handler functions 
void signal_handler(int signum){
	printf("caught SIGINT signal \n");
	//perform cleanup actions here if needed
	exit(signum);//terminate the program 
}
void sigterm_handler(int signum){
	printf("Caught SIGTERM signal\n");
	//perform cleanup actions here if needed
	exit(signum);//terminate the program
}
void sigsegv_handler(int signum){
	printf("Caught SIGSEGV signal (segmentation fault)\n");
	//perform cleanup actions here if needed
	exit(signum);//terminate the program 
}
int main(){
	//register signal handlers for SIGINT,SIGTERM, And SIGSEGV
	signal(SIGINT,signal_handler);
	signal(SIGTERM,sigterm_handler);
	signal(SIGSEGV,sigsegv_handler);
	printf("Running.. press Ctrl+C to interrupt\n");
	//Accessing NULL pointer to cause segmentation fault(SIGSEGV)
	int *ptr = NULL;
	*ptr = 10;
	//this code will not be reached due to the segmentation fault
	printf("This line will not be executed\n");
	return 0;
}
