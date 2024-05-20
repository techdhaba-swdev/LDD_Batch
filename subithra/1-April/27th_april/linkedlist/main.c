#include <stdio.h>
#include "linkedlist.h"

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;
    
    // Insert some elements into the linked list
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);
    
    // Print the linked list
    printf("Linked list elements: ");
    printList(head);
    
    // Free memory allocated for the linked list
    freeList(head);
    
    return 0;
}
