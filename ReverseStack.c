#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack{
	int top;
	unsigned capacity;
	char*array;
};
struct Stack*createStack(unsigned capacity)
{
	struct Stack*stack=(struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity =capacity;
	stack->top=-1;
	stack->array=(char*)
