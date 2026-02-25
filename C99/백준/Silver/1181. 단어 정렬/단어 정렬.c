#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char word[51];
	int len;
}words;
words sorted[20001];
void merge(words* arr, int left, int mid, int right){
	int i = left, j = mid+1, k = left;
	while (i <= mid && j <= right){
		if (arr[i].len > arr[j].len)
			sorted[k++] = arr[j++];
		else if (arr[i].len < arr[j].len)
			sorted[k++] = arr[i++];
		else{
			if (strcmp(arr[i].word, arr[j].word) < 0)
				sorted[k++] = arr[i++];
			else
				sorted[k++] = arr[j++];
		}
	}
	if (i <= mid){
		while (i <= mid)
			sorted[k++] = arr[i++];
	}
	else{
		while (j <= right)
			sorted[k++] = arr[j++];
	}
	for (k = left ; k <= right ; ++k)
		arr[k] = sorted[k];
}
void mergesort(words* arr, int left, int right){
	int mid;
	if (left < right){
		mid = (left + right) / 2;
		mergesort(arr, left, mid);
		mergesort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
}
int main(){
	int i,n; scanf("%d", &n);
	words arr[n];
	for (i = 0 ; i < n ; ++i){
		scanf("%s", arr[i].word);
		arr[i].len = strlen(arr[i].word);
	}
	mergesort(arr, 0, n-1);
	printf("%s\n", arr[0].word);
	for (i = 1 ; i < n ; ++i)
		if (strcmp(arr[i-1].word, arr[i].word) != 0)
			printf("%s\n", arr[i].word);
	return 0;
}