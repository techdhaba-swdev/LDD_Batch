#include <stdio.h>
#include "linked_list.h" // Include the linked list module
#include "sum.h"         // Include the sum calculation module

int main() {
    struct Node* head = NULL; // Initialize the head of the list to NULL
    
    // Insert some elements into the list
    insertNode(&head, 5);
    insertNode(&head, 10);
    insertNode(&head, 15);
    
    // Print the elements of the list
    printf("Linked List: ");
    printList(head);
    
    // Calculate the sum of elements in the list
    int sum = calculateSum(head);
    // Print the sum
    printf("Sum of elements: %d\n", sum);
    
    // Free the memory allocated for the list
    freeList(head);
    
    return 0;
}
