#include <iostream>
#include <queue>
#define MAX_N 10
using namespace std;

int N, E;
int Graph[MAX_N][MAX_N];

void BFS(int node){
    bool visited[MAX_N] = { false };
    queue<int> myqueue;
    visited[node] = true; // 중요
    myqueue.push(node);

    while(!myqueue.empty()){
        int curr = myqueue.front();
        myqueue.pop();
        
        cout << curr << ' ';

        for (int i = 0 ; i < N ; i++){
            if (!visited[i] && Graph[curr][i]){ 
                visited[i] = true; // 중요ㄴ
                myqueue.push(i);
            }
        }

    }
}

int main(){

    cin >> N >> E;

    int u, v;
    for (int i = 0 ; i < E ; ++i){
        cin >> u >> v;
        Graph[u][v] = Graph[v][u] = 1;
    }
    BFS(0);
    return 0;
}