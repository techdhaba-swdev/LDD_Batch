#include <stdio.h>

#include <pthread.h>

void *printMessage(void *arg) {

char *message = (char *)arg;

printf("%s\n", message);

return NULL;

}

int main() {

pthread_t thread;

char *message = "Hello from the thread!";

pthread_create(&thread, NULL, printMessage, (void *)message);

pthread_join(thread, NULL);

printf("Thread completed.\n");

return 0;

}
