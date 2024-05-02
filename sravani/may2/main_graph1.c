#include<stdio.h>
#include<stdlib.h>
#include "graph1.h"
int main() {
//create a graph with 4 vertices
  int numVertices = 4;

  struct Graph* graph = createGraph(numVertices);
  if(graph != NULL){
//Add edges to the graph
  addEdge(graph, 0, 1);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);

  printGraph(graph);
  free(graph);
  }
  else{
	  printf("failed to create ghraph\n");
  }

  return 0;

}

