#include <stdio.h>
#include "linked.h"

void printList(DoublyNode *head);
void insertNode(DoublyNode **head, int data);
DoublyNode* createNode(int data);

int main() {
    DoublyNode *head = NULL; // Initialize an empty list

    // Inserting nodes
    insertNode(&head, 5);
    insertNode(&head, 10);
    insertNode(&head, 15);
    insertNode(&head, 20);
    insertNode(&head, 25);

    // Print all nodes
    printList(head);

    return 0;
}
