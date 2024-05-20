#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlist.h"
// Structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a new node at the beginning of the doubly linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = *head_ref;

    if (*head_ref != NULL)
        (*head_ref)->prev = new_node;

    *head_ref = new_node;
}

// Function to traverse and print the doubly linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
