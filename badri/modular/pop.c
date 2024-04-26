#include "pop.h"
#include "stack.h"
#include <stdio.h>

int stack_pop()
{
	if (stack_is_empty()){
		printf("stack underflow\n");
		return -1;
	}
	int value = stack_data[stack_top];
	stack_top--;
	return value;
}
