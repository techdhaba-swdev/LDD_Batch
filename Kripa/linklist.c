#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}
struct Node* deleteNode(struct Node* head, int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key not found\n");
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main() {
    struct Node* head = NULL;

    head = insertAtBeginning(head, 1);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 3);

    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    printf("Initial list: ");
    printList(head);

 
    head = deleteNode(head, 3);
    printf("After deleting 3: ");
    printList(head);

    return 0;
}