#include"eval.h"
/*
int stack[MAX] ; //operators stack
char infix[MAX] ; //infix array used to store expression entered by user
char postfix[MAX]; //postfix array used to store whole postfix expression after convertion
int top=-1; //holds index of stack currently it is empty
*/
int main()
{
	char stack[MAX];
	int stack2[MAX] ; //operators stack
	char infix[MAX] ; //infix array used to store expression entered by user
	char postfix[MAX]; //postfix array used to store whole postfix expression after convertion
	int top=-1; //holds index of stack currently it is empty
	int res;
    	printf("Enter infix expression:");
    	gets(infix);//get string function to read elements given by user which is declared in string.h
    	intopost();
	printf("\n");
	print();
	printf("\n");
    	res=post();
    	
   	printf("The result obtained after postfix evaluation is %d\n",res);
   
    return 0;
}

