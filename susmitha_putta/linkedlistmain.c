#include "linkedlist.h"
#include <stdio.h>

int main() {
    int k = 0;
    //insert elements into the linked list at beginning and ending
    insertAtBegin(12);
    insertAtBegin(22);
    insertAtEnd(30);
    insertAtEnd(44);
    insertAtBegin(50);
    //printing linkedlist
    printf("Linked List: ");
    printlist();
    //deleting at beginning and ending and specified elements
    deleteAtBegin();
    deleteAtEnd();
    deleteNode(12);
    //printing list after deletion
    printf("\nLinked List after deletion: ");
    printlist();
    //insert additional elements and print the updated list
    insertAtBegin(4);
    insertAtBegin(16);
    printf("\nUpdated Linked List: ");
    printlist();
    //search elements in the list
    k = searchList(16);
    if (k == 1)
        printf("\nElement is found");
    else
        printf("\nElement is not present in the list");
    return 0;
}
