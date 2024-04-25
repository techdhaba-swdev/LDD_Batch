#include <stdio.h>
#include "stack.h"
int main() {
	Stack stack;
	init(&stack);
	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);
	printf("Popped value: %d\n", pop(&stack));
	printf("Popped value: %d\n", pop(&stack));
	printf("Popped value: %d\n", pop(&stack));
	printf("Popped value: %d\n", pop(&stack));
	return 0;
}
