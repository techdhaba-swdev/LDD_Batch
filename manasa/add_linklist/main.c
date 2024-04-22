#include <stdio.h>
#include "circularlist.h"
int main() {
	struct Node* head = NULL;
	insertAtEnd(&head, 1);
	insertAtEnd(&head, 2);
	insertAtEnd(&head, 3);
	insertAtEnd(&head, 4);
	insertAtEnd(&head, 5);
	printf("circular linked list: ");
	displaylist(head);
	return 0;
}

