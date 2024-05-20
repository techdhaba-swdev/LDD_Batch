#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure for passing arguments to threads
struct thread_args {
    int num1;
    int num2;
};

// Function for addition
void *addition(void *arg) {
    struct thread_args *args = (struct thread_args *)arg;
    int result = args->num1 + args->num2;
    printf("Result of addition: %d\n", result);
    return NULL;
}

// Function for subtraction
void *subtraction(void *arg) {
    struct thread_args *args = (struct thread_args *)arg;
    int result = args->num1 - args->num2;
    printf("Result of subtraction: %d\n", result);
    return NULL;
}

int main() {
    pthread_t add_thread, sub_thread;
    struct thread_args add_args, sub_args;

    // Get user input for numbers
    printf("Enter first number: ");
    scanf("%d", &add_args.num1);
    printf("Enter second number: ");
    scanf("%d", &add_args.num2);

    // Set arguments for subtraction
    sub_args.num1 = add_args.num1;
    sub_args.num2 = add_args.num2;

    // Create threads for addition and subtraction
    pthread_create(&add_thread, NULL, addition, (void *)&add_args);
    pthread_create(&sub_thread, NULL, subtraction, (void *)&sub_args);

    // Wait for threads to finish
    pthread_join(add_thread, NULL);
    pthread_join(sub_thread, NULL);

    return 0;
}
