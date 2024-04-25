#include "clink.h"//Include the header file that contains the structure definition and function prototypes
#include <stdio.h>  // Include standard I/O functions

int main() {
    struct Node* head = NULL;  // Initialize an empty circular linked list
    int values[] = {1, 2, 3, 4, 5}; // Array of values to add to the list

    // Add nodes to the list
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        addNode(&head, values[i]);
    }

    // Print the list
    printf("Circular Linked List: ");
    printList(head);

    // Calculate the sum of all node values
    int sum = calculateSum(head);
    printf("Sum of all node values: %d\n", sum);

    // Free memory allocated for the list
    freeList(&head);
    return 0;
}
