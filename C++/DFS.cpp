#include <iostream>
#include <stack>
#define MAX_N 10
using namespace std;
int N, E;
int Graph[MAX_N][MAX_N];
void DFS(int node){
	bool visited[MAX_N] = { false };
	stack<int> mystack;
	mystack.push(node);
	while(!mystack.empty()){
		int curr = mystack.top();
		mystack.pop();
		if (visited[curr]) continue;
		cout << curr << ' ';
		visited[curr] = true;
		for (int next = 0 ; next < N ; next++) // next < N
			if (!visited[next] && Graph[curr][next]) mystack.push(next);	
	}
}
int main(){
	cin >> N >> E;
	int u, v;
	for (int i = 0 ; i < E ; i++){
		cin >> u >> v;
		Graph[u][v] = Graph[v][u] = 1;
	}
	DFS(0);
	return 0;
}
