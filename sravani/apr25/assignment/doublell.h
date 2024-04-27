#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

// Doubly linked list node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
struct Node* insertAtBeginning(struct Node* head, int data);
struct Node* insertAtEnd(struct Node* head, int data);
struct Node* deleteNode(struct Node* head, int data);
void display(struct Node* head);

#endif /* DOUBLY_LINKED_LIST_H */
