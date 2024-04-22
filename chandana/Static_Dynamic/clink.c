#include <stdio.h>
#include <stdlib.h>
#include "clink.h"


Node* createList(int n) {
	Node* head=NULL;
        Node* temp=NULL;
	Node* new_node = NULL;
	int data;

	if(n<=0) {
		return head;
	}

	printf("Enter the values for the list :\n");
	for(int i=0;i<n;i++){
		printf("Enter value %d: ",i+1);
		scanf("%d",&data);

		new_node = (Node*) malloc(sizeof(Node));
		new_node->data=data;
		new_node->next=NULL;

		if(head==NULL) {
			head=new_node;
		}
		else{
			temp->next=new_node;
		}
		temp=new_node;
	}
	temp->next=head;
	return head;
}
void display(Node* head) {
	Node* current=head;

	if(head==NULL) {
		printf("Circular linked list is empty,\n");
		return;
	}
	printf("circular linked list\n");
	do {
		printf("%d",current->data);
		current=current->next;
	}
	while(current!=head);
	printf("\n");
}
