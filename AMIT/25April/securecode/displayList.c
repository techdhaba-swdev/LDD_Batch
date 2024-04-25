#include<stdio.h>
#include<stdlib.h>
#include"mystruct.h"

// Function to display the linked list
void displayList(struct Node* head) {          //displayList is the function with parameter stuct Node* head , a pointer to head
    struct Node* current = head;               //initialize local pointer current with value of head pointer
    while (current != NULL) {                 //while loop will continue till current becomes NULL
        printf("%d -> ", current->data);       //data of the current node is printed
        current = current->next;
    }
    print_message("NULL\n");
}

