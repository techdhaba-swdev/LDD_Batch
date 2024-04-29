#include<stdio.h>
#include<pthread.h>
#include<signal.h>
#include<stdlib.h>

//we have to create a pthread 

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
int flag=0;
//we are declare a function
void *thread_function(void *arg){
	pthread_mutex_lock(&mutex);
	while(flag==0){
		pthread_cond_wait(&condition,&mutex);
	}
	printf("THread received signal\n");
	pthread_mutex_unlock(&mutex);
        pthread_exit(NULL);
}
int main(){
	pthread_t thread;
	//create a threa
	pthread_create(&thread,NULL,thread_function,NULL);
	//signal thread
	pthread_mutex_lock(&mutex);
	flag ==1;
	pthread_cond_signal(&condition);
	pthread_mutex_unlock(&mutex);

	//wait for pthread to finish
	pthread_join(thread, NULL);
	return 0;
}
