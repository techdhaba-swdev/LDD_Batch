#include<stdio.h>
#include "doubly_ll.h"

int main()
{
	Node *head = NULL;
	for(int i = 1; i<+5; ++i)
	{
		addNode(&head, i);
	}
	printf("sum of elements in the linked list: %d\n", sumList(head));
	return 0;
}

