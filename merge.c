#include <stdio.h>

#define MAX 10

int sorted[MAX] = { 0, };

void merge(int* arr, int start, int mid, int end) {
	int right = start;
	int left = mid+1;
	int index = start;
	while (right <= mid && left <= end) {
		if (arr[right] <= arr[left]) {
			sorted[index++] = arr[right++];
		}
		else {
			sorted[index++] = arr[left++];
		}
	}
	if (right > mid) {
		for (int i = left; i <= end; i++) {
			sorted[index++] = arr[i];
		}
	}
	else {
		for (int i = right; i <= mid; i++) {
			sorted[index++] = arr[i];
		}
	}
	for (int i = start; i <= end; i++) {
		arr[i] = sorted[i];
	}
}

void partition(int* arr, int start, int end) {

	if (start < end) {
		int mid = (start + end) / 2;
		partition(arr, start, mid);
		partition(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

void display(int* arr) {
	for (int i = 0; i < MAX; i++) {
		printf("%d ", arr[i]);
	}
}
int main() {
	int arr[MAX] = { 5,3,1,2,4,6,8,7,9,10 };
	partition(arr, 0, 9);
	display(arr);
}