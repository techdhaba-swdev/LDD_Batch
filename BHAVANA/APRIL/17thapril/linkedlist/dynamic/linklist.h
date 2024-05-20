#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void appendNode(Node **head, int value);
int sumLinkedList(Node *head);
void freeLinkedList(Node *head);

#endif
