#include <stdio.h>
#include <stdlib.h>
#include "circular_linked_list.h"

void insert(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = data;
    new_node->next = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }

    while (last->next != *head_ref)
        last = last->next;

    last->next = new_node;
}

int sum(struct Node* head) {
    struct Node* temp = head;
    int sum = 0;
    if (head != NULL) {
        do {
            sum += temp->data;
            temp = temp->next;
        } while (temp != head);
    }
    return sum;
}
