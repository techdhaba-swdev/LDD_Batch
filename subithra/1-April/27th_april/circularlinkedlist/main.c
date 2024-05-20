#include "circular_linked_list.h"
#include <stdio.h>

int main() {
    Node *head = NULL;

    // Inserting elements into the list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);
    
    // Displaying the list
    displayList(head);
    
    // Deleting a node
    deleteNode(&head, 20);

    // Displaying the list after deletion
    displayList(head);

    // Freeing the memory allocated to the list
    freeList(&head);

    return 0;
}
