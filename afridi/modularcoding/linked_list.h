#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Define the structure for a node in the linked list
struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node
};

// Function prototypes for linked list operations
struct Node* createNode(int data);    // Create a new node
void insertNode(struct Node** head, int data); // Insert a new node at the beginning of the list
void printList(struct Node* head);     // Print the elements of the list
void freeList(struct Node* head);      // Free the memory allocated for the list

#endif
