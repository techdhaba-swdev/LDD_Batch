#include<stdio.h>
#include<string.h>
#define max 100
int top, stack[max];
void push(char x)
{
	if(top == max-1)
	{
		printf("stack is overflow");
	}
	else
	{
		stack[++top] = x;
	}
}
void pop()
{
	printf("%c", stack[top--]);
}
main()
{
	char str[] = "NANNA";
	int len = strlen(str);
	int i;
	for(i=0;i<len;i++)
	{
		push(str[i]);
	}
	for(i=0;i<len;i++)
	{
		pop();
	}
}
