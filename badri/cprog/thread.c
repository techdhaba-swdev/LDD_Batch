#include <stdio.h>

#include <pthread.h>

void *thread_func(void *arg) {

printf("Thread ID: %lu\n", pthread_self());

return NULL;

}

int main() {

pthread_t tid[3];

for (int i = 0; i < 3; ++i) {

pthread_create(&tid[i], NULL, thread_func, NULL);

}

pthread_exit(NULL);

}
