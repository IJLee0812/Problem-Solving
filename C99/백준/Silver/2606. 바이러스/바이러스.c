#include <stdio.h>
#define MAX 101
int num, con, i, j, count = 0;
int DFS_V[MAX] = {0, }; // num : 전체 con : 연결v i, j : 두 개 입력
int graph[MAX][MAX] = {0, };

void dfs(int v, int num){
	int w;
	DFS_V[v] = 1;
	
	for (w = 1 ; w <= num ; w++){
		if (graph[v][w] == 1 && DFS_V[w] == 0){
			count++;
			dfs(w, num);
		}
	}
}
int main(void){

	//int edge;

	scanf("%d", &num); scanf("%d", &con);

	//edge = con - 1;
	
	while (con--){
		scanf("%d %d", &i, &j);
		graph[i][j] = 1;
		graph[j][i] = 1;
	}

	dfs(1, num);
	printf("%d", count);
	return 0;
}