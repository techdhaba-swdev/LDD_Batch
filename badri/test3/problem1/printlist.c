#include "header.h"

// Function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        printf("ID: %d, Name: %s\n", head->data.id, head->data.name);
        head = head->next;
    }
}

