#include <stdio.h>
#include <pthread.h>

void  *thread_function()
{
printf("thread created \n");
}

int main()
{
pthread_t threadid;
pthread_create(&threadid , NULL , thread_function , NULL);
pthread_join(threadid , NULL);
printf("thread main\n");
}

