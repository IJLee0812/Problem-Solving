#include <stdio.h>
long long mod(long long a, long long b, long long c){
	if (b == 1) return a % c;
	long long val = mod(a, b/2, c);
	val = val * val % c;
	if (b % 2 == 0) return val;
	return val * a % c;
}
int main(){
	long long a, b, c; scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld", mod(a, b, c));
	return 0;
}