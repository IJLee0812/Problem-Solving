#include <stdio.h>
#include <stdbool.h>
int n,m;
int arr[10];
bool isused[10];
void f(int k){
	int tmp = 0;
	if (k == m){
		for (int i = 0 ; i < m ; ++i){
			if (tmp > arr[i])
				return;
			tmp = arr[i];
		}
		for (int i = 0 ; i < m ; ++i)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = 1 ; i <= n ; ++i){
		if (!isused[i]){
			arr[k] = i;
			isused[i] = 1;
			f(k+1);
			isused[i] = 0;
		}
	}
}
int main(){
	scanf("%d %d", &n, &m);
	f(0);
	return 0;
}