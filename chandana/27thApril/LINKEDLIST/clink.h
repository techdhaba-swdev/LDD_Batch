#ifndef CLINK_H
#define CLINK_H

// Define a structure for a node in the circular linked list
struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node in the list
};

// Function prototypes
struct Node* createNode(int data);     // Create a new node with the given data
void addNode(struct Node** head, int data); // Add a new node with the given data to the end of the list
int calculateSum(struct Node* head);   // Calculate the sum of all node values in the list
void printList(struct Node* head);     // Print all node values in the list
void freeList(struct Node** head);     // Free all memory allocated for the list

#endif
