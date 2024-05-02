#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<pthread.h>
#define NUM_THREADS 3
//global variable to indicate whether the threads should continue running
volatile sig_atomic_t running = 1;
//thread function
void *thread_function(void *arg)
{
	int thread_id = *((int *)arg);
	while(running)
	{
		printf("thread %d is running\n",thread_id);
		sleep(1);
	}
	printf("thread %d exiting \n",thread_id);
	pthread_exit(NULL);
}
void signal_handler(int signum)
{
	printf("caught SIGINT. stopping threads..\n");
	running = 0;
}
int main()
{
	//register signal hanlder for SIGINT
	 signal(SIGINT, signal_handler);
    // Create threads
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }
    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }
    printf("All threads have finished\n");
    return 0;
}
