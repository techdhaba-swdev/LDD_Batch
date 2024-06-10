#include"intializegraph.h"
#include"graph.h"
 void initializeGraph(int numVertices){
	for(int i=0;i<numVertices;i++){
		for(int j=0;j<numVertices;j++){
			adjMatrix[i][j] = 0;
		}
	}
 }
