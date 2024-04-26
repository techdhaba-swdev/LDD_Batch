#include <stdio.h>
#include "stack.h"
int main()
{
	Stack stack;
	init(&stack);

	push(&stack , 10);
	push(&stack , 20);
	push(&stack , 30);
	printf("popping elements from the stack:\n");
	while(!is_empty(&stack))
	{
		printf("%d\n",pop(&stack));
	}
	printf("\n");
	return 0;
	}

