#ifndef LINKLIST_H // Header guard to prevent multiple inclusions
#define LINKLIST_H

// Define the structure of a node in the linked list
typedef struct Node {
    int data;           // Data stored in the node (assuming integer data)
    struct Node* next;  // Pointer to the next node in the list
} Node;

// Function prototypes for the linked list operations
Node* createNode(int data);
Node* insertNode(Node* head, int data);
void displayList(Node* head);
void freeList(Node* head);

#endif
