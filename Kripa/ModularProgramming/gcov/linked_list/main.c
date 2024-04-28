#include <stdio.h>
#include "singly_linklist.h"

int main() {
    Node* head = NULL;

    // Append elements to the linked list
    append(&head, 5);
    append(&head, 3);
    append(&head, 9);
    append(&head, 7);
    append(&head, 2);
    append(&head, 1);
    append(&head, 6);

    int key = 7;

    // Perform linear search
    int result = linearSearch(head, key);

    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the linked list\n", key);
    }

    return 0;
}

