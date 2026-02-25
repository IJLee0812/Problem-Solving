#include <stdio.h>
void find(int n){
	int cnt = 0;
	while(n){
		if (n % 2 == 1)
			printf("%d ", cnt);
		cnt++;
		n /= 2;
	}
}
int main(){
	int t,n; scanf("%d",&t);
	for (int i = 0 ; i < t ; ++i){
		scanf("%d", &n);
		find(n);
	}
	return 0;
}