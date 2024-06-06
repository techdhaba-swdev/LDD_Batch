#include <stdio.h>
#include "Clinklist.h"

int main() {
    // Create a new circular linked list
    struct CircularLinkedList list;
    list.head = NULL;

    // Insert elements into the circular linked list
    append(&list, 1);
    append(&list, 2);
    append(&list, 3);

    // Display the circular linked list
    display(&list);

    return 0;
}

