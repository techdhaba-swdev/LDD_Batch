#include <stdio.h>
#include "linklist.h"

int main() {
    Node *head = NULL;
    
    for (int i = 1; i <= 5; i++) {
        appendNode(&head, i);
    }

    int sum = sumLinkedList(head);

    printf("Sum of values from all nodes: %d\n", sum);

    freeLinkedList(head);

    return 0;
}
