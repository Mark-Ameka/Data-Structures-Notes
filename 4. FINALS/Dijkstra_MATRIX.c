#include <stdio.h>
#define INF 9999
#define MAX 7

typedef int Graph[MAX][MAX];

void Dijikstra(Graph G, int start_indx){
	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, min_d, nextnode, i,j;
	
	// Creating cost matrix
	for(i = 0; i < MAX; i++){
		for(j = 0; j < MAX; j++){
			if(G[i][j] == 0){
				cost[i][j] = INF;
			} else{
				cost[i][j] = G[i][j];
			}
		}
	}

	for(i = 0; i < MAX;i++){
		distance[i] = cost[start_indx][i];
		pred[i] = start_indx;
		visited[i] = 0;
	}
	
	distance[start_indx] = 0;
	visited[start_indx] = 1;
	count = 1;
	
	while(count < MAX-1){
		min_d = INF;
		for(i = 0; i < MAX; i++){
			if(distance[i] < min_d && !visited[i]){
				min_d = distance[i];
				nextnode = i;
			}
		}
		visited[nextnode] = 1;
		
		/*
			Formula:
			d = distance		u = unvisited
			c = cost			v = visited
			
			if(d(u) + c(u,v)) < d(v)){
   				d(v) = d(u) + c(u,v)
			}
		*/
		for(i = 0; i < MAX; i++){
			if(!visited[i]){
				if((min_d + cost[nextnode][i]) < distance[i]){
					distance[i] = min_d+cost[nextnode][i];
					pred[i] = nextnode;
				}
			}
		}
		count++;
	}
	
	for(i = 0; i < MAX; i++){
		printf("%d ", distance[i]);
	}
}

int main(){
	Graph G = {
	        {INF, 4,   2,   INF, 1,	  INF,   4},
	        {4,   INF, 5,   INF, 3,   INF,   4},
	        {2,   INF, INF, INF, INF, 6,   INF},
	        {INF, 5,   2,   INF, 6,   1,   INF},
	        {2,   3,   INF, 3,   INF, 1,     2},
	        {INF, INF, 4,   4,   INF, INF, INF}};
	
	Dijikstra(G, 4);
	
	return 0;
}
