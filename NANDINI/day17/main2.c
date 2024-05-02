#include <stdio.h>
#include "graph2.h"

int main() {
    int numVertices = 4;

    initializeGraph(numVertices);

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);

    printGraph(numVertices);

    return 0;
}
