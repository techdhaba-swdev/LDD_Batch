#include"linkedlistgraph.h"

int main() {
   
   clock_t start=clock();
   int numVertices = 4;
   struct Graph* graph = createGraph(numVertices);
 
  addEdge(graph, 0, 1);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 2);
 
  printGraph(graph);
  clock_t end=clock();
  double time_taken=((double)(end-start));
  printf("time taken is %f\n",time_taken);
 
  return 0;
}

