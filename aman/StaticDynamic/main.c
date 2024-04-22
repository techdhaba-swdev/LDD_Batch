#include <stdio.h>
#include "linklist.h"
int main(){
	struct Node* head = NULL;
	insertNode(&head, 5);
	insertNode(&head, 10);
	insertNode(&head, 15);
	insertNode(&head, 20);
	insertNode(&head, 25);
	printf("Sum of elements in linklist: %d\n", sumList(head));
	return 0;
}
