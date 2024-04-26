#include "doublelink.h"
#include <stddef.h>// represents a null pointer constant, typically used to initialize pointers that are not pointing to any valid object or function.

int main() {
    Node* head = NULL; // Initialize head pointer to NULL
    insertAtBeginning(&head, 10); // Insert node with data 10 at the beginning
    insertAtBeginning(&head, 20); // Insert node with data 20 at the beginning
    insertAtBeginning(&head, 30); // Insert node with data 30 at the beginning
    displayList(head); // Display the doubly linked list
    return 0; // Return 0 to indicate successful execution
}
