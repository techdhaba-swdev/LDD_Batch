#include <stdio.h>//includes standard input and output functions like printf and scanf
#include "graph1.h"//includes graph1.h header file which contains function declarations

int main() {
    int numVertices = 4;//giving the 4 number of vertices

    initializeGraph(numVertices);//calling graphinitialize function

    addEdge(0, 1); // Directed edge from 0 to 1
    addEdge(1, 2); // Directed edge from 1 to 2
    addEdge(2, 3); // Directed edge from 2 to 3

    printGraph(numVertices);//calling function printgraph to print vertices
    return 0;//returns successful complition of code
}
