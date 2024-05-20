#include <stdio.h>
#include "createGraph.h"
#include "addEdge.h"
#include "printGraph.h"
#include <time.h>

int main() {
    int numVertices = 4;
    clock_t start = clock();
    struct Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printGraph(graph);

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
