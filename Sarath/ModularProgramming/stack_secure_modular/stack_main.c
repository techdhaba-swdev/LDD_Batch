#include<stdio.h>
#include"stack.h"
int main()
{
	struct stack *head=NULL;
	push(10);
	push(20);
	push(30);
	push(40);
	print();
	int p1=pop();
	printf("Poped element %d\n",p1);
	print();
	int p2=pop();
	printf("Poped element %d\n",p2);
	print();
}

