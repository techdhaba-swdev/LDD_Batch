#include"empty.h"
/*typedef struct {
        int *data;
        int  top;
        int capacity;
}Stack;*/
bool stack_is_empty(Stack *stack){
	return (stack->top ==-1);
}
