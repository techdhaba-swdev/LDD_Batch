#include "linked_list.h"
#include <stdio.h>

int main() {
	struct node** head = NULL;
    int k = 0;
    //insert element into the linkedlist
    insertAtBegin(12);
    insertAtBegin(22);
    insertAtEnd(30);
    insertAtEnd(44);
    insertAtBegin(50);

    //printing linkkedlist
    insertAfterNode(&head, 33);

    printf("Linked List: ");
    printList();

    //deleting at beggining and end and specified element
    deleteAtBegin();
    deleteAtEnd();
    deleteNode(12);


    //printing list after deletion
    printf("\nLinked List after deletion: ");
    printList();

    //insert additional element and print the updated list
    insertAtBegin(4);
    insertAtBegin(16);
    printf("\nUpdated Linked List: ");
    printList();

    //search for an element in the linkedlist
    k = searchList(16);
    if (k == 1)
        printf("\nElement is found");
    else
        printf("\nElement is not present in the list");
    return 0;
}

