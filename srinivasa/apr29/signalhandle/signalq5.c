#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<signal.h>

void signal_handle(int signum)
{
	printf("thread recived");
}
void *thread_function(void *arg)
{
	printf("thread is running");
	signal(SIGUSR1, signal_handle);
	while(1)
		sleep(1);

}
int main()
{
	pthread_t t1,t2;
	pthread_create(&t1, NULL, thread_function, NULL);
	pthread_create(&t2, NULL, thread_function, NULL);
	pthread_kill(t1, SIGUSR1);
	pthread_kill(t2, SIGUSR1);
        pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
