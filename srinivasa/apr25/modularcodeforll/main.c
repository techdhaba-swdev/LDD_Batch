#include "linklist.h"
#include <stdio.h>
#include<stdlib.h>
int main() {
	struct node *head = NULL;
    int k = 0;
    insertAtBegin(12);
    insertAtBegin(22);
    insertAtEnd(30);
    insertAtEnd(44);
    insertAtBegin(50);
    printf("Linked List: ");
    printList();
    deleteAtBegin();
    deleteAtEnd();
    deleteNode(12);
    printf("\nLinked List after deletion: ");
    printList();
    insertAtBegin(4);
    insertAtBegin(16);
    printf("\nUpdated Linked List: ");
    printList();
    k = searchList(16);
    if (k == 1)
        printf("\nElement is found");
    else
        printf("\nElement is not present in the list");
        // Free memory for all dynamically allocated nodes before exiting
    struct node *current = head;
    struct node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    return 0;
}
