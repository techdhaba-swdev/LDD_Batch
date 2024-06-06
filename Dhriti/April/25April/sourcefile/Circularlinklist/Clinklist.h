#ifndef CLINKLIST_H
#define CLINKLIST_H
#include "node.h"

// Structure for the Circular Linked List
struct CircularLinkedList {
    struct Node* head;
};

// Function to append a new node with the given data to the end of the list
void append(struct CircularLinkedList* list, int data);

// Function to display the elements of the circular linked list
void display(struct CircularLinkedList* list);

#endif

