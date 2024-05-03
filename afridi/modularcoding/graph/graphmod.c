
#include <stdio.h>
#include <stdlib.h> // for malloc

// Function to create a new graph
Graph* createGraph(int numVertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    if (graph == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(EXIT_FAILURE);
    }
    graph->numVertices = numVertices;
    graph->adjMatrix = (int **)malloc(numVertices * sizeof(int *));
    if (graph->adjMatrix == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int *)malloc(numVertices * sizeof(int));
        if (graph->adjMatrix[i] == NULL) {
            printf("Memory allocation failed. Exiting...\n");
            exit(EXIT_FAILURE);
        }
    }
    initializeGraph(graph);
    return graph;
}

// Function to initialize the graph with no edges
void initializeGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

// Function to add a directed edge from src to dest
void addEdge(Graph *graph, int src, int dest) {
    if (src >= graph->numVertices || dest >= graph->numVertices || src < 0 || dest < 0) {
        printf("Invalid vertex indices. Exiting...\n");
        exit(EXIT_FAILURE);
    }
    graph->adjMatrix[src][dest] = 1;
}

// Function to print the adjacency matrix representation of the graph
void printGraph(Graph *graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to destroy the graph and free allocated memory
void destroyGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}
