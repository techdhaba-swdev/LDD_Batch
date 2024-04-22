#include<stdio.h>
#include<stdlib.h>
#include "circularlist.h"
struct Node* createNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(newNode == NULL) {
		printf("memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void inserAtEnd(struct Node** head_ref, int data) {
	struct Node* newNode = createNode(data);
	if(*head_ref == NULL) {
		*head_ref = newNode;
		newNode->next = newNode;
	}else{
		struct Node*temp = *head_ref;
		while(temp->next != *head_ref) {
			temp=temp->next;
		}
		temp->next = newNode;
		newNode->next = *head_ref;
	}
}
void displaylist(struct Node* head) {
	if(head == NULL) {
		printf("list is empty\n");
		return;
	}
	struct Node*temp = head;
	do {
		printf("%d", temp->data);
		temp = temp->next;
	}while(temp != head);
	printf("\n");
}
