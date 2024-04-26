#include <stdio.h> //including header stdio for input and output function calling
#include <stdlib.h>// including library header for memory function
#include "linklist.h"

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));// here we are dynamically allocating memory using malloc
    if (newNode == NULL) { // checking the node is null or not
        printf("Memory allocation failed.\n");
        exit(1);//tells there is error to os
    }
    newNode->data = data;// aggigning data to new node
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node** headRef, int data) {
    Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    Node* current = *headRef;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to calculate the sum of all elements in the linked list
int sumOfElements(Node* head) {
    int sum = 0;
    Node* current = head;
    while (current != NULL) {
        sum += current->data;//calculating the sum of inserted data
        current = current->next;
    }
    return sum;
}
// Function to free the memory allocated for the linklist
void freeList(Node* head)
{
	Node* current = head;
	while (current != NULL)
	{
		Node* temp = current;
		current = current->next;
		free(temp);
	}
}

