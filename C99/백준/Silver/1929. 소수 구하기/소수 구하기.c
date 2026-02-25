#include <stdio.h>
#include <stdbool.h>
int prime[1000000];
bool check[1000001];
int num_p = 0;
void eratos(int *prime, bool *check){
	for (int i = 2 ; i <= 1000000 ; ++i){
		if (check[i] == false){
			prime[num_p] = i;
			num_p++;
		}
		for (int j = i * 2 ; j <= 1000000 ; j += i){
			check[j] = true;
		}
	}
}
int main(){
	int m, n; scanf("%d %d", &m, &n);
	eratos(prime, check);
	for (int i = 0 ; i < num_p ; ++i)
		if (m <= prime[i] && prime[i] <= n)
			printf("%d\n", prime[i]);
	return 0;
}