#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Define the structure for a node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function prototypes
Node* createNode(int data);
void insert(Node **head, int data);
void printList(Node *head);
void freeList(Node *head);



#endif

