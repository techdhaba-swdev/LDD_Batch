#ifndef LINKEDLIST_H
#define LINKEDLIST_H
// Define a struct to represent the linked list
#define MAX_NODES 100
// Define the structure for a node
struct Node;


struct LinkedList;

// Function prototypes
void initLinkedList(struct LinkedList *list);
void addNode(struct LinkedList *list, int value);
int sumLinkedList(struct LinkedList *list);

#endif


