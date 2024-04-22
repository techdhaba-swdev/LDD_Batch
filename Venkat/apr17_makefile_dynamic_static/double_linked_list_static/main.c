#include <stdio.h>
#include "dllist.h"

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("Double Linked List: ");
    displayList(head);

    int sum = sumOfNodes(head);
    printf("Sum of all nodes: %d\n", sum);

    return 0;
}
