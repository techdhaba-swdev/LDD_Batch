#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node {
    int data;           // Data of the node
    struct Node* prev;  // Pointer to the previous node
    struct Node* next;  // Pointer to the next node
} Node;

// Doubly linked list structure
typedef struct DoublyLinkedList {
    Node* head;         // Pointer to the head of the list
    Node* tail;         // Pointer to the tail of the list
} DoublyLinkedList;

// Function prototypes
DoublyLinkedList* createDoublyLinkedList();  // Create an empty doubly linked list
Node* createNode(int data);                  // Create a new node with given data
void addNodeAtEnd(DoublyLinkedList* list, int data);  // Add a node to the end of the list
void printList(DoublyLinkedList* list);       // Print the elements of the list
int sumList(DoublyLinkedList* list);          // Calculate the sum of all elements in the list

#endif
