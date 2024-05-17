#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void sigint(int sig){
	
		printf("\nctrl+c interupt genrated \n");
		exit(EXIT_SUCCESS);
	

}


int main()
{
signal(SIGINT,sigint);

while(1){

}
return 0;
}
