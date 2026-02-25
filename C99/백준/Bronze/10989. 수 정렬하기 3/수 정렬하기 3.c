#include <stdio.h>
#define size 10001
int c[size];
int main(){
	int n,num;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++i){
		scanf("%d", &num);
		c[num]++;
	}

	for (int i = 0 ; i <= size ; ++i){
		if (c[i] == 0)
			continue;

		for (int j = 0 ; j < c[i] ; ++j)
			printf("%d\n",i);
	}
	return 0;
}