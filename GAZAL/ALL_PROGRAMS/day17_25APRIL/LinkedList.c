#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the linked list
void insertNode(struct Node** headRef, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to calculate the sum of values in the linked list
int sumLinkedList(struct Node* head) {
    int sum = 0;
    while (head != NULL) {
        sum += head->data;
        head = head->next;
    }
    return sum;
}

int main() {
    struct Node* head = NULL;
    int numNodes, value;

    // Ask the user for the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    // Ask the user to enter values for each node
    for (int i = 0; i < numNodes; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insertNode(&head, value);
    }

    // Print the linked list
    printf("Linked List: ");
    printLinkedList(head);

    // Calculate the sum of values in the linked list
    int sum = sumLinkedList(head);
    printf("Sum of values in the linked list: %d\n", sum);

    return 0;
}