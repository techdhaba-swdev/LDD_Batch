#include <stdio.h>
#include "singly.c"

int main() {
    
    struct Node *head = createNode(1);
    struct Node *second = createNode(2);
    struct Node *third = createNode(3);
    struct Node *fourth = createNode(4);
    struct Node *fifth = createNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    int sum = sumSinglyLinkedList(head);

    printf("Sum of all values in the singly linked list: %d\n", sum);

    freeSinglyLinkedList(head);

    return 0;
}