#include<stdio.h>
#include<strlib.h>
void push(char stack[],char item ,int *top)
{
	stack[++(*top)]=item;
}
void pull(char stack[],&top)
{
	if (*top==-1)
	{
		printf("stack over flow:");
		return '\0';
	}
	return stack[(*top)--];
int main ()
{      char string[20];
	char stack[20];
	char revstring[20];
	int top =-1;
	printf("enter  a string to reversed:");
	scanf("%s",string);
	for (i=0;i< strlen(string);i++)
	{ 
		push(stack,string[i],&top);
	}
	int index =0;
	while (top!=0)
	{
		revstring[index++]=pop(stack ,&top);
	}
	revstring[index]='\0';
	printf("reversed string:%s:",revstring);
	return 0;
}
