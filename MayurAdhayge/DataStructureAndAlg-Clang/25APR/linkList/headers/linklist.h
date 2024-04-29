// -- coding: utf-8 --
#ifndef LINKLIST_H
#define LINKLIST_H

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data);
void insertNode(Node** head, int data);
int sum(Node* head);
void displayList(Node* head);
void freeList(Node** head);

#endif 
