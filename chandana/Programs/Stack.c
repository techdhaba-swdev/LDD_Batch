#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define size 100

int stack[size];
int top=-1;

void push(int item){
	if(top==size-1){
		printf("Stack Overflow\n");
		exit(EXIT_FAILURE);
	}
	stack[++top]=item;
}

int pop(){
	if(top==-1){
		printf("stack underflow\n");
		exit(EXIT_FAILURE);
}
	return stack[top--];
}
int isEmpty(){
	return top==-1;
}
int isOperator(char c){
	return c == '+' || c=='-' || c== '*' || c== '/';
}

int Operation(int a,int b,char operator){
	switch(operator){
		case '+' : return a+b;
	        case '-' : return a-b;
	        case '*' : return a*b;
		case '/' : return a/b;
		default : return 0;
	}
}
int evaluateExp(char* expression){
	for(int i=0;expression[i];i++){
		if(expression[i] == ' ' || expression[i] == '\t') {
			continue;
		}
			else if(isdigit(expression[i])){
				int operand=0;
				while(isdigit(expression[i])){
					operand = operand * 10 + (expression[i] - '0');
					i++;
				}
				i--;
				push(operand);
			}
			else if(isOperator(expression[i])){
				int b=pop();
				int a=pop();
				int result=Operation(a,b,expression[i]);
				push(result);
			}
		}
		return pop();
	}
	int main()
	{
		char expression[] = "4 5 7 - * 1 /";
		int result=evaluateExp(expression);
		printf("Result : %d\n",result);
		return 0;
	}

