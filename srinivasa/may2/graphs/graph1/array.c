#include<stdio.h>
#include"array.h"
#define MAX 100
int adjmatrix[MAX][MAX];
void startgraph(int numver)
{
	for (int i = 0; i < numver; i++)
	{
		for(int j =0; j <numver; j++)
		{
			adjmatrix[i][j] = 0;
		}
	}
}
void addedge(int src , int dest)
{
	adjmatrix[src][dest] = 1;
}
void printgraph(int numver)
{
	for (int i = 0; i < numver; i++)
        {
                for(int j =0; j <numver; j++)
                {
                       printf("%d ", adjmatrix[i][j]);
                }
		printf("\n");
	}
}
