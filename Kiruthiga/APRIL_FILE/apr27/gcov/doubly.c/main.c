#include<stdio.h>
#include"doublylinkedlist.h"
int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    printf("Doubly Linked List:\n");
    printList(head);

    return 0;
}

