#include"stack1.h"
int main(){
	Stack stack;
	stack_init(&stack);
	stack_push(&stack,10);
	stack_push(&stack,20);
	stack_push(&stack,30);
	printf("poping elements from the stack:\n");
	while(!stack_is_empty(&stack)){
		printf("%d\n",stack_pop(&stack));
	}
	if(stack_is_empty(&stack)){
		printf("Stack is empty.\n");
	}else{
		printf("Stack is not empty.\n");
	}
	return 0;
}

