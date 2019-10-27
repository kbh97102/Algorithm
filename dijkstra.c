#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXNODE 7
#define INF 1000000000


typedef struct graphType {
	int num;
	int weight[MAXNODE][MAXNODE];
}graphType;

int distance[MAXNODE];
int visited[MAXNODE];

int minNode(graphType* g) {

	int min = INF;
	int minIndex = 0;

	for (int i = 0; i < g->num; i++) {
		if (!visited[i]) {
			if (distance[i] < min) {
				min = distance[i];
				minIndex = i;
			}
		}
	}
	return minIndex;
}


void findShortestPath(graphType* g, int start) {
	for (int i = 0; i < MAXNODE; i++) {
		distance[i] = g->weight[start][i];
		visited[i] = false;
	}
	distance[start] = 0;
	visited[start] = true;
	for (int i = 0; i < MAXNODE; i++) {
		int minIndex = minNode(g);
		visited[minIndex] = true;
		for (int j = 0; j < g->num; j++) {
			if (!visited[j]) {
				if (distance[j] + g->weight[j][minIndex] < distance[minIndex]) {
					distance[minIndex] = distance[j] + g->weight[j][minIndex];
				}
			}
		}
		
	}

}


int main() {
	graphType g = { 7,
   {{ 0, 29, INF, INF, INF, 10, INF },
   { 29,  0, 16, INF, INF, INF, 15 },
   { INF, 16, 0, 12, INF, INF, INF },
   { INF, INF, 12, 0, 22, INF, 18 },
   { INF, INF, INF, 22, 0, 27, 25 },
   { 10, INF, INF, INF, 27, 0, INF },
   { INF, 15, INF, 18, 25, INF, 0 } }
	};
	findShortestPath(&g, 0);

}