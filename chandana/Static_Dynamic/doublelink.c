#include <stdio.h>
#include <stdlib.h>
#include "doublelink.h"

struct Node* createNode(int data){
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->prev=NULL;
	newNode->next=NULL;
	return newNode;
}

void addNode(struct Node** head,int data){
	struct Node* newNode=createNode(data);
	if(*head==NULL){
		*head=newNode;
		return;
	}
	struct Node* temp =*head;
	while(temp->next!=NULL){
		temp=temp=temp->next;
	}
	temp->next = newNode;
	newNode->prev=temp;
}

int sumAllNodes(struct Node* head){
	int sum =0;
	struct Node* temp=head;
	while(temp!=NULL){
		sum+=temp->data;
	temp=temp->next;
}
return sum;
}
void printList(struct Node* head){
	struct Node* temp = head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

