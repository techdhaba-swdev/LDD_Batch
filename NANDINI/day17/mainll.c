#include"ll.h"
#include<stdio.h>

int main()
{
	struct node** head = NULL;
	int k = 0;

        //insert element into linkedlist

	insertAtBegin(7);
	insertAtBegin(29);
	insertAtBegin(22);
	insertAtEnd(5);
	insertAtEnd(10);
	insertAtBegin(55);
	insertAfterNode(&head,33);

        //printing linkedlist

	printf("Linked List:");
        printList();

        //deleting at begining and end and specified element

	deleteAtBegin();
	deleteAtEnd();
	deleteNode(11);

       //printing list after deletion

	printf("\nLinked List after deletion:");
	printList();


        //insert additional elements and print the updated list

	insertAtBegin(3);
	insertAtBegin(18);
	printf("\nUpdated Linked List:");
	printList();

       //search for an element in the linked list

        k = searchList(55);
	if(k == 1)
		printf("\nElement is found");
	else
		printf("\nElement is not present in the list");
	return 0;
}

