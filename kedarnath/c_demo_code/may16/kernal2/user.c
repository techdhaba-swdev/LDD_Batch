#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

#define DEVICE_NAME "/dev/data_transfer"
#define DATA_SIZE sizeof(struct user_data)

struct user_data {
    int value;
    char message[20];
};

void *read_data(void *arg) {
    int fd = *(int *)arg;
    struct user_data data;

    
        // Read data from the device
        ssize_t ret = read(fd, &data, DATA_SIZE);
        if (ret == -1) {
            perror("Failed to read data");
           
        } else if (ret == 0) {
            printf("No data available\n");
           
        } else if (ret != DATA_SIZE) {
            printf("Incomplete data read\n");
           
        }

        printf("Received data from kernel: value = %d, message = %s\n", data.value, data.message);
    

    return NULL;
}

int main() {
    int fd, ret;
    struct user_data data;
    pthread_t tid;

    // Open the device for writing
    fd = open(DEVICE_NAME, O_WRONLY);
    if (fd == -1) {
        perror("Failed to open device");
        exit(1);
    }

    // Prepare data to send
    data.value = 42;
    snprintf(data.message, sizeof(data.message), "Hello from user-space!");

    // Send data to the kernel
    ret = write(fd, &data, DATA_SIZE);
    if (ret != DATA_SIZE) {
        perror("Failed to write data");
        close(fd);
        exit(1);
    }

    printf("Data sent successfully!\n");

    // Close the device (optional, as the program exits)
    close(fd);

    // Open the device for reading
    fd = open(DEVICE_NAME, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open device for reading");
        exit(1);
    }

    // Create pthread to read data from the device
    if (pthread_create(&tid, NULL, read_data, &fd) != 0) {
        perror("Failed to create thread");
        close(fd);
        exit(1);
    }

    // Wait for pthread to finish
    if (pthread_join(tid, NULL) != 0) {
        perror("Failed to join thread");
        close(fd);
        exit(1);
    }

    // Close the device
    close(fd);

    return 0;
}



