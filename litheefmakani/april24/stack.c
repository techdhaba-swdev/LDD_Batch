#include"stack.h"
void init(Stack *stack){
	stack->top = -1;
}
int isEmpty(Stack *stack){
	return stack->top==-1;
}
int isFull(Stack *stack){
	return stack->top==MAX_SIZE -1;
}
void push(Stack *stack,int value){
	if(!isFull(stack)){
		stack->top++;
		stack->data[stack->top]=value;
	}
}
int pop(Stack *stack){
	if(!isEmpty(stack)){
		int value = stack->data[stack->top];
		stack->top--;
		return value;
	}
	return -1;
}

