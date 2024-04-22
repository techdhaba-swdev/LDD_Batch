#include <stdio.h>
#include <stdlib.h>
#include "circularlist.h"
Node* createNode(int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL){
		printf("Memory allocation failed!\n");
		exit(1);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
Node* insertNode(Node* head, int data){
	Node* newNode = createNode(data);
	if(head == NULL){
		head = newNode;
		head->next = head;
	}
	else{
		Node* temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = head;
	}
	return head;
}
void displayList(Node* head){
	if(head == NULL){
		printf("List is empty!\n");
		return;
	}
	Node* temp = head;
	do{
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	while (temp != head);
	printf("...\n");
}
int sumAllNodess(Node* head){
	int sum =0;
	if(head == NULL){
		printf("List is empty!\n");
		return sum;
	}
	Node* temp = head;
	do{
		sum += temp->data;
		temp = temp->next;
	}
        while (temp !=   head);
        return sum;
}	
