#include <stdio.h>
#include <stdlib.h>
#include "graph3.h"

int **adjMatrix; // Global variable for adjacency matrix

void initializeGraph(int numVertices) {
  adjMatrix = (int **)malloc(numVertices * sizeof(int *));
  if (adjMatrix == NULL) {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  
  for (int i = 0; i < numVertices; i++) {
    adjMatrix[i] = (int *)calloc(numVertices, sizeof(int));
    if (adjMatrix[i] == NULL) {
      printf("Memory allocation failed\n");
      exit(EXIT_FAILURE);
    }
  }
}

void addEdge(int src, int dest, int numVertices) {
  if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
    adjMatrix[src][dest] = 1; // Mark 1 to indicate an edge
  } else {
    printf("Invalid edge: (%d, %d)\n", src, dest);
  }
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

void freeGraph(int numVertices) {
  for (int i = 0; i < numVertices; i++) {
    free(adjMatrix[i]);
  }
  free(adjMatrix);
}

