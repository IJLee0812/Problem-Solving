#include <stdio.h>

int main(){

	int apt[15][14], t, k, n, i;

	for (i = 0 ; i < 14 ; i++){ // 0층
		apt[0][i] = i+1;
	}

	for (i = 0 ; i < 15 ; i++){ // 각 층의 1호
		apt[i][0] = 1;
	}

	for (i = 1 ; i < 15 ; i++){
		for (int j = 1 ; j < 14 ; j++){
			apt[i][j] = apt[i-1][j] + apt[i][j-1];
		}
	}

	scanf("%d", &t); // test_case

	for (i = 0 ; i < t ; i++){

		scanf("%d", &k); scanf("%d", &n);

		printf("%d\n", apt[k][n-1]);
	}
	
	return 0;
}