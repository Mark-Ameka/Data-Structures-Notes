#include <stdio.h>

// defining the number of vertices
#define num_v 4
// defining assumed infinity value
#define INF 999

void printMatrix(int matrix[][num_v]);

// Implementing floyd warshall algorithm
void floydWarshall(int graph[][num_v]){
	int matrix[num_v][num_v], i, j, k;

	for(i = 0; i < num_v; i++){
		for(j = 0; j < num_v; j++){
			matrix[i][j] = graph[i][j];
		}
	}

	// Adding vertices individually
	for(k = 0; k < num_v; k++){
		for(i = 0; i < num_v; i++){
			for(j = 0; j < num_v; j++){
				//Formula:
				/*	
					n = num1
					n2 = num2
					m = middle vertex
					
					D[n,n2] < D[n,m] + D[m,n2]
					
					E.G: D[2,3] < D[2,1] + D[1,3]
				*/
				if(matrix[i][k] + matrix[k][j] < matrix[i][j]){
					matrix[i][j] = matrix[i][k] + matrix[k][j];
				}
			}
		}
	}
	printMatrix(matrix);
}

void printMatrix(int matrix[][num_v]) {
	int i, j;
	for(i = 0; i < num_v; i++){
		for(j = 0; j < num_v; j++){
			if(matrix[i][j] == INF){
				printf("%4s", "INF");
			} else{
				printf("%4d", matrix[i][j]);
			}
		}
		printf("\n");
	}
}

int main() {
	int graph[num_v][num_v] = {{0, 3, INF, 5},
						 {2, 0, INF, 4},
						 {INF, 1, 0, INF},
						 {INF, INF, 2, 0}};
	floydWarshall(graph);
}
