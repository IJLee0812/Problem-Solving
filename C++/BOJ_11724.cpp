#include <iostream>
using namespace std;
#define MAX 1001
int N, M, Graph[MAX][MAX];
bool visited[MAX] = {false};
int res = 0;
void DFS(int x){
    visited[x] = true;
    for (int i = 1 ; i <= N ; ++i){
        if (!visited[i] && Graph[x][i]){
            DFS(i);
        }
    }
}
int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> M;
    int x, y;
    for (int i = 0 ; i < M ; ++i){
        cin >> x >> y;
        Graph[x][y] = Graph[y][x] = 1;
    }
    int res = 0;
    for (int i = 1 ; i <= N ; ++i)
        if (!visited[i]){
            DFS(i);
            res++;
        }
    cout << res << '\n';
    return 0;
}