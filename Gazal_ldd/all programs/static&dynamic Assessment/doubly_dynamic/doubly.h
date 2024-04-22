#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int data);
int sumDoublyLinkedList(struct Node *head);
void freeDoublyLinkedList(struct Node *head);

#endif