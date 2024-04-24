#include"pop.h"
/*typedef struct {
        int *data;
        int top;
        int capacity;
}Stack;*/

int stack_pop(Stack *stack){
	if(stack_is_empty(stack)){
		return -1;
	}
	return stack->data[stack->top--];
}
