#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *functionC();
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
int counter =0;
main()
{
	int re1,re2;
	pthread_t thread1,thread2;

	if(( re1=pthread_create(&thread1,NULL,&functionC,NULL)) )
	{
		printf("Thread creation failed:%d\n",re1);
	}
	if( (re2=pthread_create(&thread2,NULL,&functionC,NULL)) )
	{
		printf("thread creation failed :%d\n",re2);
	}
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	exit(0);
}
void *functionC()
{
	counter++;
	printf("counter value:%d\n",counter);
}
