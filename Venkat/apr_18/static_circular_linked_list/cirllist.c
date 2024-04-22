#include "cirllist.h"
#include <stdlib.h>

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
