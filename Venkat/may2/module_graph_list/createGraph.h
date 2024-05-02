#ifndef CREATE_GRAPH_H
#define CREATE_GRAPH_H

#include "node.h"

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Graph* createGraph(int numVertices);

#endif 
