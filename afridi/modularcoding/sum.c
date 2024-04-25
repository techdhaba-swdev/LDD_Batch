#include<stddef.h>
#include "sum.h"

// Function to calculate the sum of elements in the list
int calculateSum(struct Node* head) {
    int sum = 0;                // Initialize sum to zero
    struct Node* current = head;// Start from the head of the list
    // Traverse the list and add each element to the sum
    while (current != NULL) {
        sum += current->data;   // Add the data of the current node to the sum
        current = current->next;// Move to the next node
    }
    return sum; // Return the calculated sum
}
