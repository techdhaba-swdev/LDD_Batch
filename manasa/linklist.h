#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
    int data;
    struct node *next;
};

void printList();
void insertAtBegin(int data);
void insertAtEnd(int data);
void insertAfterNode(struct node *list, int data);
void deleteAtBegin();
void deleteAtEnd();
void deleteNode(int key);
int searchList(int key);

#endif
