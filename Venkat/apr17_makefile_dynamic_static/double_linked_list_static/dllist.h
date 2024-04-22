#ifndef DLLIST_H
#define DLLIST_H

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data);
void insertAtEnd(struct Node** headRef, int data);
void displayList(struct Node* head);
int sumOfNodes(struct Node* head);

#endif
