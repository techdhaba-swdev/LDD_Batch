#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    pthread_mutex_t mutex;
} Queue;

void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    pthread_mutex_init(&queue->mutex, NULL);
}

void cleanupQueue(Queue* queue) {
    pthread_mutex_destroy(&queue->mutex);
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    pthread_mutex_lock(&queue->mutex);
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    pthread_mutex_unlock(&queue->mutex);
}

int dequeue(Queue* queue) {
    pthread_mutex_lock(&queue->mutex);
    if (queue->front == NULL) {
        fprintf(stderr, "Queue is empty.\n");
        pthread_mutex_unlock(&queue->mutex);
        exit(EXIT_FAILURE);
    }

    Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);

    pthread_mutex_unlock(&queue->mutex);
    return data;
}

int main() {
    Queue queue;
    initQueue(&queue);

    // Example usage
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    cleanupQueue(&queue);

    return 0;
}
