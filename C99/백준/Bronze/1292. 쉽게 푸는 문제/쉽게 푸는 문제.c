#include <stdio.h>
int main(){
	int n[1000], res = 0, sum = 1, ind = 0, s, e; scanf("%d %d", &s, &e);
	while (ind<=999){
		for (int j = 0 ; j < sum ; ++j){
				if (ind < 1000){
					n[ind] = sum;
					ind++;
				}
		}
		sum++;
	}
	for (int i = s-1 ; i < e ; ++i)
		res += n[i];
	printf("%d", res);
	return 0;
}