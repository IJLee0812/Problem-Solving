#include <stdio.h>
int fact(int num){
	int res = 1;
	for (int i = 1 ; i <= num ; ++i){
		res *= i;
	}
	return res;
}
int main() {
    int n, k;
	scanf("%d %d", &n, &k);
	int quo = fact(n);
	int div = fact(k) * fact(n-k);
	int sol = quo / div;
	printf("%d", sol);
    return 0;
}