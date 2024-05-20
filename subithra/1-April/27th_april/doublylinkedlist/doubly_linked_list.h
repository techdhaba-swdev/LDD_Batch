#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

// Declare the Node structure
typedef struct Node Node;

// Function declarations
Node* createNode(int data);
void insertAtBeginning(Node **head, int data);
void displayList(Node *head);
void insertAtEnd(Node **head, int data);
void deleteNode(Node **head, int key);
void freeList(Node **head);

#endif /* DOUBLY_LINKED_LIST_H */
