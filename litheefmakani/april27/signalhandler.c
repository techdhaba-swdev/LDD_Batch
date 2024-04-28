//program to illustrate user-defined signal handler
#include<stdio.h>
#include<signal.h>
//handle for SIGNT ,caused by 
//ctrl c keyboard 
void handle_sigint(int sig){
       printf("caught signal %d\n",sig);
}

int main(){
	signal(SIGINT,handle_sigint);
	while(1){
		//do nothing ,waiting for signal
	}
	return 0;
}
