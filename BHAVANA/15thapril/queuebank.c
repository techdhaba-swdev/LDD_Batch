#include <stdio.h>
#include <stdlib.h>

struct Customer {
    char name[50];
};

struct Node {
    struct Customer data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Node* newNode(struct Customer customer) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = customer;
    node->next = NULL;
    return node;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, struct Customer customer) {
    struct Node* node = newNode(customer);
    if (queue->rear == NULL) {
        queue->front = queue->rear = node;
        return;
    }
    queue->rear->next = node;
    queue->rear = node;
}

struct Customer dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        struct Customer empty_customer = {""};
        return empty_customer;
    }
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    struct Customer customer = temp->data;
    free(temp);
    return customer;
}

int main() {
    struct Queue* queue = createQueue();

    struct Customer bhavana = {"bhavana"};
    struct Customer preethi = {"preethi"};
    struct Customer neha = {"neha"};

    enqueue(queue, bhavana);
    enqueue(queue, preethi);
    enqueue(queue, neha);

    printf("Queue size: %d\n", queue->front == NULL ? 0 : 1);

    while (queue->front != NULL) {
        struct Customer serving_customer = dequeue(queue);
        printf("Serving: %s\n", serving_customer.name);
    }

    return 0;
}
