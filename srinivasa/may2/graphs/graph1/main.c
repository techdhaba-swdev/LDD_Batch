#include<stdio.h>
#define MAX  100
int adjmatrix[MAX][MAX];
//FUNCTION to instialize the graph with no edges
void initializegraph(int numvertices)
{
	for (int i = 0; i < numvertices; i++)
	{
		for (int j = 0; i < numvertices; j++)
		{
			adjmatrix[i][j] = 0;
		}
	}
}
//function to add directed edge from src to dest 
void addedge(int src, int dest)
{
	adjmatrix[src][dest] = 1;
}
//function to print the adjacency matrix representation of the graph
void printgraph(int numvertices)
{
	printf("adjacency matrix :\n");
	for (int i = 0; i < numvertices; i++)
	{
		for (int j = 0; j < numvertices; j++)
		{
			printf("%d",adjmatrix[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int numvertices = 4;
	initializegraph(numvertices);
	addedge(0, 1);
	addedge(1, 2);
	addedge(2, 3);
	printgraph(numvertices);
	return 0;
}
