#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define MAXINDEX 10

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}node_t;


void display(int* arr) {
	for (int i = 0; i < MAXINDEX; i++) {
		printf("%d ", arr[i]);
	}
}
void swap(int* arr, int index1, int index2) {
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}
void generate(int* arr) {
	for (int i = 0; i < MAXINDEX; i++) {
		arr[i] = rand() % MAXINDEX;
	}
}
void quickSort(int* arr, int start, int end) {
	int pivot = (start + end) / 2;
	int largeThanPivot = start;
	int smallThanPivot = end;

	if (start >= end) {
		return;
	}
 	while (largeThanPivot <= smallThanPivot) {
		while (largeThanPivot <= end && arr[largeThanPivot] <= arr[pivot]) {
  			largeThanPivot++;
		}
		//
		while (smallThanPivot > start && arr[smallThanPivot] >= arr[pivot]) {
			smallThanPivot--;
		}
		if (largeThanPivot > smallThanPivot) {
			swap(arr, pivot, smallThanPivot);
		}
		else{
			swap(arr, largeThanPivot, smallThanPivot);
		}
	}
	quickSort(arr, start, pivot - 1);
	quickSort(arr, pivot + 1, end);
}

node_t* insertNode(node_t* root, int data) {
	if (root == NULL) {
		root = (node_t*)malloc(sizeof(node_t));
		root->data = data;
		root->left = root->right = NULL;
		return root;
	}
	if (root->data < data) {
		root->right = insertNode(root->right, data);
	}
	else if (root->data > data) {
		root->left = insertNode(root->left, data);
	}
	return root;
}
void nodeDisplay(node_t* root) {
	node_t* dis = root;

	if (dis == NULL) {
		return;
	}
	nodeDisplay(dis->left);
	printf("%d ", dis->data);
	nodeDisplay(dis->right);

}
void heapSort(int* arr) {
	int child, parent;
	for (int i = 1; i < MAXINDEX; i++) {
		child = i;
		do {
			parent = (child-1)/2;
			if (arr[child] > arr[parent]) {
				swap(arr, child, parent);
			}
			child = parent;
		} while (child != 0);
	}

	for (int i = MAXINDEX - 1; i >= 0; i--) {
		swap(arr, 0, i);
		child = i;
		parent = 0;
		do {
			child = parent * 2 + 1;
			while(child < i-1 && arr[child] < arr[child+1]){
				child++;
			}
			if (child < i && arr[child] > arr[parent]) {
				swap(arr, child, parent);
			}
			parent = child;
		} while (child < i);
	}
}

int main() {
	int arr[MAXINDEX] = {5,3,2,1,6,4,8,9,7,10};
	/*node_t* root = (node_t*)malloc(sizeof(node_t));
	root = { NULL, };*/
	//srand(time(NULL));
	//int arr[MAXINDEX] = {5,3,2,1,6,4,8,9,7,10};
	//generate(arr);
	//quickSort(arr, 0, MAXINDEX - 1);
	//display(arr);
	/*for (int i = MAXINDEX; i > 0; i--) {
		root = insertNode(root, i);
	}
	nodeDisplay(root);*/
	heapSort(arr);
	display(arr);
}
