#include <stdio.h>
#include "double_linklist.h"

int main() {
    Node* head = NULL;

    // Inserting elements
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);

    // Displaying the list
    displayList(head);

    // Deleting element
    deleteNode(&head, head->next->next);

    // Displaying the list after deletion
    displayList(head);

    // Freeing memory
    freeList(&head);

    return 0;
}
