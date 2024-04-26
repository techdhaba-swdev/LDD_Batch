#include "linklist.h"
#include<stdio.h>

int main(){
	int k=0;

	//insert element into the linked list
	insertAtBegin(12);
	insertAtBegin(22);
	insertAtEnd(30);
	insertAtEnd(44);
	insertAtBegin(50);

	//printing linkedlist
	printf("Linkedlist: ");
	printlist();

	//deleting at beggining and end and specified element
	deleteAtBegin();
	deleteAtEnd();
	deleteNode(12);

	//printing list after deletion
	printf("\nLinkedlist after deletion: ");
	printlist();

	//insert additional element and print the updated list
	insertAtBegin(4);
	insertAtBegin(16);
	printf("\nUpdateed linkedlist:");
	printlist();

	//search for an element in the linkedlist
	k = searchList(16);
	if (k == 1)
		printf("\nElement is found");
	else
		printf("\nElement is not in the list");
	return 0;
}
