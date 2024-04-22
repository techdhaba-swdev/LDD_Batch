#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data);
int sumSinglyLinkedList(struct Node *head);
void freeSinglyLinkedList(struct Node *head);

#endif 