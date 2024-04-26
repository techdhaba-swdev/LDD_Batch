#include <stdio.h>
#include "linklist.h"

int main() {
    Node* head = NULL;

    // Add elements to the list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    // Calculate the sum of all elements
    int sum = sumOfElements(head);
    printf("Sum of all elements in the list: %d\n", sum);// prints the sum all data in node

    // Free the memory allocated for the list
    freeList(head);

    return 0; // successfull indication of program complition
}
