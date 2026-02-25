#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int x;
	int y;
}point;
point sorted[100001];
void merge(point* arr, int left, int mid, int right){

	int i, j, k; i = left; j = mid + 1; k = left;

	while (i <= mid && j <= right){
		if (arr[i].x > arr[j].x) 
			sorted[k++] = arr[j++];
		else if (arr[i].x < arr[j].x)
			sorted[k++] = arr[i++];
		else{
			if (arr[i].y > arr[j].y)
				sorted[k++] = arr[j++];
			else if (arr[i].y < arr[j].y)
				sorted[k++] = arr[i++];
		}
	}

	if (i <= mid){
		while (i <= mid){
			sorted[k++] = arr[i++];
		}
	}
	else{
		while (j <= right){
			sorted[k++] = arr[j++];
		}
	}

	for (k = left ; k <= right ; ++k)
		arr[k] = sorted[k];

}

void mergesort(point* arr, int left, int right){
	int mid;
	if (left < right){
		mid = (left+right) / 2;
		mergesort(arr, left, mid);
		mergesort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
}


int main(){

	int n; scanf("%d", &n);

	point* arr = (point *)malloc(sizeof(point) * n);

	for (int i = 0 ; i < n ; ++i)
		scanf("%d %d", &arr[i].x, &arr[i].y);

	mergesort(arr, 0, n-1);

	for (int i = 0 ; i < n ; ++i)
		printf("%d %d\n", arr[i].x, arr[i].y);

	return 0;
}