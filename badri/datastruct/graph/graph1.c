#include <stdio.h>//includes standard input and output functions like scanf and printf
#include "graph1.h"//includes graph1.h headerfile containing function declarations

#define MAX_VERTICES 100 // defines a macro for maximun number of vertices
int adjMatrix[MAX_VERTICES][MAX_VERTICES];//declare adjacency matrix globalvariable of [100][100] vertices

void initializeGraph(int numVertices) {//initialize the graph with no edges
    // Initialize the adjacency matrix with zeroes
    for (int i = 0; i < numVertices; i++) {//loops through the rows
        for (int j = 0; j < numVertices; j++) {//loops through columns
            adjMatrix[i][j] = 0;//set each cell to 0
        }
    }
}

void addEdge(int src, int dest) {//function for initialize source and destination
    // Mark 1 to indicate an edge from src to dest
    adjMatrix[src][dest] = 1;//set the value to 1 to represent adjacency
}

void printGraph(int numVertices) {//function to print the adjacencies
    // Print the adjacency matrix representation of the graph
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++) {//loops through rows
        for (int j = 0; j < numVertices; j++) {//loops through columns
            printf("%d ", adjMatrix[i][j]);//print ecah adjacency value
        }
        printf("\n");//print nextline
    }
}
