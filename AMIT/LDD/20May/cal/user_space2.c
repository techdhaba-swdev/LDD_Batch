#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/char_device"

                                
int num1 = 10;
int num2 = 5;

// Function to add or subtract numbers in kernel space
void* perform_operation(void* arg) {
    int operation = (int)arg; // 0 for addition, 1 for subtraction

    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd == -1) {
        perror("Error opening device file");
        return NULL;
    }

    // Send numbers to kernel space
    write(fd, &num1, sizeof(int));
    write(fd, &num2, sizeof(int));

    // Perform addition or subtraction
    int result;
    read(fd, &result, sizeof(int));

    close(fd);

    if (operation == 0)
        printf("Sum: %d\n", result);
    else
        printf("Difference: %d\n", result);

    return NULL;
}

int main() {
    pthread_t add_tid, subtract_tid;

                                                                           // Create threads for addition and subtraction
    pthread_create(&add_tid, NULL, perform_operation, (void*)&num1);
    pthread_create(&subtract_tid, NULL, perform_operation, (void*)&num2);

                                                                      // Wait for threads to finish
    pthread_join(add_tid, NULL);
    pthread_join(subtract_tid, NULL);

    return 0;
}
