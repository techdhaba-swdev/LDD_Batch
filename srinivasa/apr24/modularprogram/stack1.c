#include"stack1.h"
int top = -1;
int arr[5];
int main()
{
	stack_push(10);
	stack_push(20);
	stack_Push(30);
	printf("poped element is %d",stack_pop());
	stack_is_empty();
	stack_is_full();
	return 0;
}
