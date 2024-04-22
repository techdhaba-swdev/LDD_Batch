#include<stdio.h>
#include<stdlib.h>
#include"print.h"

struct Node
{
        int value;
        struct Node* next;
};


int main()
{
	struct Node* head=create_node(10);
	head->next=create_node(20);
	head->next->next=create_node(30);
	head->next->next->next=create_node(40);
	head->next->next->next->next=create_node(50);

	printf("Linklist values:\n");

	print_list(head);

        struct Node* current=head;
	while(current!=NULL)
	{
		struct Node* temp= current;
		current=current->next;
		free(temp);
	}
	return 0;
}
