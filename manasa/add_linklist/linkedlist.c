#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

void insert(struct Node *head, int data)
{
	struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
	if(newNode==NULL)
	{
		printf("memory allocation failed!\n");
		exit(1);
	}
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}
int sumlist(struct Node *head)
{
	int sum = 0;
	struct Node *current = head;
	while(current != NULL)
	{
		sum += current->data;
		current = current->next;
	}
	return sum;
}
