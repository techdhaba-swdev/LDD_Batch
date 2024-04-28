#include<stdio.h>
#include<stdlib.h>
#include "stack1.h"
#include <stdbool.h>
#define MAX_SIZE 100
 static int stack[MAX_SIZE];
 static int top = -1;
 void push(int value)
{
	 if(stack_is_full()){
		 printf("stack overflow");
		 return;
	 }
	 stack[++top] = value;
}
int pop(){
	if(stack_is_empty()){
		printf("stack underflow\n");
		exit(EXIT_FAILURE);
	}
	return stack[top--];
}
bool stack_is_empty(){
	return top == -1;
}
bool stack_is_full(){
	return top == MAX_SIZE -1;
}
