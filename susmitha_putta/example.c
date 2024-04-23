#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
 void*print_message_function(void*ptr);
int main()
{
	pthread_t thread1,thread2,thread3;

	char*message1 = "Thread1";
	char*message2="Thread2";
	char*message3="Thread3";

	int iret1,iret2,iret3;
	iret1=pthread_create(&thread1,NULL,print_message_function,(void*)message1);
	iret2=pthread_create(&thread2,NULL,print_message_function,(void*)message2);
	iret3=pthread_create(&thread3,NULL,print_message_function,(void*)message3);

	pthread_join(thread1,NULL);
	 pthread_join(thread2,NULL);
	 pthread_join(thread3,NULL);

	 printf("Thread 1 returns:%d\n",iret1);
	 printf("Thread 2 returns:%d\n",iret2);
	 printf("Thread 3 returns:%d\n",iret1);

	 exit(0);
}
void *print_message_function(void*ptr)
{
	char*message;
	message=(char*)ptr;
	printf("%s\n",message);
}




