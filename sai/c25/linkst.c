#include "linkst.h"
#include<stdlib.h>
#include<stdio.h>

struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));//Allocaton 
	if (newNode == NULL){
		printf("Memory allocation failed\n");
		exit(1);
	}
	newNode->data = data;//pointing the data with new node

	newNode->next = NULL;//pointng the next data with new node
	return newNode;//value return to new node
}

void insertatbeg(struct Node** headRef,int data)
{
	struct Node* newNode = createNode(data);
	newNode->next = *headRef;
	*headRef = newNode;
}

void printList(struct Node* head)
{
	while(head != NULL){
		printf("%d->",head->data);//print the value linked list with link up in create an stop with  NULL
		head = head->next;
	}
	printf("NULL\n");
}
