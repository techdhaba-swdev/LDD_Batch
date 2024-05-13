#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_NAME "/dev/reverse_string_dev"
#define NUM_USERS 3

void *user_thread(void *arg) {
    char *message = (char *)arg;
    int fd, message_len;
    char reversed_message[100];

    // Open the device file
    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open device");
        return NULL;
    }

    // Send the string to the device
    message_len = strlen(message);
    if (write(fd, message, message_len) != message_len) {
        perror("Failed to write to device");
        close(fd);
        return NULL;
    }

    // Read the reversed string
    message_len = read(fd, reversed_message, sizeof(reversed_message));
    if (message_len < 0) {
        perror("Failed to read from device");
        close(fd);
        return NULL;
    }

    // Null-terminate the reversed string
    reversed_message[message_len] = '\0';

    // Print the original and reversed strings
    printf("Original string: %s\n", message);
    printf("Reversed string: %s\n", reversed_message);

    // Close the device file
    close(fd);

    return NULL;
}

int main() {
    pthread_t threads[NUM_USERS];
    char *messages[NUM_USERS] = {"Message 1", "Message 2", "Message 3"};

    for (int i = 0; i < NUM_USERS; i++) {
        if (pthread_create(&threads[i], NULL, user_thread, messages[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    for (int i = 0; i < NUM_USERS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
