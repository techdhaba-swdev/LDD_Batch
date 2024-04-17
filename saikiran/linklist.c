#include<stdio.h>
#include<stdlib.h>
#include "linklist.h"

void insertlink(Node** head,int data)
{
	Node* newNode = (Node)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	if(*head == NULL)
	{
		*head = newNode;
		return;
	}
	Node* temp = *head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}
int printList(Node* head)
{
	Node* current = head;
	while(current != NULL)
	{
		printf("%d->", current->data);
		current = current->next;
	}
	printf("NULL\n");
}
