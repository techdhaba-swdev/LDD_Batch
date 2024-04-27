#include <stdio.h>
#include "doublell.h"

int main() {
    // Create a new doubly linked list
    struct Node* head = NULL;
    head = insertAtBeginning(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    // Display the doubly linked list
    printf("Doubly linked list: ");
    display(head);

    // Delete a node from the doubly linked list
    head = deleteNode(head, 20);

    // Display the updated doubly linked list
    printf("Updated doubly linked list: ");
    display(head);

    return 0;
}
