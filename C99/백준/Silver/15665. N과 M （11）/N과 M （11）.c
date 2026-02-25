#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int n, N = 0, m;
int arr[10], num[10];
bool isused[10];
int nused[10000];
void f(int k){
	if (k == m){
		for (int i = 0 ; i < m ; ++i)
			printf("%d ", arr[i]);
		printf("\n");
		return;	
	}
	int prev = -1; 
	for (int i = 1 ; i <= N ; ++i){
		if (prev != num[i-1]){
			arr[k] = num[i-1];
			isused[i] = 1;
			prev = num[i-1];
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
	for (int i = 0 ; i < 10 ; ++i)
		num[i] = 10001;
	for (int i = 0 ; i < n ; ++i){
		scanf("%d", &num[i]);
		nused[num[i]-1]++;
	}	
	for (int i = 0 ; i < 10 ; ++i)
		if (num[i] != 10001)
			N++;
	qsort(num, n, sizeof(int), compare);
	f(0);
	return 0;
}