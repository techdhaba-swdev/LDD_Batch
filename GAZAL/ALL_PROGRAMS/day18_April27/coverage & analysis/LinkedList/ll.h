#ifndef LINKEDLIST_H
#define LINKEDLIST_H
// Define a struct to represent the linked list
#define MAX_NODES 100
// Define the structure for a node
struct Node {
    int data;
    int next; // Index of the next node in the array
};


struct LinkedList {
    struct Node nodes[MAX_NODES];
    int head; // Index of the first node in the linked list
    int tail; // Index of the last node in the linked list
    int size; // Current size of the linked list
};

// Function prototypes
void initLinkedList(struct LinkedList *list);
void addNode(struct LinkedList *list, int value);
int sumLinkedList(struct LinkedList *list);

#endif

