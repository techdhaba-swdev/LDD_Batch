#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* newNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNodePtr = newNode(data);
    if (*headRef == NULL) {
        *headRef = newNodePtr;
        return;
    }
    newNodePtr->next = *headRef;
    (*headRef)->prev = newNodePtr;
    *headRef = newNodePtr;
}


void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 9);

   
    printf("Doubly linked list: ");
    displayList(head);

    return 0;
}
