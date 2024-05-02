#include "graph2.h"
#include <stdio.h>
#include <time.h>

int main() {
    int numVertices = 4;
    struct Graph* graph;
    clock_t start, end;
    double cpu_time_used;

    // Start the clock
    start = clock();

    // Create the graph and add edges
    graph = createGraph(numVertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    // Print the graph
    printGraph(graph);

    // End the clock
    end = clock();

    // Calculate CPU time used
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the CPU time used
    printf("CPU time used: %f seconds\n", cpu_time_used);

    return 0;
}
