#include<stdio.h>
#include<stdlib.h>
#include "linklist.h"


Node* newNode(int data) {
       Node* currentNode = (Node*)malloc(sizeof(Node));
       currentNode->data = data;
       currentNode->next = NULL;
       return currentNode;
}


void insertNode(Node** head, int data)
{
	Node* currentNode = newNode(data);
	if(*head == NULL) {
		*head = currentNode;
		currentNode->next = *head;
	}
	else {
               
		Node* temp = *head;
		while(temp -> next != *head) {
			temp = temp->next;
		}

		temp->next = currentNode;
		currentNode->next = *head;
	}
}

void inputs(Node* head_f){

	Node* temp = head_f;
	do {
		printf("%d", temp->data);
		temp = temp->next;
		if(temp != head_f) {
			printf(" next ");
		}
	}while (temp!=head_f);
	printf("\n");
}

int sum(Node* head_f) {
	if (head_f == NULL) {
		return 0;
	}
	Node* temp = head_f;
	int total = 0;
	do {
		total += temp->data;
		temp = temp->next;
	}while(temp != head_f);
	return total;
}
