#include<stdio.h>
#include<signal.h>

void sigsegv_handler(int signum){

	printf("this is sigsegv occures for segmentation fault value is %d\n",signum);
	exit(signum);

}

int main(){

	signal(SIGSEGV,sigsegv_handler);

	int *ptr=NULL;
	*ptr=10;

	return 0;

}

