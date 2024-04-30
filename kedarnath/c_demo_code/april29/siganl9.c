#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void sigint_handler(int signum){

	int num1,num2,sum;
	printf("enter the value of num1 and num2\n");
	scanf("%d%d",&num1,&num2);
	sum=num1+num2;
	printf("sum is %d\n",sum);
	//exit(signum);
}

void sigtstp_handler(int signum){

        int num1,num2,sub;
        printf("enter the value of num1 and num2\n");
        scanf("%d%d",&num1,&num2);
        sub=num1-num2;
        printf("substraction is %d\n",sub);
        //exit(signum);
}

void sigquit_handler(int signum){

        /*int num1,num2,sub;
        printf("enter the value of num1 and num2\n");
        scanf("%d%d",&num1,&num2);
        sub=num1-num2;
        printf("substraction is %d\n",sub);*/
	printf("thank you\n");
        exit(signum);
}




int main(){

	//signal(SIGINT,sigint_handle);

	signal(SIGINT,SIG_IGN);
	signal(SIGTSTP,sigtstp_handler);
	signal(SIGTERM,sigquit_handler);
	while(1){

	}
	return 0;

}


