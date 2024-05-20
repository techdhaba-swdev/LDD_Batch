#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


void ctrl_c_handler(int signum) {
	int num1 , num2 ;
       printf("caught SIGINT signal\n");    
       printf("enter two numbers :");
       scanf("%d %d",&num1,&num2);
       printf("result %d\n",num1+num2);
}

void ctrl_z_handler(int signum) {
	int num1 ,num2	;
	printf("caught SIGTSTP signal\n");
	printf("enter two number:");
	scanf("%d %d",&num1, &num2);
	printf("result :%d\n",num1-num2);
}
int main(){
	signal(SIGINT,ctrl_c_handler); // registering the ctrl+c handler
	signal(SIGTSTP,ctrl_z_handler); // resistering the ctrl+z handler
        signal(SIGINT,SIG_IGN); //signal ignore 
	signal(SIGALRM,SIG_DFL); // defalut handling 
	
	while(1){
	}
	return 0;
}
