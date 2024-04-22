#include <stdio.h>
#include "linkedlist.h"
int main() {
	struct Node* head = NULL;
	for(int i; i <= 5; ++i)
	{
		insert(&head, i);
	}
	printf("sum of all elements in linked list;; %d\n", sumlist(head));
	return 0;
}
