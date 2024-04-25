#include <stdio.h>
#include "doublelink.h"

int main() {
    // Create a new doubly linked list
    DoublyLinkedList* list = createDoublyLinkedList();

    // Add nodes to the end of the list
    addNodeAtEnd(list, 1);
    addNodeAtEnd(list, 2);
    addNodeAtEnd(list, 3);
    addNodeAtEnd(list, 4);
    addNodeAtEnd(list, 5);

    // Print the elements of the list
    printf("List: ");
    printList(list);

    // Calculate the sum of all elements in the list
    int sum = sumList(list);
    printf("Sum of all elements: %d\n", sum);

    return 0;
}
