#include "stack.h"

static int stack[MAX]={0};
static int top=-1;

static Stack* root =(Stack) malloc(sizeof(Stack));

Stack* init(){

root->top=-1;
return &root;

}

 

void push(Stack** root, int data){

Stack tmp_root =*root;

if (tmp_root->top != (MAX-1)){
tmp_root->top++;
tmp_root->stack[tmp_root->top]=data;
printf("\ndata added succesfully");
}
else
{
	printf("\nstack overloaded, unsuccesfull data adding");
}
}


int pop(Stack** root){

Stack tmp_root =*root;

if (tmp_root->top==-1)
{
	printf("stack is empty pop not allowed");
}
else
{
	int tmp=tmp_root->stack[tmp_root->->top];
        tmp_root->stack[tmp_root->top]=0; 
	top--;

	return tmp;
}
}
