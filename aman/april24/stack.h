#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 100
typedef struct{
	int data[MAX_SIZE];
	int top;
}Stack;
void init(Stack *stack);
int is_empty(Stack *stack);
int is_full(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);

#endif
