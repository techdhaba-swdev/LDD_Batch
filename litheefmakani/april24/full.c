#include"full.h"
#define MAX_SIZE 100
/*typedef struct {
        int *data;
        int  top;
        int capacity;
}Stack;*/
bool stack_is_full(Stack *stack){
	return (stack->top == MAX_SIZE -1);
}
