#include<stdio.h>

int matrix[100][100];

void initilize(int vertices){
	
	for(int i=0;i<vertices;i++){
		for(int j=0;j<vertices;j++){
			matrix[i][j]=0;
		}
	}
}

int add_edge(int src,int dest){
	matrix[src][dest]=1;
	return 0;
}

void print_graph(int vertices){
	for(int i=0;i<vertices;i++){
		for(int j=0;j<vertices;j++){
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
}

	
	
int main(){

	int vertices=6;
	initilize(vertices);
	add_edge(0,1);
	add_edge(0,3);
	add_edge(0,5);
	add_edge(1,0);
	add_edge(1,2);
	add_edge(1,4);
	add_edge(2,1);
	add_edge(2,3);
	add_edge(2,5);
	add_edge(3,0);
	add_edge(3,2);
	add_edge(3,4);
	
	print_graph(vertices);
	
	
	return 0;
	
}


