#include "stack.h"

static int stack[MAX]={0};
static int top=-1;

void push(int data){

if (top != (MAX-1)){
top++;
stack[top]=data;
printf("\ndata added succesfully");
}
else
{
	printf("\nstack overloaded, unsuccesfull data adding");
}
}


int pop(){
if (top==-1){
	printf("stack is empty pop not allowed");
	   }
else
{
	int tmp=stack[top];
        stack[top]=0; 
	top--;

	return tmp;
}
}
