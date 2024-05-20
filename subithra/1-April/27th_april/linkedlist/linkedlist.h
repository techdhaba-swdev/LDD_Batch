#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Define the structure of a node
struct Node;

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int new_data);

// Function to print all elements of the linked list
void printList(const struct Node* node);

// Function to free memory allocated for the linked list
void freeList(struct Node* head);

#endif
