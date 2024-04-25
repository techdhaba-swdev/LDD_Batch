#include "stack.h"
void init(Stack *stack){
	stack->top = -1;
}
int is_empty(Stack *stack){
	return stack->top == -1;
}
int is_full(Stack *stack){
	return stack->top == MAX_SIZE - 1;
}
void push(Stack *stack, int value){
	if(is_full(stack)){
		printf("Stack overflow!\n");
		return;
	}
	stack->top++;
	stack->data[stack->top] = value;
}
int pop(Stack *stack){
	if(is_empty(stack)){
		printf("Stack underflow!\n");
		return -1;
	}
	int value = stack->data[stack->top];
	stack->top--;
	return value;
}
