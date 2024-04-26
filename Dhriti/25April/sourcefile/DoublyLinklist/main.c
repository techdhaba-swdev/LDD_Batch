#include <stdio.h>
#include "dlinklist.h"

int main() {
    struct Node* head = NULL;
    
    // Example usage
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    displayList(head);
    search(head, 20);
    deleteNode(&head, 10);
    displayList(head);
    
    return 0;
}

