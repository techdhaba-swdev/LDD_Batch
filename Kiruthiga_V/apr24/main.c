#include <stdio.h>
#include "main.h"
int main()
{
	stack_push(10);
	stack_push(20);
	stack_push(30);
	stack_push(40);
	printf("popped element:%d\n",stack_pop());
	printf("popped element:%d\n",stack_pop());
	return 0;
}
