#include<stdio.h>
#include"CircularLinkedList.h"

int main()
{
	struct Node* head = createCircularLinkedList();
	int choice,data;

	while(1)
	{
		puts("\nCircular Linked List operations:\n");
		puts("1. Add element to list\n");
		puts("2. Display list\n");
		puts("3. Calculate sum of elements");
		puts("4. Exit");

		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				puts("Enter the element to add: ");
				scanf("%d", &data);
				append(&head,data);
				printf("Element added successfully.\n");
				break;
			case 2:
				printf("Circular Linked List: ");
				display(head);
				break;
			case 3:
				printf("Exiting....\n");
				return 0;
			default:
				printf("Invalid choice. Please enter a valid option.\n");
		}
	}
	    return 0;
}

