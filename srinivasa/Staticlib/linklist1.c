#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
struct node *createnode(int data){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}
int sumlinkedlist(struct node *head){
	int sum =0;
	struct node *current = head;
	while(current !=NULL)
	{
		sum += current->next;
		current = current->next;
	}
	return sum ;
}
