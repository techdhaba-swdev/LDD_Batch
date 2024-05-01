#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        newNode->next = newNode; // For the first node, make it point to itself
    } else {
        struct Node* last = *head_ref;
        while (last->next != *head_ref) {
            last = last->next;
        }
        last->next = newNode; // Make the last node point to the new node
    }
    newNode->next = *head_ref; // Make the new node point to the head
    *head_ref = newNode; // Update the head to point to the new node
}

// Function to print the circular linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

// Driver code to test the implementation
int main() {
    struct Node* head = NULL;

    // Inserting nodes at the beginning
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);

    // Printing the circular linked list
    printf("Circular linked list: ");
    printList(head);

    return 0;
}
