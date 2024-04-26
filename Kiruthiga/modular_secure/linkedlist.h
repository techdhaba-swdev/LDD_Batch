#ifndef LINKEDLIST_H
#define LINKEDLIST_H
//function prototypes
struct Node;
void insertAtBeginning(struct Node** head_ref, int new_data);
void printList(const struct Node* node);
void freeList(struct Node* head);
#endif
