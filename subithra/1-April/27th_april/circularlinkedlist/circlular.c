
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node **head, int data) {
    if (head == NULL) {
        fprintf(stderr, "Invalid parameter: head is NULL\n");
        return;
    }
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
    } else {
        Node *last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
    }
}

void displayList(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void insertAtEnd(Node **head, int data) {
    if (head == NULL) {
        fprintf(stderr, "Invalid parameter: head is NULL\n");
        return;
    }
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
    } else {
        Node *last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head;
    }
}

void deleteNode(Node **head, int key) {
    if (head == NULL || *head == NULL) {
        fprintf(stderr, "Invalid parameter: head is NULL or list is empty\n");
        return;
    }
    Node *temp = *head;
    Node *prev = NULL;
    while (temp->data != key) {
        prev = temp;
        temp = temp->next;
        if (temp == *head) {
            printf("Node with data %d not found in the list.\n", key);
            return;
        }
    }
    if (temp == *head) {
        prev = *head;
        while (prev->next != *head) {
            prev = prev->next;
        }
        *head = temp->next;
        prev->next = *head;
        free(temp);
    } else {
        prev->next = temp->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);

    displayList(head);

    deleteNode(&head, 20);

    displayList(head);

    return 0;
}
