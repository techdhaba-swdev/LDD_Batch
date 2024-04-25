#include"list.h"

int main() {
    Node *head = NULL;

    // Inserting elements into the list
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);

    // Printing the list
    printf("List: ");
    printList(head);

    // Freeing the memory
    freeList(head);

    return 0;
}

