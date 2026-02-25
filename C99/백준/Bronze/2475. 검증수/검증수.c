#include <stdio.h>
#include <math.h>

int main(){

	int n1, n2, n3, n4, n5, res = 0;
	scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);

	res += n1*n1+n2*n2+n3*n3+n4*n4+n5*n5;

	printf("%d", res % 10);

	return 0;
}