#include"addedge.h"
#include"graph.h"

void addEdge(int src,int dest){
	adjMatrix[src][dest] = 1;//mark 1 to indicate an edge
}
