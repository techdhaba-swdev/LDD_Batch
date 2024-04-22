#include<stdio.h>
#include<stdlib.h>
#include"printd.h"

struct Node 
{
	int value;
	struct Node* next;
	struct Node* prev;
};

struct Node* create_node(int value)
{
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->value=value;
	new_node->next=NULL;
	new_node->prev=NULL;
	return new_node;
}

int find_sum(struct Node* head)
{
	int sum=0;
	struct Node* current=head;
	while(current!=NULL)
	{
		sum+=current->value;
		current=current->next;
	}
	return sum;
}

void print_list(struct Node* head)
{
	struct Node* current=head;
	while(current !=NULL)
	{
		printf("%d\t",current->value);
		current=current->next;
	}
	printf("\n");
}

