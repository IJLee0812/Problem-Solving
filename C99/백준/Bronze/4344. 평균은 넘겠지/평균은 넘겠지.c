#include <stdio.h>

int main(){

	int test_case, num_s; int count;
	double score[1000], sum, avg;

	scanf("%d", &test_case); // 테스트 케이스의 개수

	for (int i = 0 ; i < test_case ; i++){

		scanf("%d", &num_s); // 테스트 케이스마다의 학생의 수
		sum = 0; avg = 0;
		for (int j = 0 ; j < num_s ; j++){
			
			scanf("%lf", &score[j]); // 각 학생들의 점수
			
			sum += score[j];
		}

		avg = sum / num_s;
		
		count = 0;

		for (int k = 0 ; k < num_s ; k++){
			if (avg < score[k]){
				count++; // count / num_s -> 비율
			}
		}

		printf("%.3lf%%\n", (double)count / num_s * 100);
	}

	return 0;
}