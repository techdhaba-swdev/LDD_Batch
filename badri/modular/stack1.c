#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#define MAX_SIZE 100
 int stack_data[MAX_SIZE];
int  stack_top = -1;
void stack_init()
{
	stack_top = -1;
}
bool stack_is_empty()
{
	return stack_top == -1;
}
bool stack_is_full()
{
	return stack_top == MAX_SIZE -1;
}

