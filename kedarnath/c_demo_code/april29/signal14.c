#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void sigusr1_handler(int signum){

	printf("this is user created signal value is %d\n",signum);
	//exit(signum);
}
int main(){
	signal(SIGUSR1,sigusr1_handler);
	printf("PID: %d\n", getpid());
	while(1){
		//printf("generating usr1 signal\n");
		sleep(3);
		kill(getpid(),SIGUSR1);
		//raise(SIGUSR1);
	}
	return 0;
}

