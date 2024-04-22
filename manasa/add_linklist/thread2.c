#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *functionC();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

void main()
{
	int rc1, rc2;
	pthread_t thread1, thread2;
	if( (rc1=pthread_create( &thread1, NULL, &functionC, NULL)) )
	{
		printf("thread creation failed: %d\n", rc1);
	}

	if( (rc2=pthread_create( &thread2, NULL, &functionC, NULL)) )
        {
                printf("thread creation failed: %d\n", rc2);
        }

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	exit(0);
}
void *functionC()
{
	counter++;
	printf("counter value: %d\n",counter);
}
