#include<stdio.h>
#include<signal.h>

void sigint_handler(int signum){

	printf("this is sigint to press ctrl+c value is %d\n",signum);
	exit(signum);

}

int main(){

	signal(SIGINT,sigint_handler);

	while(1){

	}

	return 0;

}

