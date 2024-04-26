#include <stdio.h>
#include "stack.h"
#include "main.h"

int main()
{
	stack_init();
	stack_push(10);
	stack_push(20);
	stack_push(30);
	printf("popping elments from stack :\n");
	while(!stack_is_empty())
	{
		printf("%d",stack_pop());
	}
	printf("\n");
}


