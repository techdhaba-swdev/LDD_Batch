#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <poll.h>
#include <string.h>
#include <pthread.h>

#define DEVICE "/dev/example_char_device"
#define BUF_LEN 80

// Structure to hold data for thread functions
struct ThreadData {
    int fd;
    int num1;
    int num2;
};

// Function prototypes for thread functions
void *addition_thread(void *arg);
void *subtraction_thread(void *arg);

int main() {
    int fd = open(DEVICE, O_RDWR);
    if (fd == -1) {
        perror("Failed to open device");
        return EXIT_FAILURE;
    }

    // Create thread data structures
    struct ThreadData add_data, sub_data;

    // Initialize thread data
    add_data.fd = fd;
    sub_data.fd = fd;

    // Get input from user
    printf("Enter two numbers: ");
    scanf("%d %d", &add_data.num1, &add_data.num2);
    sub_data.num1 = add_data.num1;
    sub_data.num2 = add_data.num2;

    // Create threads for addition and subtraction
    pthread_t add_thread, sub_thread;
    pthread_create(&add_thread, NULL, addition_thread, (void *)&add_data);
    pthread_create(&sub_thread, NULL, subtraction_thread, (void *)&sub_data);

    // Wait for threads to finish
    pthread_join(add_thread, NULL);
    pthread_join(sub_thread, NULL);

    close(fd);
    return EXIT_SUCCESS;
}

// Thread function for addition
void *addition_thread(void *arg) {
    struct ThreadData *data = (struct ThreadData *)arg;
    char buffer[BUF_LEN];

    // Prepare data for addition
    sprintf(buffer, "%d+%d", data->num1, data->num2);

    // Write data to device
    write(data->fd, buffer, strlen(buffer));

    // Read result from device
    read(data->fd, buffer, BUF_LEN);
    printf("Addition result: %s\n", buffer);

    pthread_exit(NULL);
}

// Thread function for subtraction
void *subtraction_thread(void *arg) {
    struct ThreadData *data = (struct ThreadData *)arg;
    char buffer[BUF_LEN];

    // Prepare data for subtraction
    sprintf(buffer, "%d-%d", data->num1, data->num2);

    // Write data to device
    write(data->fd, buffer, strlen(buffer));

    // Read result from device
    read(data->fd, buffer, BUF_LEN);
    printf("Subtraction result: %s\n", buffer);

    pthread_exit(NULL);
};
