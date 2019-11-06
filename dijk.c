
#include "stdlib.h"
#include "graph.h"
#include "dijkstra.h"

int choose(int distances[], int n, int found[]){
    
    int minDistance = INF;
    int minpos = -1; //
    
	for (int i = 0; i < n; i++) {

		if (found[i] != FALSE) {
			continue;
		}
		if (distances[i] <= minDistance) {
			minpos = i;
			minDistance = distances[i];
		}
	}
    
    return minpos;
}
 
void    shortPathDijstra(GraphType *g, int start, int distances[], int pathTree[])
{
    int n= getVertices(g);
    int *found = (int *)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++){
        found[i] = FALSE;
        distances[i] = getWeight(g, start, i);
        pathTree[i] = start;
    }
    
    found[start] = TRUE;
    distances[start]= 0;
    for(int i=0;i<n-1;i++){ 
		int minIndex = choose(distances, n, found);
		found[minIndex] = TRUE;
  
		for (int j = 0; j < g->n; j++) {
			if (!found[j] && distances[j] > g->weights[minIndex*g->n + j] + distances[minIndex]) {
				distances[j] = g->weights[minIndex*g->n + j] + distances[minIndex];
				pathTree[j] = minIndex;
			}
		}
    }

    free((void*)found);
}

 
int getShortestPath(int start, int end, int pathTree[], int shortestPath[])
{
	int nodes = 0;
	int pathIndex = end;
	int tempArr[10000];
	int count = 0;
	while (pathIndex != start) { 
		tempArr[count] = pathIndex;
		pathIndex = pathTree[pathIndex];
		count++;
	}
	tempArr[count++] = start;
	for (int i = count-1; i >= 0; i--) {
		shortestPath[nodes++] = tempArr[i];
	}

	return nodes;
}