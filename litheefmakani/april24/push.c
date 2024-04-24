#include"push.h"
/*typedef struct {
	int *data;
	int top;
	int capacity;
}Stack;*/
int stack_push(Stack *stack,int data){
	if(stack_is_full(stack)){
		return -1;

	}
	stack->data[++stack->top] = data;
	return 0;
}
