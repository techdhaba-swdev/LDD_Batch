#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head_ref, int data);
int sum(struct Node* head);

#endif
