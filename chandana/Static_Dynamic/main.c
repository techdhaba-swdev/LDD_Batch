#include <stdio.h>
#include "linklist.h"

int main() {
   struct  Node* head = NULL;
   int sum=0;  

    // Create a linked list of 5 nodes
    for (int i = 1; i <= 5; i++) {
        append(&head, i);
    }

    // Add all values from all the nodes
    sum = sumNodes(head);

    // Print the sum
    printf("Sum of all values in the linked list: %d\n", sum);

    return 0;
}
