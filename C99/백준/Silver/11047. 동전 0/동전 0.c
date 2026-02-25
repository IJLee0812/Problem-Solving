#include <stdio.h>
int main(){
	int i, n, k, coin = 0; 
	scanf("%d %d", &n, &k);
	int money[n]; 
	for (i = 0 ; i < n ; ++i) 
		scanf("%d", &money[i]);
	i = n-1;
	while (k != 0){
		while ((k - money[i]) >= 0){
			coin++;
			k -= money[i];
		}
		i--;
	}
	printf("%d\n", coin);
	return 0;
}