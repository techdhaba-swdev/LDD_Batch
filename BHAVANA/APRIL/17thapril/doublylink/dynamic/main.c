#include <stdio.h>
#include "dllist.h"

int main() {
    Node *head = NULL;

    for (int i = 1; i <= 5; i++) {
        appendNode(&head, i);
    }

    printf("Original list: ");
    printList(head);

    int sum = sumList(head);
    printf("Sum of values from all nodes: %d\n", sum);

    freeList(head);

    return 0;
}
