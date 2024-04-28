#include<stdio.h>
#include "linklist.h"
#include<stdlib.h>
int main()
{
	Node* head = NULL;
	
	
	
		insertlink(&head,1 );
		insertlink(&head,2);
		insertlink(&head,3);
	

	printf("Linked list:\n");
	printList(head);

	return 0;
}
