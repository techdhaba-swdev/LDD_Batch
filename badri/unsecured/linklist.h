#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Structure representing a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function declarations
Node* createNode(int data);
void insertAtEnd(Node** headRef, int data);
int sumOfElements(Node* head);
void freeList(Node* head);
#endif
