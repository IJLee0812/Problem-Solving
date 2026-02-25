#include <stdio.h>

int main(){

	int inp, n1, n10, n100, count = 99, tmp;

	scanf("%d", &inp); // 입력값

	if (inp <= 99){ 
		printf("%d\n", inp); 
	}
	
	else{ // output : 99 + alpha
		

		for (int i = 100 ; i <= inp ; i++){
			
			tmp = i;
			
			n1 = tmp % 10; tmp /= 10;

			n10 = tmp % 10; tmp /= 10;

			n100 = tmp % 10; 

			if (n10 - n1 == n100 - n10)
				count++;
		
		}
		if (inp == 1000)
			printf("%d\n", count - 1);
		else
			printf("%d\n", count);
		
	}

	return 0;
}