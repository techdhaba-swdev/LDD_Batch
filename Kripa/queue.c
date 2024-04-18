#include <stdio.h>
#include <stdlib.h>

struct Customer {
    int id;
    struct Customer* next;
};
struct Queue {
    struct Customer* front;
    struct Customer* rear;
};
struct Customer* createCustomer(int id) {
    struct Customer* newCustomer = (struct Customer*)malloc(sizeof(struct Customer));
    if (newCustomer == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newCustomer->id = id;
    newCustomer->next = NULL;
    return newCustomer;
}
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}
void enqueue(struct Queue* queue, int id) {
    struct Customer* newCustomer = createCustomer(id);
    if (isEmpty(queue)) {
        queue->front = newCustomer;
        queue->rear = newCustomer;
    } else {
        queue->rear->next = newCustomer;
        queue->rear = newCustomer;
    }
}
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    struct Customer* temp = queue->front;
    int id = temp->id;
    queue->front = temp->next;
    free(temp);
    return id;
}
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    struct Customer* current = queue->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->id);
        current = current->next;
    }
    printf("\n");
}
int main() {
    struct Queue* queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    displayQueue(queue);

    int servedCustomer = dequeue(queue);
    printf("Customer served: %d\n", servedCustomer);

    displayQueue(queue);

    return 0;
}