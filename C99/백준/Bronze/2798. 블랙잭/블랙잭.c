#include <stdio.h>

int main(){

	int n, m; scanf("%d %d", &n, &m);
	int card[n], res, tmp = 0;
	for (int i = 0 ; i < n ; i++) // 카드 값 저장
		scanf("%d", &card[i]);

	for (int i = 0 ; i < n ; ++i){
		for (int j = i+1 ; j < n ; ++j){
			for (int k = j+1 ; k < n ; ++k){
					res = card[i] + card[j] + card[k];
					if (tmp < res && res <= m)
						tmp = res;
			}
		}
	}

	printf("%d\n", tmp);

	return 0;
}