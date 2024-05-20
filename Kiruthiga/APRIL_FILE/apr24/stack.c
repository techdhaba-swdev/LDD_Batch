#include <stdio.h>
#include<stdlib.h>
#include"stack.h"
#define MAX_SIZE 5
static int stack[MAX_SIZE];
static int top = -1;
void stack_push(int data)
{
	if(stack_is_full())
	{
		printf("stack overflow\n");
		return;
	}
	stack[++top] = data;
}
int stack_pop()
{
	if(stack_is_empty())
	{
		printf("stack underflow\n");
		exit(EXIT_FAILURE);
	}
	return stack[top--];
}
bool stack_is_empty()
{
	return top == -1;
}
bool stack_is_full()
{
	return top == MAX_SIZE -1;
}

