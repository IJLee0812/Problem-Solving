#include <stdio.h>
#include <stdbool.h>
bool isused1[40]; 
bool isused2[40]; 
bool isused3[40]; 
int n, cnt = 0;
void f(int cur){
	if (cur == n){
		cnt++;
		return;
	} 
	for (int i = 0 ; i < n ; ++i){  
		if (isused1[i] || isused2[cur+i] || isused3[cur-i+n-1])
			continue;
		isused1[i] = 1;
		isused2[cur+i] = 1;
		isused3[cur-i+n-1] = 1;
		f(cur+1);
		isused1[i] = 0;
		isused2[cur+i] = 0;
		isused3[cur-i+n-1] = 0;
	}
}
int main(){	
	scanf("%d",&n);
	f(0);
	printf("%d\n", cnt);
	return 0;
}