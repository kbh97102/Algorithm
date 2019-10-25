#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct edge {
	int node[2];
	int distance;
}node;


//부모 노드를 찾는 함수
int getParent(int parent[], int node) {
	if (parent[node] == node) {
		return node;
	}
	return parent[node] = getParent(parent, parent[node]);
}


//두 부모 노드를 합치는 함수
int unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

//같은 부모를 가지는지 확인
bool findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) {
		return true;
	}
	return false;
}

void insertData(node* arr, int start, int end, int distance) {
	arr->node[0] = start;
	arr->node[1] = end;
	arr->distance = distance;
}

int kruskal(node *arr, int *parent) {
	int sum = 0;
	for (int i = 0; i < 11; i++) {
		if (!findParent(parent, arr[i].node[0] - 1, arr[i].node[1]-1)) {
			sum += arr[i].distance;
			unionParent(parent, arr[i].node[0] - 1, arr[i].node[1]-1);
		}
	}
	return sum;

}
void sort(node* arr){
	int num = 11;
	for (int i = 0; i < num; i++) {
		for (int j = i; j < num; j++) {
			if (arr[j].distance > arr[j + 1].distance) {
				node temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main() {
	int edgeNum = 11;
	int parent[7];
	int kruskalCost = 0;
	node* arr = (node*)malloc(sizeof(node) * edgeNum);
	insertData(&arr[0], 1, 7, 12);
	insertData(&arr[1], 1, 4, 28);
	insertData(&arr[2], 1, 2, 67);
	insertData(&arr[3], 1, 5, 17);
	insertData(&arr[4], 2, 4, 24);
	insertData(&arr[5], 2, 5, 62);
	insertData(&arr[6], 3, 5, 20);
	insertData(&arr[7], 3, 6, 37);
	insertData(&arr[8], 4, 7, 13);
	insertData(&arr[9], 5, 6, 45);
	insertData(&arr[10], 5, 7, 73);
	
	sort(arr);
	for (int i = 0; i < 7 ; i++) {
		parent[i] = i;
	}
	kruskalCost = kruskal(arr, parent);
	printf("%d", kruskalCost);
}
//https://www.youtube.com/watch?v=LQ3JHknGy8c&list=PLRx0vPvlEmdDHxCvAQS1_6XV4deOwfVrz&index=19