#include <stdio.h>

int check(int num){ // 일반적인 소수찾기 알고리즘

	if (num == 1) // 1은 소수가 아님
		return 0;
	
	
	for (int d = 2 ; d < num ; d++){
		if (num % d == 0){
			return 0;
		}
	}

	return 1;

}

int main(){

	int test_case, num, res = 0;

	scanf("%d", &test_case);

	for (int i = 0 ; i < test_case ; i++){

		scanf("%d", &num);

		res += check(num);

	}

	printf("%d\n", res);
	
	return 0;
}