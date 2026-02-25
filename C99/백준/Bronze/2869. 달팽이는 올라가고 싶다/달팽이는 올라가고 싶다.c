#include <stdio.h>

int main(){
	int a, b, v, res;
	scanf("%d %d %d", &a, &b, &v);
	res = (v-b)/(a-b); 
	if ((v-b)%(a-b) == 0)
		printf("%d\n", res);
	else
		printf("%d\n", res+1);
	return 0;
}