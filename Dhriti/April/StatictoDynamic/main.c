#include<stdio.h>
#include "linklist.h"


int main(){
	Node *head = NULL;

	addlinklist(&head, 2);
	addlinklist(&head, 6);
        addlinklist(&head, 9);
	addlinklist(&head, 7);

printf("Sum of the list is: %d\n", sum(head));

return 0;
}
