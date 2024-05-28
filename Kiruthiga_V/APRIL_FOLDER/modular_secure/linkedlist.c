#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
// Define a structure for a node in the linked list
struct Node
{
	int data;
	struct Node* next;
};
void insertAtBeginning(struct Node** head_ref, int new_data){
struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));//Function to create a new node
if(new_node == NULL)
{
	fprintf(stderr, "error:memory allocation failed for new node.\n");
	exit(EXIT_FAILURE);
}
new_node->data = new_data;
new_node->next = (*head_ref);
(*head_ref) = new_node;
}
//function to print the linked list
void printList(const struct Node* node)
{
	while(node != NULL)
	{
		printf("%d",node->data);
		node = node->next;
	}
	printf("\n");
}
//Function to free memory allocated for the linked list
void freeList(struct Node* head)
{
	struct Node* temp;
	while(head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
