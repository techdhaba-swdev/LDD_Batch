#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *functionC();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

int main()
{
	int rc1, rc2;
	pthread_t thread1, thread2;
	/* create independent threads each of which will excute functionC */

	if( (rc1=pthread_create( &thread1,NULL,&functionC, NULL)) )
	{
		printf("thread creation failed:%d\n", rc1);
	}

	if( (rc2=pthread_create( &thread2,NULL,&functionC, NULL)) )
        {
                printf("thread creation failed:%d\n", rc2);
        }

	/* wait till the threads are complete before main continues unless */
	/* wait we run the risk of excuting an exit which all terminate */
	/* the process and all thread before the threads are completed */

	pthread_join( thread1,NULL);
	pthread_join( thread2,NULL);

	exit(0);
}
void *functionC()
{
	counter++;
	printf("counter the value :%d\n",counter);
}



