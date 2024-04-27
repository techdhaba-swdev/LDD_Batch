#include "linked_list.h"
#include <stdio.h>
struct node
{
	int data;
	struct node *next;
};

int main() {
    int k = 0;
    insertAtBegin(12);
    insertAtBegin(22);
    insertAtEnd(30);
    insertAtEnd(44);
    insertAtBegin(50);
    insertAfterNode(head->next->next, 33);

    printf("Linked List: ");
    printList();
    deleteAtBegin();
    deleteAtEnd();
    deleteNode(12);
    printf("\nLinked List after deletion: ");
    printList();
    insertAtBegin(4);
    insertAtBegin(16);
    printf("\nUpdated Linked List: ");
    printList();
    k = searchList(16);
    if (k == 1)
        printf("\nElement is found");
    else
        printf("\nElement is not present in the list");
    return 0;
}
