#include<stdio.h>
#include "lkadd.h"

int main(){
	struct Node* head = NULL;
	insertnode(&head, 1);
	insertnode(&head, 2);
        insertnode(&head, 3);
        insertnode(&head, 4);
	printf("Linked List: ");


	printlist(head);

	return 0;
}
