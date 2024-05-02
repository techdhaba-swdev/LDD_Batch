#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Structure for a node in the stack
struct Node {
    int data;
    struct Node* next;
};

// Global variable for the top of the stack
struct Node* top = NULL;

// Function to push a new node onto the stack
void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

// Function to pop a node from the stack
int pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        exit(1);
    }
    struct Node* temp = top;
    int data = temp->data;
    top = top->next;
    free(temp);
    return data;
}

// Function to calculate the sum of all nodes in the stack
int sumOfNodes() {
    struct Node* current = top;
    int sum = 0;
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}

// Signal handler function
void signal_handler(int signal_number) {
    printf("Received signal: %d\n", signal_number);
    printf("Exiting...\n");
    exit(0);
}

int main() {
    // Register signal handler for SIGTERM (termination signal)
    if (signal(SIGTERM, signal_handler) == SIG_ERR) {
        perror("Unable to set signal handler for SIGTERM");
        return 1;
    }

    // Push some data onto the stack
    push(10);
    push(20);
    push(30);

    // Calculate and print the sum of all nodes in the stack
    printf("Sum of all nodes in the stack: %d\n", sumOfNodes());

    // Wait for termination signal
    printf("Waiting for termination signal...\n");
    while(1) {
        sleep(1);
    }

    return 0;
}