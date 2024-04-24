
#include "stack.h"
#include<stdio.h>
#include<stdlib.h>
#define SIZE 30
int stack[SIZE];
int top=-1;
void push(int item)
{
	if(stack_full())
	{
	   printf("stack overflow\n");
	   return;
	}
	stack[++top]=item;
}
int pop()
{
	if(stack_empty())
	{
		printf("stack underflow\n");
		exit(EXIT_FAILURE);
	}
	return stack[top--];
}
bool stack_empty()
{
	return top == -1;
}
bool stack_full()
{
	return top==SIZE-1;
}




