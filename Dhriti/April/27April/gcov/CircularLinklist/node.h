#ifndef NODE_H
#define NODE_H

// Structure for a Node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data);

#endif

