#include "push.h"
#include "stack.h"
#include <stdio.h>

void stack_push(int value)
{
	if(stack_is_full())
	{
		printf("stack overflow\n");
		return;
	}
	stack_top++;
	stack_data[stack_top] = value;
}
