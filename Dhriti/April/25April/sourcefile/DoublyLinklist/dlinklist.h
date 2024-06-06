#ifndef DLINKLIST_H
#define DLINKLIST_H

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function declarations
struct Node* createNode(int data);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void deleteNode(struct Node** head, int key);
void displayList(struct Node* head);
void search(struct Node* head, int key);

#endif

