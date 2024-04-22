#include"circularll.h"
#include <stdio.h>
#include<stdlib.h>
struct node* createcircularll()
{
return NULL;
}
void append(struct node** head1,int data){
	struct node* newnode =(struct node*)malloc(sizeof(struct node));
	struct node* last = *head1;
	newnode->data= data;
	newnode->next=*head1;
	if(*head1==NULL){
		newnode->next=newnode;
		*head1=newnode;
	return;
}
while(last->next != *head1){
	last = last->next;
}
last->next=newnode;
}
void display(struct node*head){
	struct node* current = head;
	if(head == NULL){
		printf("empty\n");
		return;
	}
	do{
		printf("%d",current->data);
		current=current->next;
	}
	while(current != head);
	printf("\n");
}
int sum(struct node* head){
	struct node* current = head;
	int sum = 0;
	if(head == NULL){
		return sum;
	}
	do{
		sum+=current->data;
		current = current->next;
	}
	while(current !=head);
	return sum;
}
