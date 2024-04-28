#include <stdlib.h>
#include<pthread.h>

void *functionC();

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int counter = 0;

main()

int rc1, rc2;

pthread_t thread1, thread2;

/* Create independent threads each of which will execute functionC*/

if((rc1=pthread_create(&thread1, NULL, &functionC, HULL)))
{


printf("Thread creation failed: Ad\n", rcl);
}
if((rc2=pthread_create( &thread2, NULL, &functionC, MULL)))
{
printf("Thread creation failed: d\n", rc2);
}
/* Wait till threads are complete before main continues. Unless we wait we run the risk of executing an exit which will terminate / the process and all threads before the threads have completed*/.

pthread_join(thread1, HULL); pthread join( thread2, HULL);

exit(0);



void functionC()
{
counter++;

printf("Counter value: Ad\n", counter);
}
