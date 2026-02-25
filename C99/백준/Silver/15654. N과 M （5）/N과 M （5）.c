#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int n, m;
int arr[10], num[10];
bool isused[10];
void f(int k){
	if (k == m){
		for (int i = 0 ; i < m ; ++i)
			printf("%d ", arr[i]);
		printf("\n");
		return;	
	}
	for (int i = 1 ; i <= n ; ++i){
		if (!isused[i]){
			arr[k] = num[i-1];
			isused[i] = 1;
			f(k+1);
			isused[i] = 0;
		}
	}	
}
int compare(const void *a, const void *b){
	int A = *(int *)a;
	int B = *(int *)b;
	if (A < B) return -1;
	else if (A > B) return 1;
	return 0;	
}
int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0 ; i < n ; ++i) scanf("%d", &num[i]);
	qsort(num, n, sizeof(int), compare);
	f(0);
	return 0;
}