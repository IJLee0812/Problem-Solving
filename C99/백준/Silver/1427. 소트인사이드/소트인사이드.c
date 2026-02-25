#include <stdio.h>

void sort(int ind, int *num){
	int tmp;
	for (int i = 0 ; i < ind - 1 ; ++i){
		for (int j = 0 ; j < ind - 1 - i ; ++j){
			if (num[j] < num[j+1]){
				tmp = num[j];
				num[j] = num[j+1];
				num[j+1] = tmp;
			}
		}
	}
	for (int i = 0 ; i < ind ; ++i) printf("%d", num[i]);
}

int main(){

	int num[10], n, ind = 0; scanf("%d", &n);
	
	while (n){

		num[ind] = n % 10;

		n /= 10; ind++;

	}
	
	sort(ind, num);
	
	return 0;
}