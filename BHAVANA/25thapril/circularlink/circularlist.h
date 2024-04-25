#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the circular linked list
typedef struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node
} Node;

// Function prototypes for the circular linked list operations
Node* createNode(int data);
Node* insertNode(Node* head, int data);
void displayList(Node* head);
void freeList(Node* head);

#endif
