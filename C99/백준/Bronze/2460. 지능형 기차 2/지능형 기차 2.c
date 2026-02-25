#include<stdio.h>

int main(){

	int person[11] = {0},max = 0;
	int a, b; // a : ㄴㄹ b : ㅌ
	for (int i = 1 ; i < 11 ; ++i){
		scanf("%d %d", &a, &b);
		person[i] = person[i-1] + b - a;
	}
	for (int i = 0 ; i < 10 ; ++i){
		if (max < person[i])
			max = person[i];
	}
	
	printf("%d",max);

	return 0;
}