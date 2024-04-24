#include <stdio.h>
#include "stack.h"

void push(stack *s, int value){
	if (isFull(s)) {
		printf("stack overflow!\n");
		return ;
	}
	s->items[++s->top] = value;
	printf("pushed %d onto the stack\n" ,value);
}
