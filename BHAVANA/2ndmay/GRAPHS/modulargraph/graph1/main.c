#include "graph.h"
#include <stdio.h>
#include <time.h>

int main() {
  int numVertices = 4;
  clock_t start, end;
  double cpu_time_used;

  start = clock(); // Start the clock

  initializeGraph(numVertices);

  addEdge(0, 1); // Directed edge from 0 to 1
  addEdge(1, 2); // Directed edge from 1 to 2
  addEdge(2, 3); // Directed edge from 2 to 3

  printGraph(numVertices);

  end = clock(); // End the clock

  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Calculate CPU time used
  printf("CPU time used: %f seconds\n", cpu_time_used);

  return 0;
}
