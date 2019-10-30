#include <stdio.h>
#include <stdlib.h>	
#include <stdbool.h>

#define MAXNODE 7
#define INF 1000000000

typedef struct graph {
	int vertexNum;
	int distance[MAXNODE][MAXNODE];
}graph;


bool visited[MAXNODE];
int distance[MAXNODE];
void display(graph* g) {
	for (int i = 0; i < MAXNODE; i++) {
		for (int j = 0; j < MAXNODE; j++) {
			printf("%d ", g->distance[i][j]);
		}
		printf("\n");
	}
}
int find_min_index(graph* g) {
	int gotchabitch;
	for (int i = 0; i < g->vertexNum; i++) {
		if (!visited[i]) {
			gotchabitch = i;
			break;
		}
	}
	for (int i = 0; i < g->vertexNum; i++) {
		if (!visited[i] && distance[gotchabitch] > distance[i]) {
			gotchabitch = i;
		}
	}
	return gotchabitch;
}
void prim(graph* g,int startNode) {
	

	for (int i = 0; i < g->vertexNum; i++) {
		distance[i] = INF;
	}
	distance[startNode] = 0;
	for (int i = 0; i < g->vertexNum; i++) {
		int minNodeIndex = find_min_index(g);
		visited[minNodeIndex] = true;
		if (distance[minNodeIndex] == INF) {
			return;
		}
		printf("gotchabitch %d \n", minNodeIndex);
		for (int j = 0; j < g->vertexNum; j++) {
			if (g->distance[minNodeIndex][j] != INF) {
				if (!visited[j] && g->distance[minNodeIndex][j] < distance[j]) {
					distance[j] = g->distance[minNodeIndex][j];
				}
			}

		}
			

	}
}

int main() {
	graph arr = { 7,
		{{ 0, 29, INF, INF, INF, 10, INF },
		{ 29,  0, 16, INF, INF, INF, 15 },
		{ INF, 16, 0, 12, INF, INF, INF },
		{ INF, INF, 12, 0, 22, INF, 18 },
		{ INF, INF, INF, 22, 0, 27, 25 },
		{ 10, INF, INF, INF, 27, 0, INF },
		{ INF, 15, INF, 18, 25, INF, 0 } }
	};
	for (int i = 0; i < MAXNODE; i++) {
		visited[i] = false;
	}
	
	prim(&arr, 0);
}