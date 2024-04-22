#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *print_message_function(void *ptr);
void main(){
	pthread_t thread1, thread2;
	char *message1 = "Thread1";
       char *message2 = "Thread2";
       char *message3 = "Thread3";
       char *message4 = "Thread4";
       int iret1, iret2, iret3, iret4;
       iret1 = pthread_create(&thread1, NULL, print_message_function, (void*)message1);
       iret2 = pthread_create(&thread2, NULL,  print_message_function, (void*)message2);
       iret3 = pthread_create(&thread3, NULL,  print_message_function, (void*)message3);
       iret4 = pthread_create(&thread4, NULL,  print_message_function, (void*)message4);

       pthread_join( thread1, NULL);
       pthread_join(thread2, NULL);
       pthread_join(thread3, NULL);
       pthread_join(thread4, NULL);
       printf("Thread 1 returns: %d\n",iret1);
       printf("Thread2 returns: %d\n",iret2);
       printf("Thread3 returns: %d\n",iret3);
       printf("Thread4 returns: %d\n",iret4);
       exit(0);
}
void *print_message_function(void *ptr){
	char *message;
	message = (char*) ptr;
	printf("%s \n",message);
}
