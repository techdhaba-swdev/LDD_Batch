#include "graph.h"
#include <stdio.h>

int main() {
    int numVertices = 4; // Number of vertices in the graph

    // Create a new graph
    Graph *graph = createGraph(numVertices);

    // Add directed edges to the graph
    addEdge(graph, 0, 1); // Directed edge from vertex 0 to vertex 1
    addEdge(graph, 1, 2); // Directed edge from vertex 1 to vertex 2
    addEdge(graph, 2, 3); // Directed edge from vertex 2 to vertex 3

    // Print the adjacency matrix representation of the graph
    printGraph(graph);

    // Destroy the graph and free allocated memory
    destroyGraph(graph);

    return 0;
}
