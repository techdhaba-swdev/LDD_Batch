#include<stdio.h>
#include<stdlib.h>
#include"doublylist.h"

// Function to delete the entire doubly linked list
void deleteList(struct Node** head) {
    struct Node* current = *head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

