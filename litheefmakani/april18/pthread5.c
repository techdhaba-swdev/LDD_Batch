#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define NTHREADS 40
void *thread_function(void *);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter=0;
main(){
	pthread_t thread_id[NTHREADS];
	int i,j;
	for(i=0;i<NTHREADS;i++){
		pthread_create(&thread_id[i],NULL,thread_function,NULL);
	}
	for(j=0;j<NTHREADS;j++){
		pthread_join(thread_id[j],NULL);
	}
	//Now all threads are complete i can print the final result.
	//without the join i could be printing a valure before all the threads
	//have been completed.
	printf("Final counter value: %d\n",counter);
}
void *thread_function(void *dummyptr){
	printf("Thread number %ld\n",pthread_self());
	counter++;
	printf("counter value is : %d\n",counter);
}
