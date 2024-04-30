#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<signal.h>
#include<unistd.h>
#define NUM_THREADS 3

void sigusr1_handler(int signum){
	write(STDOUT_FILENO, "Received SIGUSR1 signal. Custom message: Hello from thread!\n", 60);
}
void *thread_function(void *arg){
	signal(SIGUSR1, sigusr1_handler);
	printf("Thread ID: %ld started.\n",pthread_self());
	while(1){
		sleep(1);
	}
	return NULL;
}
int main(){
	pthread_t threads[NUM_THREADS];
	for(int i=0;i<NUM_THREADS;i++){
		if(pthread_create(&threads[i], NULL, thread_function, NULL) != 0){
			perror("pthread_create");
			exit(EXIT_FAILURE);
		}
	}
	for (int i=0;i<NUM_THREADS;i++){
		pthread_kill(threads[i], SIGUSR1);
	}
	for(int i=0;i<NUM_THREADS;i++){
		pthread_join(threads[i], NULL);
	}
	return 0;
}
