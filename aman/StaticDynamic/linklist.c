#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
void insertNode(struct Node** headRef, int newData){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = newData;
	newNode->next = *headRef;
	*headRef = newNode;
}

int sumList(struct Node* head){
	int sum = 0;
	struct Node* current = head;
	while (current != NULL){
		sum += current->data;
		current = current->next;
	}
	return sum;
}
