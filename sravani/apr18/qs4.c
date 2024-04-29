#include<stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>

// Signal handler function for SIGUSR1
void sigusr1_handler(int signum) {
	printf("Received SIGUSR1 signal in thread %lu\n", (unsigned long)pthread_self());
}

// Function executed by each thread
void *thread_func(void *arg) {
	// Install signal handler for SIGUSR1
	signal(SIGUSR1, sigusr1_handler);

	// Loop to simulate thread's activity
	printf("pid is %d\n",getpid());
	printf("generating signal for thread value is  %lu\n",(unsigned long)pthread_self());  
	while (1) {
    	// Do some work...
    	sleep(1); // Just for demonstration purposes
	}

	pthread_exit(NULL);
}

int main() {
	// Create multiple threads
	const int num_threads = 3;
	pthread_t threads[num_threads];
	for (int i = 0; i < num_threads; ++i) {
    	if (pthread_create(&threads[i], NULL, thread_func, NULL) != 0) {
        	perror("pthread_create");
        	exit(EXIT_FAILURE);
    	}
	}

	// Wait for all threads to finish
	for (int i = 0; i < num_threads; ++i) {
    	if (pthread_join(threads[i], NULL) != 0) {
        	perror("pthread_join");
        	exit(EXIT_FAILURE);
    	}
	}

	return 0;
}

