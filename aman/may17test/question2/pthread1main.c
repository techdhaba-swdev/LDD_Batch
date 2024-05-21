#include "pthread1.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    pthread_t readThread, evenWriteThread, oddWriteThread;
    LineBuffer evenBuffer, oddBuffer;

    pthread_mutex_init(&evenBuffer.mutex, NULL);
    pthread_mutex_init(&oddBuffer.mutex, NULL);

    evenBuffer.count = 0;
    oddBuffer.count = 0;

    if (pthread_create(&readThread, NULL, readLines, &evenBuffer)) {
        perror("Error creating read thread");
        exit(EXIT_FAILURE);
    }

    if (pthread_join(readThread, NULL)) {
        perror("Error joining read thread");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&evenWriteThread, NULL, writeLines, &evenBuffer)) {
        perror("Error creating even write thread");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&oddWriteThread, NULL, writeLines, &oddBuffer)) {
        perror("Error creating odd write thread");
        exit(EXIT_FAILURE);
    }

    if (pthread_join(evenWriteThread, NULL)) {
        perror("Error joining even write thread");
        exit(EXIT_FAILURE);
    }

    if (pthread_join(oddWriteThread, NULL)) {
        perror("Error joining odd write thread");
        exit(EXIT_FAILURE);
    }

    pthread_mutex_destroy(&evenBuffer.mutex);
    pthread_mutex_destroy(&oddBuffer.mutex);

    printf("Even lines:\n");
    system("cat even.txt");
    printf("\nOdd lines:\n");
    system("cat odd.txt");

    return 0;
}

