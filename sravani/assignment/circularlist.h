#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

// Structure for a node in the circular linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void insertNode(Node** head, int data);
void deleteNode(Node** head, int data);
void displayList(Node* head);

#endif /* CIRCULAR_LIST_H */
