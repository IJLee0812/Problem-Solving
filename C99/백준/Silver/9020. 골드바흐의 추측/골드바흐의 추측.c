#include <stdio.h>
int main(){
	int i, j, n, t, not_prime[10001] = {1, 1, 0};
	for (i = 2 ; i * i < 10001 ; ++i)
		if (!not_prime[i])
			for (j = i * i ; j < 10001 ; j += i)
				not_prime[j] = 1;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (j = n / 2 ; j >= 2 ; --j){
			if (!not_prime[j] && !not_prime[n-j]){
				printf("%d %d\n", j, n-j);
				break;
			}
		}
	}
	return 0;
}