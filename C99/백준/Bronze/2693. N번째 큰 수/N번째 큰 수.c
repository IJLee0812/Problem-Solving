#include <stdio.h>
void snp(int *n){
	int tmp;
	for (int i = 0 ; i < 10 ; ++i){
		for (int j = 0 ; j < 10 - i - 1 ; ++j){
			if (n[j] < n[j+1]){
				tmp = n[j];
				n[j] = n[j+1];
				n[j+1] = tmp;
			}
		}
	}
	printf("%d\n", n[2]);
}
int main(){
	int t; scanf("%d", &t);
	int n[10];
	for (int i = 0 ; i < t ; ++i){
		for (int j = 0 ; j < 10 ; ++j)
			scanf("%d", &n[j]);
		snp(n);
	}
	return 0;
}