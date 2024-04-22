#include"CircularLinkedList.h"
#include<stdio.h>
#include<stdlib.h>

struct Node** createCircularLinkedList()
{
	return NULL;
}

void append(struct Node* head_ref, int data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* last = head_ref;
	new_node->data = data;
	new_node->next = *head_ref;

	if(*head_ref == NULL)
	{
	new_node->next = new_node;
	*head_ref = new_node;
	return;
        }
while(last->next != *head_ref)
    {
   last = last->next;
    }
   last->next = new_node;
}

void diplay(struct Node* head)
{
	struct Node* current = head;
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}
	do
	{
		printf("%d", current->data);
		current = current->next;
	}
	while(current != head);
	printf("\n");
}



