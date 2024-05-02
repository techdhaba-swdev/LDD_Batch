#include<stdio.h>
#include<stdlib.h>
#include"graph.h"
#include<time.h>
int main() {

       clock_t start = clock();

  int numVertices = 4;

  struct Graph* graph = createGraph(numVertices);

  addEdge(graph, 0, 1);

  addEdge(graph, 1, 2);

  addEdge(graph, 2, 3);

  printGraph(graph);





   clock_t end = clock();

    // Calculate the elapsed time

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
      printf("Time taken: %f seconds\n", time_taken);


  return 0;

}
