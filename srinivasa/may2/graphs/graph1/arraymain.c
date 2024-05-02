#include<stdio.h>
#include<time.h>
#include"array.h"
int main()
{
	clock_t start = clock();
	int numver = 4;
	startgraph(numver);
	addedge(0, 1);
	addedge(1, 2);
	addedge(2, 3);
	printgraph(numver);
	clock_t end = clock();
	float time = ((float)(end -start));
	printf("time taken:%f",time);
	return 0;
}

