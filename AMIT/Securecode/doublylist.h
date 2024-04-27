#ifndef DOUBLY_H
#define DOUBLY_H


// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int value);
void insertAtStart(struct Node** head, int value);
void displayList(struct Node* head);
void deleteList(struct Node** head);
#endif
