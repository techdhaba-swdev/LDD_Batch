#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
struct QueueNode {
    int customer_id;
    struct QueueNode* next;
};

typedef struct QueueNode QueueNode;

// Define the structure for the queue
struct Queue {
    QueueNode* front;
    QueueNode* rear;
};

typedef struct Queue Queue;

// Function to create a new queue node
QueueNode* createNode(int customer_id) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->customer_id = customer_id;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
Queue* initializeQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Function to enqueue a customer
void enqueue(Queue* queue, int customer_id) {
    QueueNode* newNode = createNode(customer_id);
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue a customer
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        exit(1);
    }
    QueueNode* temp = queue->front;
    int customer_id = temp->customer_id;
    queue->front = queue->front->next;
    free(temp);
    return customer_id;
}

// Function to display the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    QueueNode* current = queue->front;
    printf("Queue of customers:\n");
    while (current != NULL) {
        printf("%d ", current->customer_id);
        current = current->next;
    }
    printf("\n");
}

// Main function to test the queue management program
int main() {
    Queue* queue = initializeQueue();

    // Simulate customers arriving and leaving
    enqueue(queue, 101);
    enqueue(queue, 102);
    enqueue(queue, 103);

    printf("Initial queue:\n");
    displayQueue(queue);

    printf("Customer served: %d\n", dequeue(queue));

    enqueue(queue, 104);

    printf("Updated queue:\n");
    displayQueue(queue);

    // Free memory allocated for the queue
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);

    return 0;
}


