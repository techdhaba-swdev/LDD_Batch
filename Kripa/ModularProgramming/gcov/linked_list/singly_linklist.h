#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

// Structure representing a node in the singly linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function declarations
Node* createNode(int data);
void append(Node** headRef, int data);
int linearSearch(Node* head, int key);

#endif

