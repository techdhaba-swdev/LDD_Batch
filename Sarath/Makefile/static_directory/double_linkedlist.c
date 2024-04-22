#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head=NULL;
void insert_at_start(int data)
{
	struct node *temp=malloc(sizeof(struct node));
	temp->data=data;
	if(head==NULL)
	{
		head=temp;
		return;
	}
	temp->next=head;
	head->prev=temp;
	head=temp;
}
void insert_at_end(int data)
{
	struct node *ptr=malloc(sizeof(struct node));
	ptr->data=data;
	struct node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=ptr;
	ptr->prev=temp;
	ptr->next=NULL;
}
void print()
{
	struct node *temp=head;
	int result=0;
	while(temp!=NULL)
	{
		result+=temp->data;
		temp=temp->next;
	}
	printf("Sum of double linkedlist is %d\n",result);
}
