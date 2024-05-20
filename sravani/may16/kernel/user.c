#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define DEVICE_PATH "/dev/my_device"

struct user_data {
  int value;
  char message[20];
};

void *write_to_device(void *arg) {
  int fd = *((int *)arg);
  struct user_data data;
 
  data.value = 123;
  strcpy(data.message, "Hello Kernel!");

  if (write(fd, &data, sizeof(data)) != sizeof(data)) {
    perror("Failed to write the message to the device");
    pthread_exit(NULL);
  }

  printf("Data written to the device\n"); pthread_exit(NULL);
}

void *read_from_device(void *arg) {
  int fd = *((int *)arg);
  struct user_data data;

  memset(&data, 0, sizeof(data));

  if (read(fd, &data, sizeof(data)) != sizeof(data)) {
    perror("Failed to read the message from the device");
    pthread_exit(NULL);
  }

  printf("Data read from the device: value = %d, message = %s\n", data.value, data.message);
  pthread_exit(NULL);
}

int main() {
  int fd;
  pthread_t write_thread, read_thread;

  fd = open(DEVICE_PATH, O_RDWR);
  if (fd < 0) {
    perror("Failed to open the device");
    return 0;
  } // Create read thread
  if (pthread_create(&read_thread, NULL, read_from_device, &fd) != 0) {
    perror("Failed to create read thread");
    close(fd);
    return 0;
  }

  // Wait for both threads to finish
  pthread_join(write_thread, NULL);
  pthread_join(read_thread, NULL);

  close(fd);
  return 0;
}


