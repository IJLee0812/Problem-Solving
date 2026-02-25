#include <stdio.h>
	
int main(){

	int x; scanf("%d", &x);

	if (x == 1){ 
		printf("1/1\n"); 
		return 0;
	}	
		
	int sum = 2, ind = 3;
	while (1){
		for (int i = 1 ; i <= sum ; i++){ // 짝
			if (x == ind){ 
				printf("%d/%d\n", sum, i);
				return 0;
			}
			else if (x == ind-i){ 
				printf("%d/%d\n", sum-i, 1+i);
				return 0;
			}
		}
		sum++;
		ind += sum;
		
		for (int i = sum ; i >= 1 ; i--){ // 홀
			if (x == ind){
				printf("%d/%d\n", 1, sum);
				return 0;
			}
			else if (x == ind-i){
				printf("%d/%d\n", 1+i, sum-i);
				return 0;
			}
		}
		sum++;
		ind += sum;
	}

	return 0;
}