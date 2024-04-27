#ifndef DOUBLE_LINKLIST_H
#define DOUBLE_LINKLIST_H

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data);
void insertAtBeginning(Node** head, int data);
void insertAtEnd(Node** head, int data);
void deleteNode(Node** head, Node* del);
void displayList(Node* head);
void freeList(Node** head);

#endif
