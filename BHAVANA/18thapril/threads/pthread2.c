#include <stdio.h>
#include <pthread.h>

void* printMsg(void* msg) {
    printf("%s\n", (char*)msg);
    return NULL;
}

int main(int argc, char** argv) {
    pthread_t thrdID;

    printf("creating a new thread\n");
    pthread_create(&thrdID, NULL, printMsg, argv[1]);
    printf("created thread %ld\n", thrdID); // Changed %d to %ld for pthread_t type
    pthread_join(thrdID, NULL);

    return 0;
}
