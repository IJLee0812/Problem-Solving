#include <stdio.h>
#include <string.h>
void f(char *num){
	char *front = &num[0], *rear = &num[strlen(num)-1];
	for (int i = 0 ; i < strlen(num) / 2 ; ++i){
		if (*front != *rear){
			printf("no\n"); 
			return;
			}
		front++; rear--;
	}
	printf("yes\n"); return;
}
int main(){
	char num[5]; 
	while (1){
		scanf("%s", num); getchar();
		if (num[0] == '0') return 0;
		f(num);	
	}
}