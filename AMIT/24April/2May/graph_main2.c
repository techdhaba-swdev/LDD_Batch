#include<stdio.h>
#include<time.h>
#include"graph2.h"
#define MAX_VERTICES 100
 
int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int main()
{
  clock_t start = clock();

  int numVertices = 4;

  initializeGraph(numVertices);

  addEdge(0, 1); // Directed edge from 0 to 1

  addEdge(1, 2); // Directed edge from 1 to 2

  addEdge(2, 3); // Directed edge from 2 to 3

  printGraph(numVertices);
   clock_t end = clock();

    // Calculate the elapsed time

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
      printf("Time taken: %f seconds\n", time_taken);

  return 0;

}
