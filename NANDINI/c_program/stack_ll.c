#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
struct stacknode
{
	int data;
	struct stacknode*next;
};
struct stacknode*newnode(int data)
{
	struct stacknode*stacknode = (struct stacknode*)malloc(sizeof(struct stacknode));
	stacknode->data =data;
	stacknode->next = NULL;
	return stacknode;
}
int isEmpty(struct stacknode*root)
{
	return !root;
}
void push(struct stacknode**root, int data)
{
	struct stacknode*stacknode=newnode(data);
	stacknode->next=*root;
	*root = stacknode;
	printf("%d pushed on stack\n", data);
}
int pop(struct stacknode**root)
{
	if(isEmpty(*root))
		return INT_MIN;
	struct stacknode*temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);
	return popped;
}
int peek(struct stacknode*root)
{
	if(isEmpty(root))
		return INT_MIN;
	return root->data;
}
int main()
{
	struct stacknode*root = NULL;
	push(&root, 10);
        push(&root, 20);
	push(&root, 30);
	printf("%d popped from stack\n", pop(&root));
	printf("Top element is %d\n", peek(root));
	return 0;
}

