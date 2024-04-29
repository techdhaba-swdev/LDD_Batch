#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

//signal handler function for SIGINT (ctrl+c)
 void sigint_handler(int signum){
	 printf("\n ctrl+c presed. existing gracefully.\n");
	 exit(signum);
 }
int main(){
	signal(SIGINT,sigint_handler);

	printf("press ctrl+c to exit .\n");

	while(1){
		//program continues its normal operation
	}
	return 0;
}
