#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b){
	int n1 = *(int *)a;
	int n2 = *(int *)b;
	if (n1 < n2) return -1;
	if (n1 > n2) return 1;
	return 0;
}
int main(){
	int n, x; scanf("%d", &n);
	int arr[n];
	for (int i = 0 ; i < n ; ++i)
		scanf("%d", &arr[i]);
	qsort(arr, n, sizeof(int), compare);
	scanf("%d", &x);
	int left = 0, right = n-1, tmp, cnt = 0;
	while (left < right){
		tmp = arr[left] + arr[right];
		if (tmp == x)
			cnt++;
		if (tmp < x){
			left += 1;
			continue;
		}
		right-=1;
	}
	printf("%d", cnt);
	return 0;
}