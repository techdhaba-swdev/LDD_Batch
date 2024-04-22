// main.c

#include <stdio.h>
#include "linklist.h"

int main() {
    // Create a linked list
    Node *head = NULL;

    // Add values to the linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    // Print the sum of all values in the linked list
    printf("Sum of values in the linked list: %d\n", sum_list(head));

    // Free memory allocated for the linked list
    free_list(head);

    return 0;
}
