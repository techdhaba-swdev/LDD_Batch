#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtEnd(Node** head_ref, int data) {
    Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to reverse a singly linked list
void reverseList(Node** head_ref) {
    Node *prev = NULL, *current = *head_ref, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    printf("Initial linked list:\n");
    display(head);

    reverseList(&head);

    printf("Linked list after reversal:\n");
    display(head);

    freeList(head); // Free memory allocated for the linked list
    return 0;
}


