#include <stdio.h>
#include<stdbool.h>
#define MAX 10
#include "stack.h"

typedef struct{
int stack[MAX];
int top;
}Stack;


static Stack root;


void stack_init(){
root.top=-1;
}



void push(int data){

if (root.top != (MAX-1)){
root.top++;
root.stack[root.top]=data;
printf("\ndata added succesfully");
}
else
{
	printf("\nstack overloaded, unsuccesfull data adding");
}
}



int pop(){
if (root.top==-1){
	printf("stack is empty pop not allowed");
	   }
else
{
	int tmp=root.stack[root.top];
        root.stack[root.top]=0; 
	root.top--;

	return tmp;
}
}

bool isStackEmpty(){
if (root.top==-1){
return 1;
}
else{
return 0;
}
}


bool isStackFull(){
if (root.top==(MAX-1)){
return 1;
}
else{
return 0;
}
}
