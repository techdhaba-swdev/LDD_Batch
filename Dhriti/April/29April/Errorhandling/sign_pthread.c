#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

pthread_t thread1, thread2; 

void sigusr1_handler(int sigman) {

     	// printf(Received SIGUSR1 in thread %ld\n pthread_self()); pthread returns the thread id of the calling thread, identifies which thread handle the signal.
	
	const char msg[] = "Received SIGUSR1 in thread\n";
	write(STDOUT_FILENO, msg, sizeof(msg));
}


void* thread_func(void* arg) { // entry point of each thread
    signal(SIGUSR1, sigusr1_handler); //whenever sigusr1 signal is recevied by this thread sigusr1_handle func is invoked
    while(1) {
        printf("Program is running.. \n");
        sleep(1); //pauses the execution of the thread by 1 second
    }
    return NULL;
}

int main() {
    pthread_create(&thread1, NULL, thread_func, NULL);
    pthread_create(&thread2, NULL, thread_func, NULL);
    
    // Send SIGUSR1 to thread1
    pthread_kill(thread1, SIGUSR1);
    
    // Send SIGUSR1 to thread2
    pthread_kill(thread2, SIGUSR1);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}




