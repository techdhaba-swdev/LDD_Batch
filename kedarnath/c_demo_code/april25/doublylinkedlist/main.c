#include"list.h"
int main() {
    Node* head = NULL;

    // Insert some elements into the doubly linked list
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);

    // Print the doubly linked list
    printf("Doubly Linked List: ");
    printList(head);

    // Free memory allocated to the list
    freeList(&head);

    return 0;
}

