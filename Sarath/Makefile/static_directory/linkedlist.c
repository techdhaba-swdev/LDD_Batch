#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"
struct node
{
	int data;
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
		return ;
	}
	temp->next=head;
	head=temp;
}
void insert_at_end(int data)
{
	struct node *temp=malloc(sizeof(struct node));
	struct node *ptr=head;
	temp->data=data;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=temp;
	temp->next=NULL;
}
void print()
{
	struct node *ptr=head;
	int result=0;
	while(ptr!=NULL)
	{
		result=result+ptr->data;
		ptr=ptr->next;
	}
	printf("Sum of list is %d\n",result);
}

