#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *function();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter =0;

int main()
{
	int rc1, rc2;
	pthread_t thread1, thread2;

	if((rc1=pthread_create( &thread1, NULL, &function, NULL)))
	{
	  printf("Thread creation failed %d\n", rc1);
	}
	 if((rc2=pthread_create(&thread2, NULL, &function, NULL)))
        {
          printf("Thread creation failed %d\n", rc2);
	}

	
	 pthread_join(thread1, NULL);
         pthread_join(thread2, NULL);

	 exit(0);
}

void *function()
{
  counter++;
  printf("Counter value %d\n",counter);


}
