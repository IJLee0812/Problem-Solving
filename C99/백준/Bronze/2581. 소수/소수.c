#include <stdio.h>
#include <stdbool.h>
int prime[10000];
bool check[10001];
int num_p = 0, min, sum = 0;
void eratos(int *prime, bool *check){
	for (int i = 2 ; i <= 10000 ; ++i){
		if (check[i] == false){
			prime[num_p] = i;
			num_p++;
		}

		for (int j = i * i ; j <= 10000 ; j += i){
			check[j] = true;
		}
	}
}
int main(){
	int m, n;
	scanf("%d", &m); scanf("%d", &n);
	eratos(prime, check);
	for (int i = 0 ; i < num_p ; i++){
		if (sum == 0 && m <= prime[i]){
			min = prime[i];
		}
		if (m <= prime[i] && prime[i] <= n){
			sum += prime[i];
		}
	}
	if (sum == 0){
		printf("-1\n");
		return 0;
	}
	printf("%d\n%d\n", sum, min);
	return 0;
}