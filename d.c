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
int path[MAXNODE];
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
	int beforeIndex = start;
	int test[MAXNODE];
	int count = 0;
	for (int i = 0; i < MAXNODE-1; i++) {
		int minIndex = minNode(g);
		path[minIndex] = beforeIndex;
		visited[minIndex] = true;
		for (int j = 0; j < g->num; j++) {
			if (!visited[j]) {
				if (distance[minIndex] + g->weight[minIndex][j] < distance[j]) {
					distance[j] = distance[minIndex] + g->weight[minIndex][j];
					if (j == 6) {
						test[count++] = minIndex;
					}
				}
			}
		}
		beforeIndex = minIndex;
	}
	for (int i = 0; i < MAXNODE; i++) {
		printf("%d ", path[i]);
	}
	printf("\n");
	for (int i = 0; i < MAXNODE; i++) {
		printf("%d ", test[i]);
	}
	printf("\n");
	for (int i = 0; i < MAXNODE; i++) {
		printf("%d ", distance[i]);
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