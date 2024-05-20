// linklist.c

#include <stdlib.h>
#include "linklist.h"

// Function to create a new node
Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to append a new node to the end of the list
void append(Node **head_ref, int data) {
    Node *new_node = create_node(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    Node *last_node = *head_ref;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

// Function to calculate the sum of all values in the linked list
int sum_list(Node *head) {
    int sum = 0;
    Node *current = head;
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}

// Function to free memory allocated for the linked list
void free_list(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
