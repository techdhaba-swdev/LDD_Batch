#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include<time.h>
void signal_handle( int signum)
{
	printf("\n ctrl+c pressed . exiting ...\n");
	exit(signum);
}
int main()
{

	clock_t start = clock();
	signal(SIGINT, signal_handle);
	while(1);
	return 0;
}
