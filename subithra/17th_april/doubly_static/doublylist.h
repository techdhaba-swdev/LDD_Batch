// linklist.h

#ifndef LINKLIST_H
#define LINKLIST_H

// Define the structure for a node
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Function prototypes
Node *create_node(int data);
void append(Node **head_ref, int data);
int sum_list(Node *head);
void free_list(Node *head);

#endif /* LINKLIST_H */
