#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *print_message(void *ptr);

int main(){

	pthread_t thread1,thread2;
	char *message1="thread1";
	char *message2="thread2";
	int t1,t2;
	t1=pthread_create(&thread1,NULL,print_message,message1);
	t2=pthread_create(&thread2,NULL,print_message,message2);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("thread1 is returns %d\n",t1);
	printf("thread2 is return %d\n",t2);
	exit(0);

}

void *print_message(void *ptr){

	char *message;
	message=(char*)ptr;
	printf("message is %s\n",message);

}
