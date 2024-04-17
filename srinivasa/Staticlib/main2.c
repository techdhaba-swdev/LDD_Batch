// main.c

#include <stdio.h>
#include "linklist2.h"

int main() {
    // Creating a linked list with 5 nodes
    Node *head = NULL;
    for (int i = 1; i <= 5; ++i) {
        insert(&head, i);
    }

    // Printing the sum of all values in the linked list
    printf("Sum of elements in the linked list: %d\n", sumList(head));

    return 0;
}
