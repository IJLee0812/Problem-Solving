#include <stdio.h>

int main(){

	int n, sum = 1, res = 1;

	scanf("%d", &n); // N

	if (n == 1){
		printf("%d\n", sum);
		return 0;
	}

	while (1){
		
		if (sum < n){
			sum += 6 * res; 
			res++;
		}
		else{
			printf("%d\n", res);
			break;
		}
	}

	return 0;
}