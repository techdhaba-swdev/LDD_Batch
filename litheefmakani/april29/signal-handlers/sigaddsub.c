#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

//we perform two operations here one is add number using sigint(ctrl-c),another one is sub numbers using sigstop(ctrl-z))
//we are defining two numbers
int num1,num2;

//signal handler for sigint(ctrl+c)
void sigint_handler(int signum){
	printf("\n enter the two numbers to add :\n");
	scanf("%d %d" ,&num1,&num2);
	printf("sum is :%d\n",num1+num2);
}
//signal handler for sigstop(ctrl-z)
void sigstop_handler(int signum){
	printf("\n enter the two numbers to sub :\n");
	scanf("%d%d",&num1,&num2);
	printf("sub is :%d\n",num1-num2);
}
int main(){
	//signal(SIGINT, sigint_handler);
	signal(SIGTSTP,sigstop_handler);

	printf("press ctrl+c to add two numbers,ctrl+z to substract two numbers\n");
	while(1){
		sleep(1);//slepping to keep the program running
	}
	return 0;
}
	
