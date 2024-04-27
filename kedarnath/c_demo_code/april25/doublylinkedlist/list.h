#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>


// Define the structure for a node in the doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void insertEnd(Node** head, int data);
void printList(Node* head);
void freeList(Node** head);

#endif

