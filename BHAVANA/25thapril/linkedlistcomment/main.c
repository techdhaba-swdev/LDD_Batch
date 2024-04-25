#include <stdio.h>
#include "linklist.h" // Include the header file for linked list operations

int main() {
    Node* head = NULL; // Initialize the head of the list to NULL

    // Insert some elements into the list
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);

    // Display the elements of the list
    printf("Linked List: ");
    displayList(head);

    // Free the memory allocated for the list
    freeList(head);

    return 0;
}
