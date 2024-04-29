// -- coding: utf-8 --
#include <stdio.h>
#include "linklist.h"

int main() {
    Node* head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    displayList(head);
    printf("\n%d\n",sum(head));
    freeList(&head);
    return 0;
}
