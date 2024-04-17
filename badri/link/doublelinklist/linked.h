#ifndef DOUBLY_NODE_H
#define DOUBLY_NODE_H

typedef struct DoublyNode {
    int data;
    struct DoublyNode *prev;
    struct DoublyNode *next;
} DoublyNode;

#endif
