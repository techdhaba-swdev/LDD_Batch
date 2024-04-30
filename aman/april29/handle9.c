#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void sigint_handler(int signum){// function sigint_handler which will execute when it will receive singnal ctrl+c
        printf("\n ctrl+c pressed. exits the program gracefully.\n");// this printf prints that the ctrl+c is caught and then it do addition
}
int main(){
        signal(SIGINT, sigint_handler);//here sigint_handler function is getting registered to handle ctrl+c signal
        printf("press ctrl+c to exit.\n"); 
      
        while(1){//infinite loop and wait for ctrl+csignal 
        }
        return(EXIT_SUCCESS);//successful compilation of program
}
