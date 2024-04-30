#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// Signal handler function
void sigusr1_handler(int signum) {
    printf("Thread %lu received SIGUSR1\n", (unsigned long)pthread_self());
}

// Thread function
void* thread_function(void* arg) {
    // Register the signal handler for SIGUSR1
    signal(SIGUSR1, sigusr1_handler);

    // Infinite loop to keep the thread alive
    while (1) {
        sleep(1);
    }

    return NULL;
}
int main() {
	pthread_t thread1,thread2;

	//create thread1
	if(pthread_create(&thread1,NULL,thread_function,NULL)!=0 ) {
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	//create thread2
	if(pthread_create(&thread2,NULL,thread_function,NULL)!=0) {
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}

	//wait for threads to finish (which they won't so this is an infinite loop)
//	pthread_join(thread1,NULL);
//	pthread_join(thread2,NULL);

	printf("PID of the program %d\n", getpid());
	
	while(1){
	sleep(1);
}
	exit(EXIT_SUCCESS);
}
