#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
int x,y;//declaring two integer variable required  for storingvalue of input number 
void sigint_handler(int signum){// function sigint_handler which will execute when it will receive singnal ctrl+c
	printf("\nCtrl+C caught. doing addition: %d + %d = %d\n", x, y, x+y);// this printf prints that the ctrl+c is caught and then it do addition
}
int main(){
	signal(SIGINT, sigint_handler);//here sigint_handler function is getting registered to handle ctrl+c signal
	printf("enter two number: ");//it prints enter  two number 
	scanf("%d %d", &x, &y);//reads the number input by user
	printf("Press ctrl+c to add number.\n");//it prints number  will be added by pressing ctrl+c
	while(1){//infinite loop and wait for ctrl+csignal to add two number
	}
	return(EXIT_SUCCESS);//successful compilation of program
}
