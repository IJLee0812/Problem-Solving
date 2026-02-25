#include <stdio.h>
int main(){
	int n, grade; scanf("%d", &n);
	int x[n], y[n];
	for (int i = 0 ; i < n ; ++i)
		scanf("%d %d", &x[i], &y[i]);
	for (int i = 0 ; i < n ; ++i){
		grade = 0;
		for (int j = 0 ; j < n ; ++j){
			if (x[i] < x[j] && y[i] < y[j])
				grade++;
		}
			printf("%d ", grade+1);		
	}
	return 0;
}