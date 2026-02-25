#include <stdio.h>

int main(){

	int n, b = 0; scanf("%d", &n);

	while (1){
		if (n % 5 == 0){
			b += n / 5;
			printf("%d\n", b); break;
		}

		n -= 3; b++;

		if (n < 0){
			printf("-1\n");
			break;
		}
	}

	return 0;
}