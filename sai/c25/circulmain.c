#include <stdio.h>
#include "circular.h"

int main() {
    Node* head = NULL;

    // Insert nodes
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);

    // Display the list
    displayList(head);

    // Delete a node
    deleteNode(&head, 2);

    // Display the updated list
    displayList(head);

    return 0;
}
