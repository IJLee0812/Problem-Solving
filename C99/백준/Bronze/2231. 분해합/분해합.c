#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main() {
	int N = 0;
	int n = 0, digit = 0;
	int temp = 0;
	int ans = 0;
	int decom = 0;

	scanf("%d", &N);
	
	n = N;

	while (1) {
		digit += 1;
		n = n / 10;

		if (n == 0)
			break;
	} //N의 자리수를 구하는 반복문

	for (int i = N - 9 * digit; i <= N; i++) {
		decom = i;
		temp = i;
		while (temp != 0) {
			decom += temp % 10;
			temp /= 10;
		} //조건 범위에 있는 수의 부분합을 구하는 반복문
		if (decom == N) {
			ans = i;
			break; // 가장 작은 생성자를 찾으면 반복문 종료
		}
	}

	printf("%d", ans);

	return 0;
}