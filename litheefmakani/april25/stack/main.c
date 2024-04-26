#include <stdio.h>
#include "stack.h"

int main()
{
	stack s ;
	initialize(&s);

	push(&s, 10);
	push(&s, 20);
	push(&s ,30);

	printf("pop element : %d\n",pop(&s));
	printf("pop element : %d\n",pop(&s));
	printf("pop elemnet : %d\n" ,pop(&s));

	return 0;
}
