#include <stdlib.h> 
#include<stdio.h>
#include <pthread.h>

void *functionC();

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int counter = 0;

void main()
{
	int rc1, rc2,rc3;

        pthread_t thread1, thread2,thread3;

       //Create Independent threads each of which will execute Function/
       if((rc1=pthread_create(&thread1, NULL, &functionC, NULL)))
       printf("Thread creation failed: %d\n", rc1);

       if((rc2=pthread_create(&thread2, NULL, &functionC, NULL)))
       printf("Thread creation failed: %d\n", rc2);
       
       if((rc3=pthread_create(&thread3, NULL, &functionC, NULL)))
       printf("Thread creation failed: %d\n", rc3);


       pthread_join( thread1, NULL);
       pthread_join( thread2, NULL);
       pthread_join( thread3, NULL);

       exit(0);

}
void *functionC()
{
	counter++;
        printf("Counter value: %d\n", counter);
}
