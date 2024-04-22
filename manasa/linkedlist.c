#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

void insert(Node *head, int data)
{
	Node *newNode=(Node*)malloc(sizeof(Node));
	if(newNode==NULL)
	{
		printf("memory allocation failed!\n");
		exit(1);
	}
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}
int sumlist(Node *head)
{
	int sum = 0;
	Node *current = head;
	while(current != NULL)
	{
		sum += current->data;
		current = current->next;
	}
	return sum;
}
