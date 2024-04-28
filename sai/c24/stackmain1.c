#include<stdio.h>
#include "stack1.h"
int main()
{
	push(10);
	push(20);
	push(30);

	printf("popped value:%d\n",pop());
	printf("popped vlaue:%d\n",pop());

	return 0;
}
