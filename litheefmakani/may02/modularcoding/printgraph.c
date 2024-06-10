#include"printgraph.h"
#include"graph.h"
void printGraph(int numVertices) {
printf("Adjacency Matrix:\n");

  for (int i = 0; i < numVertices; i++) {

    for (int j = 0; j < numVertices; j++) {

      printf("%d ", adjMatrix[i][j]);

    }

    printf("\n");

  }

}
