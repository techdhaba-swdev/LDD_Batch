#include<stdio.h>
#include "stack.h"

int main() {
	push(5);
	push(10);
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	
	return 0;
}
