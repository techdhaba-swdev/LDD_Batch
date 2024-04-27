#ifndef LINKLIST_H
#define LINKLIST_H
//Create HEADER Guard to prevent multiple inclusions of the same header file 

#include <stdio.h>
#include <stdlib.h>
//Standard Input/Output library.

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Linked list structure
typedef struct LinkedList {
    Node* head;
} LinkedList;

// Function prototypes
LinkedList* createLinkedList();
Node* createNode(int data);
void addNode(LinkedList* list, int data);
void printList(LinkedList* list);
int sumList(LinkedList* list);

#endif
//
