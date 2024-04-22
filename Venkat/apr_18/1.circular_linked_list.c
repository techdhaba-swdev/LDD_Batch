#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void addNode(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;

    newNode->data = value;
    newNode->next = *head;

    if (*head != NULL) {
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newNode;
    } else {
        newNode->next = newNode;
    }

    *head = newNode;
}

int sumOfValues(struct Node* head) {
    if (head == NULL)
        return 0;

    int sum = 0;
    struct Node* temp = head;

    do {
        sum += temp->data;
        temp = temp->next;
    } while (temp != head);

    return sum;
}

int main() {
    struct Node* head = NULL;
    int numNodes, value, sum;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the values for each node:\n");
    for (int i = 0; i < numNodes; i++) {
        scanf("%d", &value);
        addNode(&head, value);
    }

    sum = sumOfValues(head);
    printf("Sum of values in the circular linked list: %d\n", sum);

    return 0;
}