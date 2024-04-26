#include<stdlib.h>
#include "linklist.h"
struct Node* createnode(int value){
        struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->value=value;
        newnode->next=NULL;
        return newnode;
}
void addnode(struct Node** head,int value){
	struct Node* newnode=createnode(value);
	if(*head==NULL)
	{
		*head=newnode;
	}
	else
	{
		struct Node* current=*head;
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=newnode;
	}
}
int sumvalues(struct Node* head){
	int sum=0;
	struct Node* current=head;
	while(current!=NULL){
		sum=sum+current->value;
		current=current->next;
	}
	return sum;
}

