#include<stdlib.h>
#include<stdio.h>

#include <pthread.h>

void *functionC();
pthread_mutex_t mutex1 =PTHREAD_MUTEX_INITIALIZER;
int counter = 0;
int main()
{
int rc1, rc2;

pthread_t thread1, thread2;



if ((rc1=pthread_create(&thread1, NULL, &functionC, NULL)))
{

printf("Thread creation failed: Ad\n", rc1);
}

if ((rc2=pthread_create(&thread2, NULL, &functionC, NULL)))
{
printf("Thread creation failed: d\n", rc2);
}



pthread_t join(thread1, NULL);
pthread_t join(thread2, NULL);
}
void *functionC(){

counter++;

printf("Counter value: Ad\n", counter);

}
	

