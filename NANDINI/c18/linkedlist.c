#include<stdio.h>
#include<stdlib.h>
#include"print.h"

struct Node 
{
	int value;
	struct Node* next;
};

struct Node* create_node(int value)

{
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->value= value;
	new_node->next=NULL;
	return new_node;
}

void print_list(struct Node* head)
{
	struct Node* current= head;
	while(current!=NULL)
	{
		printf("%d\t",current->value);
		current=current->next;
	}
	printf("\n");
}

