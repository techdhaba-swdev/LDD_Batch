#include <stdio.h>
#include "CircularLinkedList.h"

int main() {
    struct Node* head = NULL;
    int data, sum = 0;

    // Insert five nodes into the circular linked list
    printf("Enter five integers to insert into the circular linked list:\n");
    for (int i = 0; i < 5; ++i) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    // Display the circular linked list
    printf("\nCircular Linked List: ");
    displayList(head);

    // Calculate the sum of the elements in the circular linked list
    struct Node* temp = head;
    do {
        sum += temp->data;
        temp = temp->next;
    } while (temp != head);

    // Display the sum
    printf("Sum of elements in the circular linked list: %d\n", sum);

    return 0;
}
