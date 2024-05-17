#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int a = 10;
int b = 20;
int sum;
void *print_msg(void);
void *calculate(void *ptr);
int main()
{
	pthread_t thread1 , thread2;

	
	pthread_create(&thread1 , NULL , print_msg , NULL);
	pthread_create(&thread2 , NULL , calculate , NULL );
	//pthread_create(&thread2 , NULL , clculate , &b);

	pthread_join (thread1 , NULL);
	pthread_join (thread2 , NULL);
}

void *print_msg(void )
{
	printf("thread1 is running");
}
void *calculate(void *ptr)
{
 
	sum = a +b ;
	printf ("value of add is :%d\n" ,sum);

	
}

