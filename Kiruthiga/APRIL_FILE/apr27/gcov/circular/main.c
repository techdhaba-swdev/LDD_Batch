#include<stdio.h>
#include"circularlinkedlist.h"
int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 2);

    printf("Circular Linked List: ");
    printList(head);

    return 0;
}
