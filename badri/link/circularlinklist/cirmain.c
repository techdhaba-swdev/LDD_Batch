#include <stdio.h>
#include "cir.h"

int main() {
    int n, data;
    Node* head = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values for the nodes:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertNode(&head, data);
    }

    printf("Values in the linked list: ");
    printList(head);

    printf("Sum of values in the linked list: %d\n", sumList(head));

    return 0;
}
