#include<stdio.h>
#include<stdlib.h>
#include"double_linkedlist.h"
struct node //declared a structure which stores next and prev nodes address which is double linked list
{
	int data; //declared a variable data to store input
	struct node *prev;
	struct node *next;
};
struct node *head=NULL; //initialized head with NULL as at first there will be no node
void insert_at_start(int data) // API for insert at start which takes integer data as argument
{
	struct node *temp=malloc(sizeof(struct node)); //allocated space dynamically for data using malloc and stored in temp
	temp->data=data; //assigned data to temp
	if(head==NULL) //checks for the first time if head is NULL
	{
		head=temp; //assigns temp to head
		return; //this will be done only once because for second push the head will not be NULL
	}
	temp->next=head; //linking temp and head using linkedlist
	head->prev=temp; //as this is double linked list the prev also should be updated
	head=temp; //now head is pointing to temp as we added from start
}
void insert_at_end(int data) //API for insert at end which takes integer argument
{
	struct node *ptr=malloc(sizeof(struct node)); //dynamically allocated space for data and stored in ptr using malloc
	ptr->data=data; //assigned data to ptr
	struct node *temp=head; //reinitiaized head as temp for traversing as we shouldn't traverse head directly
	while(temp->next!=NULL) //loop rotates untill last node 
	{
		temp=temp->next; //temp will be updated with next node address
	}
	temp->next=ptr; //after loop break temp and ptr are linked
	ptr->prev=temp; 
	ptr->next=NULL; //as ptr is last node we assign ptr next to NULL
}
void print() //API for printing required output
{
	struct node *temp=head; //reinitialized head as temp for traversing
	int result=0; //initalized result for printing sum of list
	printf("list elements:");
	while(temp!=NULL) //loop runs until last node
	{
		result+=temp->data; //adds all elements of list and assigns to result
		printf("%d ",temp->data); //printing all elements
		temp=temp->next; //temp will be updated to next node
	}
	printf("\nSum of double linkedlist is %d\n",result); //printing the sum of all elements of list using printf library function
}
