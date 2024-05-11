#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10
#define MAX_NAME_LENGTH 50

// Structure for a customer
typedef struct {
    int customer_number;
    char name[MAX_NAME_LENGTH];
    // You can add more fields as needed, such as transaction type, etc.
} Customer;

// Structure for a queue
typedef struct {
    Customer items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

// Function to add a customer to the queue
void enqueue(Queue* queue, int customer_number) {
    if (isFull(queue)) {
        printf("Queue is full. Customer cannot be added.\n");
        return;
    }

    // Prompt user for customer's name
    printf("Enter customer's name: ");
    char name[MAX_NAME_LENGTH];
    fgets(name, MAX_NAME_LENGTH, stdin);
    strtok(name, "\n"); // Remove newline character from fgets result

    // Increment rear pointer and add customer to the queue
    queue->rear++;
    queue->items[queue->rear].customer_number = customer_number;
    strncpy(queue->items[queue->rear].name, name, MAX_NAME_LENGTH);
}

// Function to remove a customer from the queue
Customer dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No customer to dequeue.\n");
        exit(1);
    }
    Customer dequeuedCustomer = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return dequeuedCustomer;
}

// Function to display the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue:\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("Customer Number: %d, Name: %s\n", queue->items[i].customer_number, queue->items[i].name);
    }
}

int main() {
    Queue* queue = createQueue();

    // Enqueue some customers
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);

    // Display the queue
    display(queue);

    // Dequeue a customer
    Customer dequeuedCustomer = dequeue(queue);
    printf("Dequeued Customer Number: %d, Name: %s\n", dequeuedCustomer.customer_number, dequeuedCustomer.name);

    // Display the queue after dequeue
    display(queue);

    // Free the memory allocated for the queue
    free(queue);

    return 0;
}