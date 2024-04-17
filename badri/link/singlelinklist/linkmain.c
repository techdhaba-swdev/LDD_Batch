#include <stdio.h>
#include "link.h"

// Static linking
extern void insertNode(Node **head, int data);

int main() {
    Node *head = NULL; // Initialize an empty list

    // Inserting nodes
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);
    insertNode(&head, 50);

    // Printing the values of nodes
    printf("Values stored in the nodes: ");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
