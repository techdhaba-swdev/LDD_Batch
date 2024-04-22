#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct StackNode{
	int data;
	struct StackNode*next;
};
struct StackNode*newNode(int data){
	struct Stacknode*stackNode = (struct StackNode*)malloc(sizeos(struct StackNode));
       stackNode->data = data;
stackNode->next=NULL;
return stackNode;
}
bool isEmpty(struct StackNode*root){
	return !root;
}
void push(struct StackNode**root,int data){
	struct StackNode*stackNode=newNode(data);
	stackNode->next=*root;
	*root = stackNode;
}
int pop(struct StackNode**root){
	if(isEmpty(*root))
		return 0;
	struct StackNode*temp =*root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);
	return popped;
}		
int performOperation(int operand1,int operand2,char operator){
	switch(operator){
		case '+':
			return operand1+operand2;
                case'-':
			return operand1-operand2;
		case '*':
			return operand1*operand2;
		case '/':
			return operand1/operand2;
		default:
			return 0;

	}
}
int main(){
	char performOperation[100];
	printf("Enter an operation(+,-,*,/):");
	scanf("%c",operator);
	printf("enter two numbers:");
	scanf("%d%d",&operand1,&operand2);
         iperformOperation(10,20);
   return 0;
}   
