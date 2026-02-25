#include <stdio.h>
#include <stdlib.h>
int main(){

	char num1[4], num2[4], tmp;
	int n1, n2;
	scanf("%s %s", num1, num2);

	tmp = num1[0]; num1[0] = num1[2]; num1[2] = tmp;

	tmp = num2[0]; num2[0] = num2[2]; num2[2] = tmp;

	n1 = atoi(num1); n2 = atoi(num2);

	if (n1 < n2) printf("%d", n2);
	else printf("%d", n1);

	return 0;
}