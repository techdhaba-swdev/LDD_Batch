
#include<stdio.h>
#include<stdlib.h>
#include "linklist.h"

void addlinklist(Node **head, int data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	if(newNode == NULL)
	{
		printf("Error\n");
	}

	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}


int sum(Node *head){
	int sum =0;
	Node *current = head;
	while(current != NULL){
		sum += current->data;
		current = current->next;
	}
	return sum;
}
	
