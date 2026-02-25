#include <stdio.h>
char a[3072][6144] = {0};
void star(int n, int x, int y){
	if (n == 3){
		a[x][y] = '*';
		a[x+1][y+1] = '*';
		a[x+1][y-1] = '*';
		a[x+2][y-2] = '*';
		a[x+2][y-1] = '*';
		a[x+2][y] = '*';
		a[x+2][y+1] = '*';
		a[x+2][y+2] = '*';
		return;
	}
	star(n/2, x, y); // 위
	star(n/2, x+n/2, y-n/2); //아래왼
	star(n/2, x+n/2, y+n/2); //아래오
}
int main(){
	int i,j,n; scanf("%d", &n);
	star(n, 0, n-1);

	for (i = 0 ; i < n ; ++i){
		for (j = 0 ; j < n*2 ; ++j){
			if (a[i][j] == '*')
				printf("%c", a[i][j]);
			else printf(" "); //공백문자
		}
		printf("\n");
	}
	return 0;
}