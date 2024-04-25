#include <stdio.h>
#include "circularlist.h"

int main() {
    Node* head = NULL; // Initialize the head of the circular list to NULL

    // Insert some elements into the circular list
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);

    // Display the elements of the circular list
    displayList(head);

    // Free the memory allocated for the circular list
    freeList(head);

    return 0;
}
