#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* newNode(int data) {
    struct Node* newNodePtr = (struct Node*)malloc(sizeof(struct Node));
    if (newNodePtr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNodePtr->data = data;
    newNodePtr->next = NULL;
    return newNodePtr;
}


void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNodePtr = newNode(data);
    if (*headRef == NULL) {
        *headRef = newNodePtr;
        newNodePtr->next = *headRef; 
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != *headRef) {
        temp = temp->next;
    }
    temp->next = newNodePtr;
    newNodePtr->next = *headRef;
    *headRef = newNodePtr;
}


void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 9);

    printf("Circular linked list: ");
    displayList(head);

    return 0;
}
