#include<stdio.h>
#include<stdlib.h>
#include"doublylist.h"

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning
    insertAtStart(&head, 10);
    insertAtStart(&head, 20);
    insertAtStart(&head, 30);

    // Display the doubly linked list
    printf("Doubly Linked List: ");
    displayList(head);

    // Clean up and free memory
    deleteList(&head);

    return 0;
}
