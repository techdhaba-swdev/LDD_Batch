#include<stdlib.h>
#include "circularlist.h"
void addnode(struct Node** head,int value){
	struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->value=value;
        newnode->next=NULL;
        if(*head==NULL)
        {
                *head=newnode;
		newnode->next=*head;
        }
        else
        {
                struct Node* current=*head;
                while(current->next!=NULL)
                {
                        current=current->next;
                }
                current->next=newnode;
		newnode->next=*head;
        }
}
int sumvalues(struct Node* head){
	if(head==NULL)
	{
		return 0;
	}
        int sum=0;
        struct Node* current=head;
        while(current!=head){
                sum=sum+current->value;
                current=current->next;
        }
        return sum;
}

