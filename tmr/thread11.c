#include<stdio.h>
#include<pthread.h>


void* print_1(void* arg)
{
	for (int i=2; i<=20; i=i+2)
	{
		printf("%d\n", i);
	}

	pthread_exit(NULL);
}


void* print_2(void*arg)
{
	for (int i=1; i<=19; i=i+2)
	{
		printf("%d\n", i);
	}
	pthread_exit(NULL);
}
int main()
{
	pthread_t  even_thread ,odd_thread;

	pthread_create(&even_thread,NULL, print_1,NULL);
	pthread_create(&odd_thread,NULL, print_2,NULL);
	pthread_join(even_thread,NULL);
	pthread_join(odd_thread,NULL);
	return 0;
}
