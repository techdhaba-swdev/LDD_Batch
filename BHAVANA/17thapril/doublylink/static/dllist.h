#ifndef DLLIST_H
#define DLLIST_H

#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

void appendNode(Node **head, int value);
int sumList(Node *head);
void printList(Node *head);
void freeList(Node *head);

#endif
