#include<stdio.h>
#include<stdlib.h>
#include "linklist.h"
void main()
{
	struct Node* head=NULL;
	addnode(&head,18);
	addnode(&head,27);
	addnode(&head,35);
	addnode(&head,56);
	printf("the sum of all is %d\n",sumvalues(head));
	struct Node* current=head;
	while(current!=NULL){
		struct Node* temp=current;
		current=current->next;
		free(temp);
	}
}
	
