#include "array.h"
#include <stdio.h>

int adjMatrix[MAX_VERTICES][MAX_VERTICES];

void initializeGraph(int numVertices) {
  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      adjMatrix[i][j] = 0;
    }
  }
}

void addEdge(int src, int dest) {
  adjMatrix[src][dest] = 1;
}

void printGraph(int numVertices) {
  printf("Adjacency Matrix:\n");
  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      printf("%d ", adjMatrix[i][j]);
    }
    printf("\n");
  }
}
