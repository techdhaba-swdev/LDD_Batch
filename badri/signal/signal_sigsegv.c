#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig)
{
	printf("segmentation fault\n");
	exit(EXIT_FAILURE);
}
int main()
{
	signal(SIGSEGV , handler);
	 int* ptr = NULL;
	 *ptr = 10;
	 return 0;
	}

