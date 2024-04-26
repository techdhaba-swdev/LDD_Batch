#include <stdio.h>

#include <pthread.h>

void printMsg(char* msg) { printf("%s\n", msg);

}

int main(int argc, char** argv) {

pthread_t thrdID;
int tmp=thrdID;

printf("creating a new thread\n"); 
pthread_create(&thrdID, NULL, (void*)printMsg, argv[1]); 
printf("created thread %d\n", tmp);
//pthread_join(thrdID, NULL);

return 0;

}
